/*
 * Demonstrates:
 * - dynamic memory allocation
 * - self-referential struct
 * - singly-linked list implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

struct ll_node {
  char *data;
  struct ll_node *next;
};

struct ll_node *prepend(char *data, struct ll_node *next) {
  struct ll_node *n = malloc(sizeof(struct ll_node));
  n->data = data;
  n->next = next;
  return n;
}

void free_llist(struct ll_node *head) {
  struct ll_node *p=head, *q;
  while (p) {
      q = p->next;
      free(p);
      p = q;
  }
}

int main(int argc, char *argv[]) {
  struct ll_node *head = 0;
  
  for (int i=0; i<argc; i++) {
    head = prepend(argv[i], head);
  }
  
  struct ll_node *p;
  for (p=head; p; p=p->next) {
    printf("%s ", p->data);
  }
  printf("\n");
  
  free_llist(head);
  return 0;
}
