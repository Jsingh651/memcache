CC = cc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRCS = src/main.c src/server.c src/hash.c src/entry.c src/protocol.c src/commands.c src/memory.c src/stats.c src/config.c src/log.c
OBJS = $(SRCS:.c=.o)
TARGET = memcache

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c include/memcache.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

test: $(TARGET)
	./tests/run_tests.sh

.PHONY: all clean test
