#include <mySimpleComputer.h>

int
sc_icounterSet (int value)
{
  if (value < 0)
    return -1;
  command = value;
  return 0;
}