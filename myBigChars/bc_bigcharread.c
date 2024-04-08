#include <myBigChars.h>

int
bc_bigcharread (int fd, int *big, int need_count, int *count)
{
  if (big && count)
    {
      *count = read (fd, big, need_count * sizeof (int) * 2);
      return 0;
    }
  else
    return -1;
}