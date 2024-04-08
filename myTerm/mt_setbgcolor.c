#include <myTerm.h>

int
mt_setbgcolor (enum colors x)
{
  char *str = malloc (100);
  sprintf (str, "\E[48:5;%dm", x);
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, str, strlen (str));
  size_t len = strlen (str);
  free (str);
  close (fd);
  return (result == len) ? 0 : -1;
}