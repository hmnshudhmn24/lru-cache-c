#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#define CACHE_SIZE 3

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

typedef struct {
    int capacity, count;
    Node *head, *tail;
    Node *hash_map[CACHE_SIZE];
} LRUCache;

LRUCache* createCache(int capacity);
int get(LRUCache* cache, int key);
void put(LRUCache* cache, int key, int value);
void printCache(LRUCache* cache);
void freeCache(LRUCache* cache);

#endif
