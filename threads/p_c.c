#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int in = 0,
    out = 0,
    count = 0;
    
int buffer[BUFFER_SIZE];

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  not_empty = PTHREAD_COND_INITIALIZER;

void *producer_thread_fn (void *argp) {
  int item=0;
  while (1) {
    while (count == BUFFER_SIZE) ; // wait til not full
    pthread_mutex_lock(&mtx);
    buffer[in] = item++; // produce item 
    in = (in + 1) % BUFFER_SIZE; 
    count++;
    pthread_mutex_unlock(&mtx);
    pthread_cond_signal(&not_empty); // signal any waiting consumers
  }
}

void *consumer_thread_fn (void *argp) {
  while (1) { 
    pthread_mutex_lock(&mtx);
    while (count == 0) {
      pthread_cond_wait(&not_empty, &mtx); // wait til not_empty condition signaled
    }
    printf("Consumer %u: %d\n", pthread_self(), buffer[out]); fflush(stdout);
    out = (out + 1) % BUFFER_SIZE; 
    count--; 
    pthread_mutex_unlock(&mtx);
  }
}

int main (int argc, char *argv[]) {
  pthread_t tid;
  int i;
  for (i=0; i<BUFFER_SIZE; i++) {
    buffer[i] = -1;
  }
  pthread_create(&tid, NULL, consumer_thread_fn, NULL); // consumer 1
  pthread_create(&tid, NULL, consumer_thread_fn, NULL); // consumer 2
  pthread_create(&tid, NULL, producer_thread_fn, NULL);
  pthread_exit(NULL);
}
