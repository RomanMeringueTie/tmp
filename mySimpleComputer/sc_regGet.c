#include <mySimpleComputer.h>

#define FLAG_GET(k) ((flag >> (k - 1)) & 0x1)

int
sc_regGet (int reg, int *value)
{
  if (reg < 1 || reg > 4 || value == NULL)
    return -1;
  *value = FLAG_GET (reg);
  return 0;
}