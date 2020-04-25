SRC_FILES = csapp_forks.c fork_exam_eg.c simple_shell1.c simple_shell2.c sighandler1.c

EXECS     = ${SRC_FILES:.c=}
O_FILES   = $(SRC_FILES:%.c=%.o)

CC        = gcc
CFLAGS    = -Wall -O2
LDFLAGS   = 
LDLIBS    = 

all: $(EXECS)

clean:
	rm -f $(EXECS)
