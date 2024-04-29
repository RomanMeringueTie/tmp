#include <mySimpleComputer.h>

int
main ()
{
  FILE *file = fopen ("example", "wb+");
  int *value = malloc (sizeof (int));
  sc_commandEncode (0, 0x01, 0, value);
  fwrite (value, 4, 1, file);
  *value = 12;
  fwrite (value, 4, 1, file);
  sc_commandEncode (0, 0x14, 1, value);
  fwrite (value, 4, 1, file);
  sc_commandEncode (0, 0x15, 3, value);
  fwrite (value, 4, 1, file);
  sc_commandEncode (0, 0x1E, 3, value);
  fwrite (value, 4, 1, file);
  *value = 999999;
  fwrite (value, 4, 1, file);
  fclose (file);
  return 0;
}