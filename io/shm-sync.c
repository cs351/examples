#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHM_KEY  0xABCD
#define SHM_SIZE 5

int sig_recvd = 0;
void sighandler (int sig)
{
    if (sig == SIGUSR1) {
        sig_recvd = 1;
        printf("sig received\n");
    }
}

int main (int argc, char *argv[])
{
    int shmid, i;
    pid_t pid;
    char *shm_arr;

    signal(SIGUSR1, sighandler);
    
    if ((pid = fork()) != 0) {
        shmid   = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0600);
        shm_arr = shmat(shmid, NULL, 0);

        memset(shm_arr, 0, SHM_SIZE);
        for (i=0; i<SHM_SIZE; i++) {
            shm_arr[i] = i;
        }

        kill(pid, SIGUSR1); // tell child to continue

        shmdt(shm_arr);
        while (!sig_recvd) // wait for child signal
            pause(); 
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        while (!sig_recvd) // wait for parent signal
            pause(); 
        
        shmid = shmget(SHM_KEY, SHM_SIZE, 0600);
        if (shmid < 0) {
            perror(NULL);
            exit(0);
        }

        shm_arr = shmat(shmid, NULL, 0);

        for (i=0; i<SHM_SIZE; i++) {
            printf("%d\n", shm_arr[i]);
        }
        
        shmdt(shm_arr);
        kill(getppid(), SIGUSR1); // tell parent to continue
    }

    return 0;
}
