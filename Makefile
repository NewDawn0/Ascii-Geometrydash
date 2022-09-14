CC = gcc
CFLAGS = -Wall -g -lncurses
OBJS = dash.c
OUTFILE = dash

all: compile

compile: $(OBJS)
	@echo "Compiling file..."
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)

test:
	@echo "Running file"
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)
	./dash

clean:
	@echo "Cleaning up..."
	rm -rf *.o *.dSYM
