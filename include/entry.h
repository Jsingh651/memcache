#include "memcache.h"
mc_entry_t *mc_entry_create(const char *key, const char *value);
void mc_entry_destroy(mc_entry_t *e);
