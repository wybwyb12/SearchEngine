#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include <vector>
#include <memory>
#include "TaskQueue.h"
#include <functional>

using std::vector;
using std::unique_ptr;
using std::bind;
using std::function;

namespace SearchEngine
{

class Thread;

using Task = function<void()>;

class ThreadPool
{
public:
    ThreadPool(size_t threadNum, size_t queSize);
    ~ThreadPool();

    void start();
    void stop();

    void addTask(Task &&ptaskcb);

private:
    Task getTask();

    //线程池交给工作线程做的所有逻辑全部封装在这里
    //线程池交给工作线程做的任务
    void threadFunc();

private:
    size_t _threadNum;
    size_t _queSize;
    vector<unique_ptr<Thread>> _threads;//存放工作线程的容器
    TaskQueue _taskQue;//任务队列子对象，存放任务
    bool _isExit;//标识线程池退出的标志
};

}
#endif

