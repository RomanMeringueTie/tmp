#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCounters (void)
{
  mt_gotoXY (14, 120);
  printf ("%d", command);
  fflush (stdout);
}