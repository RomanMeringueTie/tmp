#include <myBigChars.h>

int
bc_printbigchar (int arr[2], int x, int y, enum colors fg, enum colors bg)
{
  if (arr)
    {
      int bin[64];
      int tmp1 = *arr;
      int tmp2 = *(arr + 1);
      unsigned int mask = 1U << (32 - 1);
      for (int i = 0; i < 32; i++)
        {
          bin[i] = (tmp1 & mask) ? 1 : 0;
          (tmp1) <<= 1;
        }
      for (int i = 32; i < 64; i++)
        {
          bin[i] = (tmp2 & mask) ? 1 : 0;
          (tmp2) <<= 1;
        }
      mt_setbgcolor (bg);
      mt_setfgcolor (fg);
      fflush (stdout);
      for (int i = 0; i < 64; i++)
        {
          fflush (stdout);
          if (bin[i])
            printf ("\E(0a\E(B");
          else
            printf (" ");
          if (i % 8 == 0)
            {
              mt_gotoXY (y + i / 8, x);
              fflush (stdout);
            }
        }
      // printf ("\n");
      // mt_delline ();
      fflush (stdout);
      return 0;
    }
  else
    return -1;
}