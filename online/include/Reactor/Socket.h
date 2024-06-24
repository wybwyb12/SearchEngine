#ifndef _SOCKET__H_
#define _SOCKET__H_

#include "NonCopyable.h"

namespace SearchEngine
{
class Socket
: NonCopyable
{
public:
    Socket();
    explicit Socket(int fd);
    ~Socket();
    int fd() const;
    void shutDownWrite();

private:
    int _fd;
};

}
#endif
