#include "../../include/Reactor/Condition.h"
#include "../../include/Reactor/MutexLock.h"
#include <stdio.h>

namespace SearchEngine
{

Condition::Condition(MutexLock &mutex)
: _mutex(mutex)
{
   int ret =  pthread_cond_init(&_cond, nullptr);
   if(ret)
   {
       perror("pthread_cond_init");
   }
}

Condition::~Condition()
{
   int ret =  pthread_cond_destroy(&_cond);
   if(ret)
   {
       perror("pthread_cond_destroy");
   }
}

void Condition::wait()
{
   int ret =  pthread_cond_wait(&_cond, _mutex.getMutexLockPtr());
   if(ret)
   {
       perror("pthread_cond_wait");
   }
}

void Condition::notify()
{
   int ret =  pthread_cond_signal(&_cond);
   if(ret)
   {
       perror("pthread_cond_signal");
   }
}

void Condition::notifyAll()
{
   int ret =  pthread_cond_broadcast(&_cond);
   if(ret)
   {
       perror("pthread_cond_broadcast");
   }
}

}
