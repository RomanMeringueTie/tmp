#include <myBigChars.h>
#include <mySimpleComputer.h>
#include <myTerm.h>

void
printBigCell (int *font, int index)
{
  int number = ram[index];
  char str[10];
  sprintf (str, "%.4x", number);
  int arr[8];
  for (int i = 0; i < strlen (str); i++)
    {
      sscanf (&(str[i]), "%1x", &(arr[i]));
    }
  bc_printbigchar (&(font[32]), 152, 5, fg_white, bg_black);
  for (int i = 0; i < strlen (str); i++)
    {
      bc_printbigchar (&(font[arr[i] * 2]), 162 + i * 10, 5, fg_white,
                       bg_black);
    }
  printf ("\n");
}