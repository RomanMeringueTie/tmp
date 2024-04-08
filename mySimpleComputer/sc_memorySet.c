#include <mySimpleComputer.h>

int
sc_memorySet (int address, int value)
{
  if ((address >= 0 && address <= 127) && sc_commandValidate (value) == 0)
    {
      ram[address] = value;
      return 0;
    }
  else
    return -1;
}
