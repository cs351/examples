SRC_FILES = $(wildcard *.c)

EXECS     = $(SRC_FILES:.c=)
O_FILES   = $(SRC_FILES:%.c=%.o)

CC        = gcc
CFLAGS    = 
LDFLAGS   = 
LDLIBS    = -lm

all: $(EXECS)

clean:
	rm -f $(EXECS)
