#include <mySimpleComputer.h>
int
ALU (int com, int oper)
{
  if (com == 0x1E)
    accumulator += ram[oper];
  else if (com == 0x1F)
    accumulator -= ram[oper];
  else if (com == 0x20)
    {
      if (ram[oper] != 0)
        accumulator /= ram[oper];
      else
        sc_regSet (2, 1);
    }
  else if (com == 0x21)
    accumulator *= ram[oper];
  else if (com == 0x33)
    ram[oper] = ~accumulator;
  else if (com == 0x34)
    accumulator &= ram[oper];
  else
    return -1;
  printAccumulator ();
  return 0;
}