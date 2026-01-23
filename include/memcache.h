#ifndef MEMCACHE_H
#define MEMCACHE_H
#include <stddef.h>
#include <stdint.h>
#include <time.h>

#define MC_MAX_KEY 256
#define MC_MAX_VALUE 4096
#define MC_DEFAULT_PORT 7379
#define MC_DEFAULT_MAX_ENTRIES 10000

typedef struct mc_entry {
    char *key;
    char *value;
