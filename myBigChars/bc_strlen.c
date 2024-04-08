#include <myBigChars.h>

int
bc_strlen (char *str)
{
  if (str == NULL)
    return 0;
  int length = 0;
  char ch = *str;
  if ((ch & 0x80) == 0x00)
    {
      length += 1;
    }
  else if ((ch & 0xE0) == 0xC0)
    {
      length += 2;
    }
  else if ((ch & 0xF0) == 0xE0)
    {
      length += 3;
    }
  else if ((ch & 0xF8) == 0xF0)
    {
      length += 4;
    }
  else
    {
      return -1;
    }
  return length;
}