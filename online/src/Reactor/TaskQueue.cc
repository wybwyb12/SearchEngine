#include "../../include/Reactor/TaskQueue.h"

namespace SearchEngine
{

TaskQueue::TaskQueue(size_t queSize)
: _queSize(queSize)
, _que()
, _mutex()
, _notEmpty(_mutex)
, _notFull(_mutex)
, _flag(true)
{

}

TaskQueue::~TaskQueue()
{
    
}

bool TaskQueue::empty() const
{
    return 0 == _que.size();
}

bool TaskQueue::full() const
{
    return _que.size() == _queSize;
}

void TaskQueue::push(ElemType &&value)
{
    //这里利用RALL的思想，利用栈对象的生命周期管理资源
    MutexLockGuard autoLock(_mutex);
    while(full())
    {
        _notFull.wait();//等待在条件变量上
    }

    _que.push(std::move(value));
    
    _notEmpty.notify();

}

ElemType TaskQueue::pop()
{
    MutexLockGuard autoLock(_mutex);
    while(_flag && empty())
    {
        _notEmpty.wait();
    }
    
    if(_flag)
    {
        ElemType tmp = _que.front();
        _que.pop();

        _notFull.notify();
        return tmp;
    }
    else
    {
        return nullptr;
    }
}

void TaskQueue::wakeup()
{
    _flag = false;
    _notEmpty.notifyAll();
}

}
