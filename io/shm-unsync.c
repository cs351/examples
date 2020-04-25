#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHM_KEY  0xABCD
#define SHM_SIZE 5

int main (int argc, char *argv[])
{
    int shmid, i;
    char *shm_arr;


    if (fork() != 0) {
        shmid   = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0600);
        shm_arr = shmat(shmid, NULL, 0);

        memset(shm_arr, 0, SHM_SIZE);

        srandomdev();
        for (i=0; i<SHM_SIZE; i++) {
            usleep(random() % 100000);
            shm_arr[i] = i;
        }
        
        shmdt(shm_arr);
        
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        srandomdev();

        shmid   = shmget(SHM_KEY, SHM_SIZE, 0600);
        if (shmid < 0) {
            perror(NULL);
            exit(0);
        }

        shm_arr = shmat(shmid, NULL, 0);

        srandomdev();
        for (i=0; i<SHM_SIZE; i++) {
            usleep(random() % 100000);
            printf("%d\n", shm_arr[i]);
        }
        
        shmdt(shm_arr);
    }

    return 0;
}
