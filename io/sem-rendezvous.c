#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
    int i;
    pid_t p1, p2;
    sem_t *p1_arrived, *p2_arrived;
    p1_arrived = sem_open("/sem1", O_CREAT, 0600, 0);
    p2_arrived = sem_open("/sem2", O_CREAT, 0600, 0);

    if ((p1 = fork()) == 0) {
        srandomdev();
        /* P1 */
        for (i=0; i<10; i++) {
            sleep(random()%3);
            /*sem_post(p1_arrived);
              sem_wait(p2_arrived);*/
            printf("P1: Iter %d\n", i); 
            fflush(stdout);
        }
        exit(0);
    }
    if ((p2 = fork()) == 0) {
        srandomdev();
        /* P2 */
        for (i=0; i<10; i++) {
            sleep(random()%3);
            /*sem_post(p2_arrived);
              sem_wait(p1_arrived);*/
            printf("P2: Iter %d\n", i);
            fflush(stdout);
        }
        exit(0);
    }

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);

    sem_close(p1_arrived);
    sem_close(p2_arrived);
    sem_unlink("/sem1");
    sem_unlink("/sem2");
    
    return 0;
}
