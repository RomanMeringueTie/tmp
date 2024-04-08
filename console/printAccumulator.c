#include <mySimpleComputer.h>
#include <myTerm.h>

void
printAccumulator (void)
{
  mt_gotoXY (2, 119);
  printf ("%d\n", accumulator);
  fflush (stdout);
}