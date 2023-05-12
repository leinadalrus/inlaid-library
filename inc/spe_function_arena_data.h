#include <stdint.h>

typedef struct ArenaData {
  void *destination, *source, *table_data;
  uint16_t data_size;
} ArenaData;

typedef struct ArenaState {
  ArenaData arena_data;
} ArenaState;
