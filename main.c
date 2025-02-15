#include <stdio.h>
#include "lru_cache.h"

int main() {
    LRUCache* cache = createCache(3);

    put(cache, 1, 10);
    put(cache, 2, 20);
    put(cache, 3, 30);
    printCache(cache);

    get(cache, 1);
    printCache(cache);

    put(cache, 4, 40);
    printCache(cache);

    freeCache(cache);
    return 0;
}
