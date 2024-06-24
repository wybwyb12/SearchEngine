#ifndef __CONDITION_H__
#define __CONDITION_H__

#include <pthread.h>
#include "NonCopyable.h"

namespace SearchEngine
{
class MutexLock;

class Condition
: NonCopyable
{
public:
    Condition(MutexLock &mutex);
    ~Condition();
    void wait();
    void notify();
    void notifyAll();

private:
    MutexLock &_mutex;
    pthread_cond_t _cond;
};

}

#endif

