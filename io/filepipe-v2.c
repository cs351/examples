#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    int fd;
    pid_t pid1, pid2;

    if ((pid1 = fork()) == 0) {
        fd = open("shared.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        dup2(fd, 1);
        execl("/bin/echo", "/bin/echo", "hello", NULL);
    }
    if ((pid2 = fork()) == 0) {
        fd = open("shared.txt", O_RDONLY);
        dup2(fd, 0);
        execl("/usr/bin/wc", "/usr/bin/wc", NULL);
    }
    waitpid(pid2, NULL, 0);
    return 0;
}
