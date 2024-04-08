#include <myReadKey.h>
#include <mySimpleComputer.h>

int rk_mytermsave (void)
{
    int fd = open ("myReadKey/term.bin", O_RDWR);
    int tty = open ("/dev/tty", O_RDWR);
    struct termios *tsaved = malloc(sizeof(struct termios));
    if (tcgetattr (tty, tsaved) != 0)
    {
        free(tsaved);
        close(fd);
        close(tty);
        return -1;
    }
    if (write(fd, tsaved, sizeof(struct termios) != sizeof(struct termios)))
    {
        free(tsaved);
        close(fd);
        close(tty);
        return -1;
    }
    free(tsaved);
    close(fd);
    close(tty);
    return 0;
}