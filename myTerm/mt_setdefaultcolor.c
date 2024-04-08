#include <myTerm.h>

int
mt_setdefaultcolor (void)
{
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, "\E[49;m\E[39;m", 12);
  close (fd);
  return (result == 12) ? 0 : -1;
}