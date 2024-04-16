#include <mySimpleComputer.h>
#include <myTerm.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (20, 151);
  printf ("dec:%.5d oct:%.6o hex:%.4x bin:%.15b", value, value, value, value);
  fflush (stdout);
}