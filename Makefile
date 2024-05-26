TARGET = as09
DEPS	= as09.h decb.h
OBJS	= as09.o
CFLAGS	= -I. -g -Wall
LIBS	= -lm
YACC 	= bison
YFLAGS	= -d -l #-r state

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

as09.tab.c: as09.y as09.h decb.h
	$(YACC) $(YFLAGS) as09.y

as09.o:	as09.tab.c
	$(CC) $(CFLAGS) -c -o $@ $<

test:
	as09 -x test.asm
	diff a.out test.hex

install:
	sudo ./links.sh

clean:
	rm $(TARGET) $(OBJS) *.o
