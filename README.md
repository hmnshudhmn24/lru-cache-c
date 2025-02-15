# LRU Cache Implementation in C

## Description
A simple **Least Recently Used (LRU) Cache** implementation in C using **Doubly Linked List** and **Hash Table**.

## Features
- Uses **hashing** for O(1) lookup time.
- Implements **doubly linked list** for tracking usage order.
- Supports **get(key)** and **put(key, value)** in **O(1)** time.
- Automatically removes **Least Recently Used (LRU) item** when full.

## Files
- `lru_cache.h` - Header file with struct and function declarations.
- `lru_cache.c` - Core LRU logic.
- `main.c` - Example usage.
- `Makefile` - Compile & run with `make`.

## Usage
```sh
make
./lru_cache
```

## Example Output
```
Cache State: (3, 30) (2, 20) (1, 10) 
Cache State: (1, 10) (3, 30) (2, 20) 
Cache State: (4, 40) (1, 10) (3, 30) 
```

## License
MIT License
