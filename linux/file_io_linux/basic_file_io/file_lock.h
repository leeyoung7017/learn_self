#ifndef FILE_LOCK_H
#define FILE_LOCK_H

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int file_lock(int fd,short type);



#endif
