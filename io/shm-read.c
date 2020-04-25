#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define SHM_NAME "/myshm"

int main (int argc, char *argv[])
{
    int shmfd = shm_open(SHM_NAME, O_RDONLY, 0);
    char buf[100];
    read(shmfd, buf, 100);
    printf("%s\n", buf);
    close(shmfd);
    return 0;
}
