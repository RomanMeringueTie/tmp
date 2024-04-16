#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCounters (void)
{
  mt_gotoXY (14, 119);
  printf ("%.5d", command);
  fflush (stdout);
}