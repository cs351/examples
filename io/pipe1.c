#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    int i, j, fds[2];

    pipe(fds);
    if (fork() != 0) {
        for (i=0; i<10; i++) {
            write(fds[1], &i, sizeof(int));
        }
    } else {
        for (i=0; i<10; i++) {
            read(fds[0], &j, sizeof(int));
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
