#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>

int main () {
  int i, bg, pid;
  char buf[100], *argv[10];

  /* read-eval loop */
  while (!feof(stdin)) {
    printf("$ ");  /* print prompt */

    /* read command and build argv */
    if (!fgets(buf, 100, stdin)) {
      break;
    }
    
    for (i=0, argv[0] = strtok(buf, " \n");
         argv[i];
         argv[++i] = strtok(NULL, " \n"));

    if (*argv[i-1] == '&') {
      bg = 1;
      argv[i-1] = NULL;
    } else {
      bg = 0;
    }

    if (strcmp(buf, "quit") == 0) {
      break;
    } else {
      /* fork and run command in child */
      if ((pid = fork()) == 0) {
        if (execvp(argv[0], argv) < 0) {
          printf("Command not found\n");
          exit(0);
        }
      }
    }

    if (!bg) {
      /* wait for completion in parent */
      waitpid(pid, NULL, 0);
    }
  }
  return 0;
}
