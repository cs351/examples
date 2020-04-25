#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
    int i, j, fd;
    sem_t *mutex = sem_open("/mutex", O_CREAT, 0600, 1);
    fd = open("shared.txt", O_CREAT|O_WRONLY, 0600);
    for (i=0; i<5; i++) {
        if (fork() == 0) {
            srandomdev();
            while (sem_wait(mutex) < 0) ;
            for (j='0'; j<='9'; j++) {
                write(fd, &j, 1);
                sleep(random() % 3);
            }
            sem_post(mutex);
            exit(0);
        }
    }
    while (wait(NULL) >= 0);
    sem_close(mutex);
    sem_unlink("/mutex");
    return 0;
}
