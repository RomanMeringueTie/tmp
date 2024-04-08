#include <myBigChars.h>

int
bc_bigcharwrite (int fd, int *big, int count)
{
  if (big)
    {
      if (write (fd, big, count * sizeof (int) * 2)
          == count * sizeof (int) * 2)
        return 0;
      else
        return -1;
    }
  else
    return -1;
}