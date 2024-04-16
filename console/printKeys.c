#include <mySimpleComputer.h>
#include <myTerm.h>

void
printKeys (void)
{
  mt_gotoXY (23, 26);
  printf ("l - load s - save i - reset r- run t - stop\n");
  mt_gotoXY (24, 26);
  printf ("ESC - escape F5 - accumulator\n");
  mt_gotoXY (25, 26);
  printf ("F6 - instruction counter\n");
  fflush (stdout);
}