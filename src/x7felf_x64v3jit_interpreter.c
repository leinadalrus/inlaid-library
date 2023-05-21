#include "../inc/x7felf_x64v3jit_interpreter.h"
#include "../inc/amd64_command_ring_buffer.h"
// need to have this include file separated
// and outside of include guards

#ifndef X7FELF_X64V3JIT_INTERPRETER_H
extern int x7felf_x64v3jit_interpreter_toggle;
#endif

#include <assert.h>
#include <memory.h>
#include <stdint.h>
#include <string.h>

void load_maked_coreboot_bios(int(*unix_nan_boxing)) {
  switch (*unix_nan_boxing) {
  default:
    break;
  }
}

int get_x64v3_memory_region(uint32_t address, int is_written,
                            MemoryRegion *memory_region) {
  return 0;
}

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address) {
  return 0;
}

uint64_t get_internal_system_clock_cycles(int n_cycles) { return 0; }

uint64_t set_x64v3_memory_region_timings(uint32_t starting_address,
                                         uint32_t ending_address,
                                         uint32_t memory_region, int bus_width,
                                         int non_sequential, int sequential) {
  return 0;
}

void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address) {}

int x64v3_jit_runtime_sentinel() {
  enum RingBufferStatusCodes rb_status_code;

  switch (rb_status_code) {
  case INVALID_ADDRESS:
  case INVALID_ASID:
  case INVALID_CERTIFICATE:
  case INVALID_COMMAND:
  case INVALID_CONFIG:
  case INVALID_LENGTH:
  case INVALID_PARAM:
  case INVALID_PLATFORM_STATE:
  default:
    break;
  }

  return 0;
}

int x64v3_jit_startup_sentinel() {
  switch (x7felf_x64v3jit_interpreter_toggle) {
  case 0:
    x64v3_jit_runtime_sentinel();
  case 1:
  default:
    break;
  }

  return 0;
}

X64V3JitInterpreter *
initialise_external_jit_interpreter(X64V3JitInterpreter *interpreter) {
  X64V3DataBundle *x64v3_data_bundle;
  ArenaState *arena_state;
  MemoryRegion *memory_region;

  uint8_t destination = (uint8_t)arena_state->arena_data.destination;
  // arena_data->destination is mutable:
  destination = destination >> memory_region->memory;
  // arena_data->table_data is the bitmask for bit-ops
  uint32_t table = (uint32_t)arena_state->arena_data.table_data;
  table = table >> memory_region->mask;

  return interpreter;
}

void deinitialise_external_jit_interpreter(X64V3JitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  interpreter = initialise_external_jit_interpreter(interpreter);
  X64V3RegionBundle *x64v3_region;
  X64V3JitInterpreter *new_interpreter =
      memset(interpreter, x64v3_region->memory_region->memory,
             sizeof(X64V3JitInterpreter));
  interpreter = new_interpreter;
}

void reset_external_jit_interpreter(X64V3JitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  x64v3_jit_startup_sentinel();
}

void start_external_jit_interpreter(X64V3JitInterpreter *interpreter) {}

void stop_external_jit_interpreter(X64V3JitInterpreter *interpreter) {}
