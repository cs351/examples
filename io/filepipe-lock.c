#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main ()
{
    int fd, n;
    struct flock fl;
    char buf[80];
    
    fd = open("shared.txt", O_RDWR|O_CREAT, 0600);

    fl.l_type = F_WRLCK;
    fl.l_whence = 0;
    fl.l_len = 0;
    fl.l_pid = getpid();
    fcntl(fd, F_SETLK, &fl); /* set write (exclusive) lock */

    if (fork() == 0) {
        fl.l_type = F_RDLCK;
        fcntl(fd, F_SETLKW, &fl); /* wait for & set read lock */
        lseek(fd, 0, SEEK_SET);   /* rewind pos */
        n = read(fd, buf, sizeof(buf));
        write(1, buf, n);
        exit(0);
    } else {
        sleep(1);
        write(fd, "hello there!", 13);
        fl.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &fl);  /* release lock */
    }

    return 0;
}
