#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include <queue>
#include "MutexLock.h"
#include "Condition.h"
#include <functional>

using std::queue;
using std::function;

namespace SearchEngine
{

using ElemType = function<void()>;

class TaskQueue
{
public:
    TaskQueue(size_t queSize);
    ~TaskQueue();
    bool empty() const;
    bool full() const;
    void push(ElemType &&value);
    ElemType pop();

    //唤醒所有等待在_not_Empty条件变量上面的线程
    void wakeup();

private:
    size_t _queSize;
    queue<ElemType> _que;
    MutexLock _mutex;//子对象
    Condition _notEmpty;
    Condition _notFull;
    bool _flag;
};

}

#endif
