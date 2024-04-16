#include <myReadKey.h>
#include <mySimpleComputer.h>

int
rk_mytermrestore (void)
{
  int fd = open ("myReadKey/term.bin", O_RDWR);
  int tty = open ("/dev/tty", O_RDWR);
  struct termios *tnew = malloc (sizeof (struct termios));
  if (read (fd, tnew, sizeof (struct termios)) != sizeof (struct termios))
    {
      free (tnew);
      close (fd);
      close (tty);
      return -1;
    }
  if (tcsetattr (tty, TCSAFLUSH, tnew) == -1)
    {
      free (tnew);
      close (fd);
      close (tty);
      return -1;
    }
  return 0;
}