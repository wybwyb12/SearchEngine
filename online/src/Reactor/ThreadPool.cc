#include "../../include/Reactor/ThreadPool.h"
#include "../../include/Reactor/Thread.h"
#include <unistd.h>

namespace SearchEngine
{

ThreadPool::ThreadPool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _queSize(queSize)
, _taskQue(_queSize)
, _isExit(false)
{
    //为了防止vector频繁扩容，所以可以提前预留空间
    _threads.reserve(_threadNum);
}

ThreadPool::~ThreadPool()
{
    //如果线程池退出的标志位为1，就说明线程池中
    //的工作线程已经退出来了，此时可以什么都不做
    //但是如果线程池的标志位为0，就说明子线程还
    //没有完全退出
    if(!_isExit)
    {
        stop();
    }
}

void ThreadPool::start()
{
    //将所有的工作线程都存放到vector中
    for(size_t idx = 0; idx != _threadNum; ++idx)
    {
        unique_ptr<Thread> up(new Thread(bind(&ThreadPool::threadFunc, this)));
        _threads.push_back(std::move(up));
    }
    for(auto &th : _threads)
    {
        th->start();
    }
}

void ThreadPool::stop()
{
    while(!_taskQue.empty())
    {
        sleep(1);
    }

    _isExit = true;
    _taskQue.wakeup();

    for(auto &th : _threads)
    {
        th->join();
    }
}

void ThreadPool::addTask(Task &&taskcb)
{
    if(taskcb)
    {
        _taskQue.push(std::move(taskcb));
    }
}

Task ThreadPool::getTask()
{
    return _taskQue.pop();
}

void ThreadPool::threadFunc()
{
    while(!_isExit)
    {
        Task taskcb = getTask();
        if(taskcb)
        {
            taskcb();//回调函数的执行
        }
    }
}

}

