#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdlib.h>

int main () {
    if (fork() == 0) {
        if (fork() == 0) {
            printf("3");
        } else {
            pid_t pid;
            int status;
            if ((pid = wait(&status)) > 0) {
                printf("4");
            }
        }
    } else {
        if (fork() == 0) {
            printf("1");
            exit(0);
        }
        printf("2");
    }
    printf("0");
    return 0;
}