#include <myReadKey.h>
#include <mySimpleComputer.h>

void
CU ()
{
  int oper, read, sign, com;
  if (sc_commandDecode (ram[command], &sign, &com, &oper) != 0)
    {
      sc_regSet (5, 1);
      sc_regSet (4, 1);
      return;
    }
  else if ((oper < 0) || (oper > 127))
    {
      sc_regSet (3, 1);
      sc_regSet (5, 1);
      return;
    }
  else
    command++;
  if ((com >= 0x1E) && (com <= 0x21) || (com >= 0x33) && (com <= 0x34))
    {
      if (ALU (com, oper) != 0)
        sc_regSet (5, 1);
    }
  else if (com == 0)
    {
    }
  else if (com == 0x01)
    {
      mt_gotoXY (60, 1);
      printf ("Кочетков Роман Николаевич, ИВ-222");
      fflush (stdout);
    }
  else if (com == 0x0A)
    {
      // mt_gotoXY (24, 6);
      // printf ("addr %d < +%.4x", oper, ram[oper]);
      // fflush (stdout);
      // int new_value = 0;
      // mt_gotoXY (((x * 8 + y) / 8) + 3, ((x * 8 + y) % 8) * 12 + 10);
      // mt_setbgcolor (bg_black);
      // mt_setfgcolor (fg_green);
      // printf ("     \n");
      // fflush (stdout);
      // mt_gotoXY (((x * 8 + y) / 8) + 3, ((x * 8 + y) % 8) * 12 + 10);
      // fflush (stdout);
      // int tmp = rk_readvalue (&new_value, 10);
      // if (tmp != -1 && sc_commandValidate (new_value) != -1)
      //   ram[(x * 8 + y)] = new_value;
      // printCell (y + x * 8, fg_green, bg_white);
      // mt_setdefaultcolor ();
    }
  else if (com == 0x14)
    {
      accumulator = ram[oper];
      printAccumulator ();
    }
  else if (com == 0x15)
    {
      ram[oper] = accumulator;
      printCell (oper, fg_green, bg_black);
    }
  else if (com == 0x29)
    {
      if (accumulator < 0)
        command = oper - 1;
    }
  else if (com == 0x2A)
    {
      if (!accumulator)
        command = oper - 1;
    }
  else if (com == 0x2B)
    {
      sc_regSet (4, 1);
    }
  mt_setdefaultcolor ();
  printCounters ();
  printFlags ();
  return;
}