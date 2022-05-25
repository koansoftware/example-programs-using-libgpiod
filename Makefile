# Tested with cross-compiler

LDFLAGS = -lgpiod

EXE =                   \
  read-gpio             \
  toggle-gpio           \
  monitor-gpio          \
  list-gpio-lines       \
  invert-gpio           \
  wait-gpio-event       \
  ctxless-toggle-gpio   \
  low-level-toogle-gpio \


.PHONY: all

all:$(EXE)

.PHONY: clean

clean:
	rm -f $(EXE) *.o

