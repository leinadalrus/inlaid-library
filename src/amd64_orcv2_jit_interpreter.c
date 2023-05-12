#include "../inc/amd64_orcv2_jit_interpreter.h"

void load_maked_coreboot_bios() {}

int get_orcv2_memory_region(uint32_t address, int is_written,
                            MemoryRegion *memory_region) {
  return 0;
}

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address) {
  return 0;
}

uint64_t get_internal_system_clock_cycles(int n_cycles) { return 0; }

uint64_t set_orcv2_memory_region_timings(uint32_t starting_address,
                                         uint32_t ending_address,
                                         uint32_t memory_region, int bus_width,
                                         int non_sequential, int sequential) {
  return 0;
}

void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address) {}

int orcv2_jit_startup_sentinel() {
  switch(amd64_orcv2_jit_interpreter_toggle) {
    case 0:
    case 1:
    default:
    break;
  }
}

int initialise_external_jit_interpreter(OrcV2JitInterpreter *interpreter) {
  OrcV2DataBundle *orcv2_data_bundle;
  ArenaBundle *arena_bundle;
  MemoryRegion *memory_region;

  // arena_data->destination is mutable:
  arena_bundle->arena_data->destination = memory_region->memory;
  // arena_data->table_data is the bitmask for bit-ops
  arena_bundle-arena_data->table_data = memory_region->mask;

  return 0;
}

void deinitialise_external_jit_interpreter(OrcV2JitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  OrcV2JitInterpreter new_interpreter = OrcV2JitInterpreter{};
  interpreter = new_interpreter;
}

void reset_external_jit_interpreter(OrcV2JitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  orcv2_jit_startup_sentinel();
}

void start_external_jit_interpreter(OrcV2JitInterpreter *interpreter) {

}

void stop_external_jit_interpreter(OrcV2JitInterpreter *interpreter) {}
