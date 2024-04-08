#include <mySimpleComputer.h>

int
sc_commandValidate (int command)
{
  if (command > 0x3fff)
    return -1;
  return 0;
}
