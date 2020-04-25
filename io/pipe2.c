#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int i, n, fds[2];
    char buf[1000];
    char *strings[] = {"the", "quick", "brown", "fox", "jumps",
                       "over", "the", "lazy", "dog"};

    pipe(fds);
    for (i=0; i<9; i++) {
        if (fork() == 0) {
            usleep(random() % 1000000);
            write(fds[1], strings[i], strlen(strings[i]));
            exit(0);
        }
    }
    
    while ((n = read(fds[0], buf, sizeof(buf))) > 0) {
        write(1, buf, n);
        printf("\n");
    }

    return 0;
}
