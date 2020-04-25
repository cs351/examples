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

void echo (int fd) {
    ssize_t nread;
    char buf[80];
    nread = read(fd, buf, 80);
    printf("Server received %d bytes\n", nread);
    write(fd, buf, nread);
}

int main(int argc, char **argv) {
  int fd_skt, fd_client, fd_hwm = 0, fd, clen;
  struct sockaddr_in saddr, caddr;
  struct hostent *hp;
  fd_set set, read_set;
  clen = sizeof(caddr);

  fd_skt = socket(AF_INET, SOCK_STREAM, 0);
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(atoi(argv[1]));
  bind(fd_skt, (struct sockaddr *)&saddr, sizeof(saddr));
  listen(fd_skt, SOMAXCONN);
  if (fd_skt > fd_hwm)
    fd_hwm = fd_skt;
  FD_ZERO(&set);
  FD_SET(fd_skt, &set);
  while (1) {
    read_set = set;
    select(fd_hwm+1, &read_set, NULL, NULL, NULL);
    for (fd = 0; fd <= fd_hwm; fd++) {
      if (FD_ISSET(fd, &read_set)) {
	if (fd == fd_skt) {
	  fd_client = accept(fd_skt, (struct sockaddr *)&caddr, &clen);
	  FD_SET(fd_client, &set);
	  if (fd_client > fd_hwm)
	    fd_hwm = fd_client;
	  printf("Connection from %s\n", inet_ntoa(caddr.sin_addr));
	} else {
	  echo(fd);
	  FD_CLR(fd, &set);
	  if (fd == fd_hwm)
	    fd_hwm--;
	  close(fd);
	}
      }
    }
  }
}
