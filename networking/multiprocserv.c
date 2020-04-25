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

void sigchild_handler (int sig) {
  pid_t pid;
  int stat;
  while ((pid = waitpid(-1, &stat, WNOHANG)) > 0);
}

int main(int argc, char **argv) {
    int fd_skt, fd_client, clen;
    struct sockaddr_in saddr, caddr;
    struct hostent *hp;
    clen = sizeof(caddr);

    fd_skt = socket(AF_INET, SOCK_STREAM, 0);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(atoi(argv[1]));
    bind(fd_skt, (struct sockaddr *)&saddr, sizeof(saddr));
    listen(fd_skt, SOMAXCONN);
    signal(SIGCHLD, sigchild_handler);

    while (1) {
	fd_client = accept(fd_skt, (struct sockaddr *)&caddr, &clen);
	hp = gethostbyaddr((const char *)&caddr.sin_addr.s_addr,
		sizeof(caddr.sin_addr.s_addr), AF_INET);
	if (hp)
	  printf("Connection from %s\n", hp->h_name);
	if (fork() == 0) {
	  close(fd_skt);
	  echo(fd_client);
	  close(fd_client);
	  exit(0);
	}
	close(fd_client);
    }
}
