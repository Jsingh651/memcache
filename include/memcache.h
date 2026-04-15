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
    size_t value_len;
    time_t accessed;
    struct mc_entry *next;
} mc_entry_t;

typedef struct mc_hash {
    mc_entry_t **buckets;
    size_t capacity;
    size_t count;
} mc_hash_t;

typedef struct mc_stats {
    uint64_t gets, sets, deletes, hits, misses, evictions;
} mc_stats_t;

typedef struct mc_config {
    int port;
    size_t max_entries;
    int verbose;
} mc_config_t;

typedef struct mc_server {
    int listen_fd;
    mc_hash_t store;
    mc_stats_t stats;
    mc_config_t config;
} mc_server_t;

