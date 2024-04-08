#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCell (int address, enum colors fg, enum colors bg)
{
  mt_setfgcolor (fg);
  mt_setbgcolor (bg);
  mt_gotoXY ((address / 8) + 3, (address % 8) * 12 + 10);
  printf ("+%04x", ram[address]);
  fflush (stdout);
}
