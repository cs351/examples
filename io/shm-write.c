#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define SHM_NAME "/myshm"

int main (int argc, char *argv[])
{
    int shmfd = shm_open(SHM_NAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    write(shmfd, argv[1], strlen(argv[1]));
    close(shmfd);
    return 0;
}
