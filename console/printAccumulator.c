#include <mySimpleComputer.h>
#include <myTerm.h>

void
printAccumulator (void)
{
  mt_gotoXY (2, 118);
  printf ("%.5d\n", accumulator);
  fflush (stdout);
}