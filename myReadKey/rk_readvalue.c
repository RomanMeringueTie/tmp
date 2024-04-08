#include <myReadKey.h>

int
rk_readvalue (int *value, int timeout)
{
  if (!value)
    return -1;
  if (rk_mytermregime (0, 100, timeout, 1, 0))
    return -1;
  int fd = open ("/dev/tty", O_RDWR);
  char str[10];
  int i = 0;
  while (1)
    {
      read (fd, &(str[i]), 1);
      if (str[i] == 0xd)
        break;
      if (!(str[i] >= '0' && str[i] <= '9'))
        return -1;
      i++;
    }
  *value = atoi (str);
  return 0;
}