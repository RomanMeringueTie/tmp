#include <mySimpleComputer.h>

#define FLAG_SET(k) (flag | (1 << (k - 1)))
#define FLAG_CLEAR(k) (flag & (~(1 << (k - 1))))

int
sc_regSet (int reg, int value)
{
  if (reg < 0 || reg > 5)
    return -1;
  if (value)
    flag = FLAG_SET (reg);
  else
    flag = FLAG_CLEAR (reg);
  return 0;
}