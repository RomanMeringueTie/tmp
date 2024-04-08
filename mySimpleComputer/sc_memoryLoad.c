#include <mySimpleComputer.h>

int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rb");
  if (file < 0)
    {
      return -1;
    }
  if (fread (ram, 4, 128, file) == 0)
    {
      return -1;
    }
  fclose (file);
  return 0;
}