#include <myBigChars.h>

#define BIT_SET(k, i) ((big[i]) | (1 << (k - 1)))
#define BIT_CLEAR(k, i) ((big[i]) & (~(1 << (k - 1))))

int
bc_setbigcharpos (int *big, int x, int y, int value)
{
  if (big && x >= 0 && x <= 7 && y >= 0 && y <= 7)
    {
      int bit;
      if (y <= 3)
        {
          bit = 33 - (8 * y + x + 1);
          if (value != 0)
            big[0] = BIT_SET (bit, 0);
          else
            big[0] = BIT_CLEAR (bit, 0);
        }
      else
        {
          bit = 33 - (8 * (y - 4) + x + 1);
          if (value != 0)
            big[1] = BIT_SET (bit, 1);
          else
            big[1] = BIT_CLEAR (bit, 1);
        }
      return 0;
    }
  else
    return -1;
}