#ifndef LOGIC_ZONE_H
#define LOGIC_ZONE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

struct zone_hint;

struct logical_zone {
  uint32_t logical_id;
  uint64_t start_address;
  uint64_t capacity;
  int32_t estimated_performance;
  bool sequential_write;
  bool in_space;
};

extern "C" {

uint64_t init_device(const char *filename);

uint64_t allocate_logical_zone(uint64_t prefer_size, logical_zone **lzone);

uint64_t reclaim_logical_zone(uint32_t logical_id, logical_zone *lzone);

int64_t build_linear_space(uint32_t *logical_ids,
                           uint32_t num_zone,
                           uint64_t *offset,
                           uint64_t *space_capacity);

int64_t lswrite(void *buf, uint64_t len, uint64_t offset);

int64_t lsread(void *buf, uint64_t len, uint64_t offset);

int64_t zwrite(void *buf, uint64_t len, uint32_t logical_id);

int64_t zread(void *buf, uint64_t len, uint32_t logical_id);

int64_t zreset(uint32_t logical_id);

int32_t set_hint_func(zone_hint (*funptr)(uint32_t logical_id));

} // extern "C"


#ifdef __cplusplus
}
#endif

#endif /* TEST_LIB */