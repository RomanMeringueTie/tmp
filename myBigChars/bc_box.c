#include <myBigChars.h>
#include <myTerm.h>

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  mt_setbgcolor (box_bg);
  mt_setfgcolor (box_fg);
  mt_gotoXY (y1, x1);
  fflush (stdout);
  printf ("\E(0");
  fflush (stdout);
  char *str = bc_decode (header);
  printf ("l");
  fflush (stdout);
  int len = 0;
  mt_gotoXY (y1, x1 + 1);
  for (int i = 0; i < x2; i++)
    {
      fflush (stdout);
      mt_setbgcolor (box_bg);
      mt_setfgcolor (box_fg);
      printf ("q");
    }
  fflush (stdout);
  printf ("k");
  fflush (stdout);
  for (int i = 0; i < y2; i++)
    {
      mt_gotoXY (y1 + i + 1, x1);
      printf ("x");
      fflush (stdout);
      mt_gotoXY (y1 + i + 1, x1 + x2 + 1);
      printf ("x");
      fflush (stdout);
    }
  printf ("m");
  for (int i = 0; i < x2; i++)
    {
      mt_gotoXY (y1 + y2, x1 + i);
      printf ("q");
    }
  printf ("j");
  printf ("\n");
  if (str)
    {
      int len = strlen (str);
      int xstart = x1 + x2 / 2 - len / 2;
      mt_setbgcolor (header_bg);
      mt_setfgcolor (header_fg);
      mt_gotoXY (y1, xstart);
      printf ("\E(B%s\E(0", str);
      fflush (stdout);
    }
  mt_setdefaultcolor ();
  printf ("\E(B");
  free (str);
  return 0;
}