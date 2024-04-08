#include <myTerm.h>

int
mt_delline (void)
{
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, "\E[2K", 4);
  close (fd);
  return (result == 4) ? 0 : -1;
}
