# MemCache

High-performance in-memory key-value store with TCP protocol, LRU eviction, and statistics tracking. Written in C11.

## Features

- GET, SET, DELETE, STATS commands
- Hash table with chaining
- LRU eviction when memory limit reached
- Connection handling with select()
- Built-in stats and logging

## Build & Run

```bash
make
./memcache --port 7379
```

## Protocol

```
SET key value
GET key
DEL key
STATS
QUIT
```

