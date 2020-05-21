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

int main() {
  struct ll_node *head = prepend("list!", NULL);
  head = prepend("linked", head);
  head = prepend("a",      head);
  head = prepend("I'm",    head);
  
  struct ll_node *p;
  for (p=head; p; p=p->next) {
      printf("%s ", p->data);
  }
  printf("\n");
  
  free_llist(head);
  return 0;
}
