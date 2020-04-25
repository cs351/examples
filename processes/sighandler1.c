#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void sigint_handler (int sig) {
    printf("Signal %d received\n", sig);
    sleep(1);
}

int main () {
    signal(SIGINT, sigint_handler);
    while (1) {
        pause();
        printf("Back in main\n");
    }
}
