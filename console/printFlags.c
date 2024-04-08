#include <mySimpleComputer.h>
#include <myTerm.h>

void
printFlags (void)
{
  mt_gotoXY (8, 116);
  if (flag & 0x1)
    printf ("П ");
  else
    printf ("_ ");
  if (flag & 0x2)
    printf ("0 ");
  else
    printf ("_ ");
  if (flag & 0x4)
    printf ("М ");
  else
    printf ("_ ");
  if (flag & 0x8)
    printf ("Т ");
  else
    printf ("_ ");
  if (flag & 0x10)
    printf ("Е");
  else
    printf ("_");
  fflush (stdout);
}