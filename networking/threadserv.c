#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

void echo (int fd) {
    ssize_t nread;
    char buf[80];
    nread = read(fd, buf, 80);
    printf("Server received %d bytes\n", nread);
    write(fd, buf, nread);
}

void *thread (void *vargp) {
  int fd = *((int *)vargp);
  pthread_detach(pthread_self());
  free(vargp);
  echo(fd);
  close(fd);
  return NULL;
}

int main(int argc, char **argv) {
  int fd_skt, *fd_client, clen;
  pthread_t tid;
  struct sockaddr_in saddr, caddr;
  struct hostent *hp;
  clen = sizeof(caddr);

  fd_skt = socket(AF_INET, SOCK_STREAM, 0);
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(atoi(argv[1]));
  bind(fd_skt, (struct sockaddr *)&saddr, sizeof(saddr));
  listen(fd_skt, SOMAXCONN);

  while (1) {
    fd_client = malloc(sizeof(int));
    *fd_client = accept(fd_skt, (struct sockaddr *)&caddr, &clen);
    printf("Connection from %s\n", inet_ntoa(caddr.sin_addr));
    pthread_create(&tid, NULL, thread, fd_client);
  }
}

