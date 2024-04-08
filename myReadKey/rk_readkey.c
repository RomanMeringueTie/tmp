#include <myReadKey.h>

int
rk_readkey (enum keys *res)
{
  int fd = open ("/dev/tty", O_RDWR);
  char key[10];
  size_t len = read (fd, &key, 10);
  if (!strcmp (key, "\E[A"))
    *res = 0;
  else if (!strcmp (key, "\E[B"))
    *res = 1;
  else if (!strcmp (key, "\E[C"))
    *res = 2;
  else if (!strcmp (key, "\E[D"))
    *res = 3;
  else if (!strcmp (key, "l"))
    *res = 4;
  else if (!strcmp (key, "r"))
    *res = 5;
  else if (!strcmp (key, "s"))
    *res = 6;
  else if (!strcmp (key, "t"))
    *res = 7;
  else if (!strcmp (key, "i"))
    *res = 8;
  else if (!strcmp (key, "\E"))
    *res = 9;
  else if (key[0] == 0xd)
    *res = 10;
  else if (!strcmp (key, "\E[15~"))
    *res = 11;
  else if (!strcmp (key, "\E[17~"))
    *res = 12;
  else
    {
      *res = -1;
      return -1;
    }
  return 0;
}