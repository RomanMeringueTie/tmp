#include <mySimpleComputer.h>

int
sc_memorySave (char *filename)
{
  FILE *file = fopen (filename, "wb");
  if (file < 0)
    {
      return -1;
    }
  if (fwrite (ram, 4, 128, file) == 0)
    {
      return -1;
    }
  fclose (file);
  return 0;
}