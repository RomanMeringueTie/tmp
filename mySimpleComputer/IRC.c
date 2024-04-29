
#include <mySimpleComputer.h>

void
IRC (int signum)
{
  int reg1, reg2, reg3, reg4;
  sc_regGet (1, &reg1);
  sc_regGet (2, &reg2);
  sc_regGet (3, &reg3);
  sc_regGet (5, &reg4);
  if ((reg1 || reg2 || reg3 || reg4) == 0)
    {
      CU ();
      alarm (1);
      sc_regGet (1, &reg1);
      sc_regGet (2, &reg2);
      sc_regGet (3, &reg3);
      sc_regGet (5, &reg4);
      return;
    }
  else
    {
      rk_mytermregime (1, 0, 0, 0, 1);
      sc_regSet (5, 1);
      return;
    }
}