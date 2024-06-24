#include "../../include/Reactor/Thread.h"
#include <iostream>

using std::cerr;

namespace SearchEngine{

Thread::Thread(ThreadCallback &&cb)
: _thid(0)
, _isRunning(false)
, _cb(std::move(cb))//注册回调函数
{
}

Thread::~Thread()
{
    if(_isRunning)
    {
        //让子线程和主线程分离，主线程不管子线程的回收
        pthread_detach(_thid);
        _isRunning = false;
    }
}

//线程启动函数
void Thread::start()
{
    int ret = pthread_create(&_thid, nullptr, threadFunc, this);
    if(ret)
    {
        perror("pthread_create\n");
        return;
    }

    _isRunning = true;
}

void Thread::join()
{
    if(_isRunning)
    {
        int ret = pthread_join(_thid, nullptr);
        if(ret)
        {
            perror("pthread_join\n");
            return;
        }

        _isRunning = false;
    }
}

//静态成员函数
void *Thread::threadFunc(void *arg)
{
    Thread *pth = static_cast<Thread *>(arg);
    if(pth)
    {
        pth->_cb();//执行回调函数
    }

    //让子线程主动退出
    pthread_exit(nullptr);
}


}
