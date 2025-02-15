CC=gcc
CFLAGS=-Wall

all: lru_cache

lru_cache: main.c lru_cache.c
	$(CC) $(CFLAGS) main.c lru_cache.c -o lru_cache

clean:
	rm -f lru_cache
