#include "../inc/libgxxjit_interpreter.h"
#include "../inc/amd64_command_buffer_handler.h"
#include "../inc/amd64_command_ring_buffer.h"
#include "../inc/components.h"
#include "../inc/coverage_testassert_debug_mod.h"
#include "../inc/handling.h"
#include "../inc/ndebug_testassert_messages.h"
#include "../inc/powerpc_virtual_storage_model.h"
#include <string.h>
// need to have this include file separated
// and outside of include guards
#if __linux__
#include <libgccjit.h>
#endif

#ifdef LIBGXXJIT_INTERPRETER_H
extern int libgxxjit_interpreter_toggle;
#endif

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
  enum RingBufferStatusCodes rb_status_code = 0;

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

int jit_startup_sentinel() {
  switch (libgxxjit_interpreter_toggle) {
  case 0:
    x64v3_jit_runtime_sentinel();
  case 1:
  default:
    break;
  }

  return 0;
}

LibGxxJitInterpreter *
initialise_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {
  const char buffer[254];
  LibGxxDataBundle *data_bundle =
      memset(interpreter, (int)buffer[254],
             sizeof(LibGxxDataBundle)); // root table data
  MemoryRegion *memory_locale =
      memcpy(data_bundle, interpreter,
             sizeof(ArenaState)); // restricted table data
  ArenaState *memory_state =
      memcpy(data_bundle, memory_locale, (size_t)buffer); // mutable table data

  uint8_t destination = (uint8_t)memory_state->arena_data.destination;
  // arena_data->destination is mutable:
  destination = destination >> memory_locale->memory;
  // arena_data->table_data is the bitmask for bit-ops
  uint32_t table = (uint32_t)memory_state->arena_data.table_data;
  table = table >> memory_locale->mask;

  return interpreter;
}

void deinitialise_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  interpreter = initialise_external_jit_interpreter(interpreter);
  LibGxxRegionBundle *bundled_region = NULL;
  LibGxxJitInterpreter *new_interpreter =
      memset(interpreter, bundled_region->memory_region->memory,
             sizeof(LibGxxJitInterpreter));
  interpreter = new_interpreter;
}

void reset_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  jit_startup_sentinel();
}

void start_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {}

void stop_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {}
