#include <myTerm.h>

int
mt_getscreensize (int *rows, int *cols)
{
  if (rows == NULL || cols == NULL)
    return -1;
  struct winsize ws;
  if (!ioctl (1, TIOCGWINSZ, &ws))
    {
      *rows = ws.ws_row;
      *cols = ws.ws_col;
      return 0;
    }
  else
    {
      return -1;
    }
}