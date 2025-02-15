#include <stdio.h>
#include <stdlib.h>
#include "lru_cache.h"

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

LRUCache* createCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->count = 0;
    cache->head = cache->tail = NULL;
    for (int i = 0; i < CACHE_SIZE; i++)
        cache->hash_map[i] = NULL;
    return cache;
}

void moveToHead(LRUCache* cache, Node* node) {
    if (cache->head == node) return;
    
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (cache->tail == node) cache->tail = node->prev;
    
    node->next = cache->head;
    node->prev = NULL;

    if (cache->head) cache->head->prev = node;
    cache->head = node;

    if (cache->tail == NULL) cache->tail = node;
}

int get(LRUCache* cache, int key) {
    int index = key % CACHE_SIZE;
    Node* node = cache->hash_map[index];

    if (node && node->key == key) {
        moveToHead(cache, node);
        return node->value;
    }
    return -1;
}

void put(LRUCache* cache, int key, int value) {
    int index = key % CACHE_SIZE;
    Node* node = cache->hash_map[index];

    if (node && node->key == key) {
        node->value = value;
        moveToHead(cache, node);
        return;
    }

    Node* newNode = createNode(key, value);
    cache->hash_map[index] = newNode;

    if (cache->count < cache->capacity) {
        cache->count++;
    } else {
        Node* toRemove = cache->tail;
        int removeIndex = toRemove->key % CACHE_SIZE;
        cache->hash_map[removeIndex] = NULL;

        cache->tail = cache->tail->prev;
        if (cache->tail) cache->tail->next = NULL;

        free(toRemove);
    }

    newNode->next = cache->head;
    if (cache->head) cache->head->prev = newNode;
    cache->head = newNode;

    if (cache->tail == NULL) cache->tail = newNode;
}

void printCache(LRUCache* cache) {
    Node* temp = cache->head;
    printf("Cache State: ");
    while (temp) {
        printf("(%d, %d) ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("
");
}

void freeCache(LRUCache* cache) {
    Node* temp = cache->head;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(cache);
}
