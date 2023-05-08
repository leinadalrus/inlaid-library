#include "../inc/amd_command_buffer_handler.h"
#include "../inc/amd_command_ring_buffer.h"
#include "../inc/memory_flow_controller_command.h"
#include "../inc/powerpc_virtual_storage_model.h"

typedef struct ArenaData {
} ArenaData; // NOTE TODO Arrays-of-Structs

typedef struct ArenaState {
  ArenaData *arena_data;
} ArenaState;

const int *walk_into_arena_allocated_trees(ArenaState arena_state,
                                           void *destination, void *source,
                                           uint16_t data_size) {
  return 0;
}
