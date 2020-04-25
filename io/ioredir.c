#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    int fd;
    if (fork() == 0) {
         fd = open("outfile.txt",
                  O_RDWR | O_CREAT,    /* read & write, create if nonexistent */
                  S_IRUSR | S_IWUSR);  /* set read & write perms for user */
        
        dup2(fd, 1); /* redir output to file */
        
        execl("/bin/echo", "/bin/echo", "hello", NULL);
    }
    wait(NULL);
    return 0;
}
