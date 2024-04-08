#include <myBigChars.h>

#define BIT_GET(k, i) ((big[i] >> (k - 1)) & 0x1)

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  if (big && value)
    {
      int bit;
      if (y <= 3)
        {
          bit = 33 - (8 * y + x + 1);
          *value = BIT_GET (bit, 0);
        }
      else
        {
          bit = 33 - (8 * (y - 4) + x + 1);
          *value = BIT_GET (bit, 1);
        }
      return 0;
    }
  else
    return -1;
}