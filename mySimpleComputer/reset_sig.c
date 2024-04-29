#include "mySimpleComputer.h"

void
reset_sig (int sig)
{
  free (ram);
  sc_memoryInit ();
  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  for (int i = 0; i < 128; i++)
    printCell (i, fg_green, bg_black);
  mt_setdefaultcolor ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printCommand ();
  fflush (stdout);
}