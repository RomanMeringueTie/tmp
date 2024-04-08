#include <myTerm.h>

int
mt_gotoXY (int x, int y)
{
  char *str = malloc (20);
  sprintf (str, "\033[%d;%dH", x, y);
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, str, strlen (str));
  size_t len = strlen (str);
  close (fd);
  free (str);
  fflush (stdout);
  return (result == len) ? 0 : -1;
}
