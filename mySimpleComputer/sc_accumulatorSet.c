#include <mySimpleComputer.h>

int
sc_accumulatorSet (int value)
{
  if (value >= 0x7FFF || value < 0)
    return -1;
  accumulator = value;
  return 0;
}
