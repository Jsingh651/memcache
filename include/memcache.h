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

int mc_hash_init(mc_hash_t *h, size_t capacity);
void mc_hash_free(mc_hash_t *h);
int mc_hash_set(mc_hash_t *h, const char *key, const char *value, mc_stats_t *stats);
const char *mc_hash_get(mc_hash_t *h, const char *key, mc_stats_t *stats);
int mc_hash_del(mc_hash_t *h, const char *key, mc_stats_t *stats);
void mc_hash_evict_lru(mc_hash_t *h, mc_stats_t *stats);

int mc_server_init(mc_server_t *s, const mc_config_t *cfg);
void mc_server_run(mc_server_t *s);
void mc_server_shutdown(mc_server_t *s);

int mc_parse_command(const char *line, char *cmd, char *key, char *value);
void mc_log(int level, const char *fmt, ...);

#endif
