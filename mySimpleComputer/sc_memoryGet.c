#include <mySimpleComputer.h>

int
sc_memoryGet (int address, int *value)
{
  if (value == NULL)
    return -1;
  *value = ram[address];
  return 0;
}