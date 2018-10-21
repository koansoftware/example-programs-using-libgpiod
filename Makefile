CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -g
LDFLAGS = -lgpiod

EXE =                  \
  read-gpio            \
  toggle-gpio          \
  monitor-gpio         \


.PHONY: all

all:$(EXE)


.PHONY: clean

clean:
	rm -f $(EXE) *.o


