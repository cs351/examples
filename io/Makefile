SRC_FILES = echo.c filepipe-v1.c filepipe-v2.c ioredir.c shm-write.c shm-read.c shm-unsync.c shm-sync.c sem-mutex.c sem-rendezvous.c pipe1.c pipe2.c pipe3.c

EXECS     = ${SRC_FILES:.c=}
O_FILES   = $(SRC_FILES:%.c=%.o)

CC        = gcc
CFLAGS    = -Wall -g
LDFLAGS   = 
LDLIBS    = # -lrt # need this when compiling on Linux for shm-open

all: $(EXECS)

clean:
	rm -rf $(EXECS) outfile.txt shared.txt 	*.dSYM
