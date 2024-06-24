#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
#include <functional>

namespace SearchEngine{
using std::function;

class Thread
{
    using ThreadCallback = function<void()>;

public:
    Thread(ThreadCallback &&cb);
    ~Thread();

    //线程的开始与结束
    void start();
    void join();

private:
    //线程入口函数, 由于成员函数this指针的影响，必须设定成静态的
    static void *threadFunc(void *arg);
    //线程的执行任务
    //virtual void run() = 0;

private:
    pthread_t _thid;//线程id
    bool _isRunning;//线程运行的标志
    ThreadCallback _cb;//封装的任务
};


} //end namespace

#endif

