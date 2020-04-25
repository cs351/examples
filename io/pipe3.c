#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main () {
    int fds[2];
    pid_t pid1, pid2;
    pipe(fds);
    if ((pid1 = fork()) == 0) {
        dup2(fds[1], 1);
        close(fds[1]);
        execlp("echo", "echo", "hello", NULL);
    }
    close(fds[1]);
    if ((pid2 = fork()) == 0) {
        dup2(fds[0], 0);
        execlp("wc", "wc", NULL);
    }
    waitpid(pid2, NULL, 0);
    return 0;
}
