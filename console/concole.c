#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>

int
main (int argc, char **argv)
{
  if (isatty (1))
    {
      int fd;
      if (argc > 1)
        fd = open (argv[1], O_RDONLY);
      else
        fd = open ("console/font.bin", O_RDONLY);
      int font_array[36];
      int *count = malloc (sizeof (int));
      bc_bigcharread (fd, font_array, 18, count);
      if (*count / (2 * sizeof (int)) != 18)
        return -1;
      int cols, rows;
      if (mt_getscreensize (&rows, &cols) != 0)
        return -1;
      if (cols < 150 && rows < 35)
        return -1;
      mt_setdefaultcolor ();
      rk_mytermsave ();
      sc_memoryInit ();
      sc_regInit ();
      sc_regSet (4, 1);
      sc_accumulatorInit ();
      sc_icounterInit ();
      for (int i = 0; i < 128; i++)
        {
          if (sc_memorySet (i, 0) != 0)
            {
              return -1;
            }
        }
      mt_clrscr ();
      char *rm = bc_encode ("Memory");
      char *ac = bc_encode ("Accumulator");
      char *fl = bc_encode ("Flags");
      char *ic = bc_encode ("Counter");
      char *co = bc_encode ("Command");
      char *dc = bc_encode ("DecodedCommand");
      char *zd = bc_encode ("Zoomed");
      char *io = bc_encode ("IN/OUT");
      char *k = bc_encode ("Keys");
      mt_setcursorvisible (0);
      for (int i = 0; i < 128; i++)
        printCell (i, fg_green, bg_black);
      mt_setdefaultcolor ();
      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
      printKeys ();
      bc_box (1, 1, 105, 20, fg_white, fg_black, rm, fg_blue, fg_black);
      bc_box (150, 1, 50, 15, fg_white, fg_black, zd, fg_blue, fg_black);
      bc_box (110, 1, 20, 2, fg_white, fg_black, ac, fg_blue, fg_black);
      bc_box (110, 7, 20, 2, fg_white, fg_black, fl, fg_blue, fg_black);
      bc_box (110, 13, 20, 2, fg_white, fg_black, ic, fg_blue, fg_black);
      bc_box (110, 19, 20, 2, fg_white, fg_black, co, fg_blue, fg_black);
      bc_box (150, 19, 50, 2, fg_white, fg_black, dc, fg_blue, fg_black);
      bc_box (1, 22, 20, 4, fg_white, fg_black, io, fg_blue, fg_black);
      bc_box (25, 22, 45, 4, fg_white, fg_black, k, fg_blue, fg_black);
      mt_setdefaultcolor ();
      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
      int x = 0;
      int y = 0;
      mt_gotoXY (x, y);
      fflush (stdout);
      enum keys key;
      rk_mytermrestore ();
      // rk_mytermsave ();
      rk_mytermregime (0, 0, 0, 0, 0);
      fflush (stdout);
      printCell (0, fg_green, bg_white);
      printBigCell (font_array, 0);
      printDecodedCommand (ram[0]);
      mt_gotoXY (23, 6);
      printf ("prev: +%.4x", ram[127]);
      fflush (stdout);
      mt_gotoXY (24, 6);
      printf ("addr %d > +%.4x", 0, ram[0]);
      fflush (stdout);
      mt_gotoXY (25, 6);
      printf ("next: +%.4x", ram[1]);
      fflush (stdout);
      int prev_index = 0;
      fflush (stdout);
      signal (SIGALRM, IRC);
      signal (SIGUSR1, reset_sig);
      while (key != 9)
        {
          fflush (stdout);
          rk_readkey (&key);
          if (key == 5)
            {
              raise (SIGALRM);
              sc_regSet (4, 0);
              printFlags ();
            }
          if (key == 0)
            {
              if (x == 0)
                x = 16;
              x--;
            }
          else if (key == 1)
            {
              if (x == 15)
                x = -1;
              x++;
            }
          else if (key == 2)
            {
              if (y == 7)
                y = -1;
              y++;
            }
          else if (key == 3)
            {
              if (y == 0)
                y = 8;
              y--;
            }
          else if (key == 6)
            {
              fflush (stdout);
              char filename[20];
              mt_gotoXY (33, 1);
              printf ("Save file name:                    ");
              fflush (stdout);
              scanf ("%s", filename);
              sc_memorySave (filename);
              mt_gotoXY (33, 19);
              printf ("%s", filename);
              fflush (stdout);
            }
          else if (key == 4)
            {
              fflush (stdout);
              char filename[20];
              mt_gotoXY (34, 1);
              printf ("Load file name:                    ");
              fflush (stdout);
              scanf ("%s", filename);
              if (sc_memoryLoad (filename) != 0)
                {
                  mt_gotoXY (34, 19);
                  printf ("No such save file");
                  fflush (stdout);
                }
              mt_gotoXY (34, 19);
              printf ("%s", filename);
              fflush (stdout);
              mt_setdefaultcolor ();
              for (int i = 0; i < 128; i++)
                printCell (i, fg_green, bg_black);
              bc_box (1, 1, 105, 20, fg_white, fg_black, rm, fg_blue,
                      fg_black);
              bc_box (150, 1, 50, 15, fg_white, fg_black, zd, fg_blue,
                      fg_black);
              bc_box (110, 1, 20, 2, fg_white, fg_black, ac, fg_blue,
                      fg_black);
              bc_box (110, 7, 20, 2, fg_white, fg_black, fl, fg_blue,
                      fg_black);
              bc_box (110, 13, 20, 2, fg_white, fg_black, ic, fg_blue,
                      fg_black);
              bc_box (110, 19, 20, 2, fg_white, fg_black, co, fg_blue,
                      fg_black);
              bc_box (150, 19, 50, 2, fg_white, fg_black, dc, fg_blue,
                      fg_black);
              bc_box (1, 22, 20, 4, fg_white, fg_black, io, fg_blue, fg_black);
              bc_box (25, 22, 45, 4, fg_white, fg_black, k, fg_blue, fg_black);
              mt_setdefaultcolor ();
              printAccumulator ();
              printCounters ();
              printFlags ();
              printCommand ();
              fflush (stdout);
            }
          else if (key == 10)
            {
              mt_gotoXY (24, 6);
              printf ("addr %d < +%.4x", prev_index, ram[prev_index]);
              fflush (stdout);
              int new_value = 0;
              mt_gotoXY (((x * 8 + y) / 8) + 3, ((x * 8 + y) % 8) * 12 + 10);
              mt_setbgcolor (bg_black);
              mt_setfgcolor (fg_green);
              printf ("     \n");
              fflush (stdout);
              mt_gotoXY (((x * 8 + y) / 8) + 3, ((x * 8 + y) % 8) * 12 + 10);
              fflush (stdout);
              int tmp = rk_readvalue (&new_value, 10);
              if (tmp != -1 && sc_commandValidate (new_value) != -1)
                ram[(x * 8 + y)] = new_value;
              printCell (y + x * 8, fg_green, bg_white);
              mt_setdefaultcolor ();
            }
          else if (key == 11)
            {
              int new_value = 0;
              mt_gotoXY (2, 118);
              mt_setdefaultcolor ();
              printf (">        \n");
              fflush (stdout);
              mt_gotoXY (2, 118);
              fflush (stdout);
              rk_readvalue (&new_value, 10);
              accumulator = new_value;
              printAccumulator ();
              fflush (stdout);
            }
          else if (key == 12)
            {
              int new_value = 0;
              mt_gotoXY (14, 119);
              mt_setdefaultcolor ();
              printf (">        \n");
              fflush (stdout);
              mt_gotoXY (14, 119);
              fflush (stdout);
              rk_readvalue (&new_value, 10);
              command = new_value;
              printCounters ();
              fflush (stdout);
            }
          else if (key == 8)
            {
              raise (SIGUSR1);
            }
          printDecodedCommand (ram[y + x * 8]);
          printCell (prev_index, fg_green, bg_black);
          printCell (y + x * 8, fg_green, bg_white);
          printBigCell (font_array, x * 8 + y);
          fflush (stdout);
          prev_index = x * 8 + y;
          mt_gotoXY (23, 6);
          printf ("prev: +%.4x",
                  ram[(prev_index == 0) ? (127) : (prev_index - 1)]);
          fflush (stdout);
          mt_gotoXY (24, 6);
          printf ("addr %d > +%.4x", prev_index, ram[prev_index]);
          fflush (stdout);
          mt_gotoXY (25, 6);
          printf ("next: +%.4x",
                  ram[(prev_index == 127) ? (0) : (prev_index + 1)]);
          fflush (stdout);
        }
      free (count);
      free (rm);
      free (zd);
      free (ac);
      free (fl);
      free (ic);
      free (co);
      free (dc);
      free (io);
      mt_setcursorvisible (1);
      mt_gotoXY (70, 1);
      rk_mytermrestore ();
      mt_setfgcolor (fg_black);
      fflush (stdout);
      return 0;
    }
  return -1;
}