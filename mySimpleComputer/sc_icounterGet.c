#include <mySimpleComputer.h>

int
sc_icounterGet (int *value)
{
  if (value == NULL)
    return -1;
  *value = command;
  return 0;
}