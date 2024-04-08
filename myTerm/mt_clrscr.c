#include <myTerm.h>

int
mt_clrscr (void)
{
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, "\E[H\E[2J", 8);
  close (fd);
  return (result == 8) ? 0 : -1;
}