#include <mySimpleComputer.h>

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (sign != 0 || command < 0 || command > 127 || value == NULL)
    return -1;
  *value = 0;
  *value = operand;
  (*value) = (*value) | command << 7;
  return 0;
}
