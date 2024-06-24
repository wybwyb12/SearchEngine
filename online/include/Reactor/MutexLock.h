#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include <pthread.h>
#include "NonCopyable.h"

namespace SearchEngine
{

class MutexLock
: NonCopyable
{
public:
    MutexLock();
    ~MutexLock();
    void lock();
    void unlock();
    void trylock();

    pthread_mutex_t *getMutexLockPtr()
    {
        return &_mutex;
    }

private:
    pthread_mutex_t _mutex;
};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock &mutex)
    : _mutex(mutex)
    {
        _mutex.lock();
    }
    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

private:
    MutexLock &_mutex;
};


}

#endif

