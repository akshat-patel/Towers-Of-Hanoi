CC:= gcc
CFLAGS:= -Wall -Werror -g

all: testTowers

testTowers: main.c towers.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f testTowers towers.o	