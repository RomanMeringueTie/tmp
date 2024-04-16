#include <myReadKey.h>

int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  int fd = open ("/dev/tty", O_RDWR);
  struct termios *tnew = malloc (sizeof (struct termios));
  tnew->c_lflag |= (regime) ? ICANON : ~ICANON;
  tnew->c_lflag |= (echo) ? ECHO : ~ECHO;
  tnew->c_lflag |= (sigint) ? ISIG : ~ISIG;
  if (regime == 0)
    {
      tnew->c_cc[VMIN] = vmin;
      tnew->c_cc[VTIME] = vtime;
    }
  tcsetattr (fd, TCSANOW, tnew);
  close (fd);
  free (tnew);
  return 0;
}