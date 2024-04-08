#include <myBigChars.h>

int
bc_printA (char *str)
{
  if (str)
    {
      printf ("\E(0%s\E(B", str);
    }
  else
    return -1;
}