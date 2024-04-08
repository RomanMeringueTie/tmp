#include <mySimpleComputer.h>
#include <myTerm.h>

int
main ()
{
  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  for (int i = 0; i < 128; i++)
    {
      if (sc_memorySet (i, 10 * i) != 0)
        {
          return -1;
        }
    }
  // int *value = malloc (sizeof (int));
  // for (int i = 0; i < 70; i += 10)
  //   {
  //     sc_memoryGet (i, value);
  //     printDecodedCommand (*value);
  //   }
  // printf ("\n");
  // printf ("%d\n", sc_memorySet (100000000, 0));
  sc_regSet (1, 1);
  sc_regSet (2, 1);
  sc_regSet (5, 1);
  // printFlags ();
  // printf ("%d\n", sc_regSet (-1, 0));
  sc_accumulatorSet (5093);
  // printf ("%d\n", sc_accumulatorSet (-1));
  sc_icounterSet (15);
  // printf ("%d\n", sc_icounterSet (-1));
  // int *sign = malloc (sizeof (int));
  // int *comand = malloc (sizeof (int));
  // int *operand = malloc (sizeof (int));
  // sc_commandDecode (ram[50], sign, comand, operand);
  // printf ("%d %d %d\n", *sign, *comand, *operand);
  // sc_commandDecode (accumulator, sign, comand, operand);
  // printf ("%d %d %d\n", *sign, *comand, *operand);
  // sc_commandEncode (0, 51, 89, value);
  // printDecodedCommand (*value);
  // free (value);
  mt_clrscr ();
  for (int i = 0; i < 127; i++)
    printCell (i, fg_red, bg_black);
  printAccumulator ();
  printCounters ();
  printDecodedCommand (ram[78]);
  printFlags ();
  printCommand ();
  printTerm (50, 0);
  return 0;
}