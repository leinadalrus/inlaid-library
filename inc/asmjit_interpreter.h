#ifndef ASMJIT_INTERPRETER_H
#define ASMJIT_INTERPRETER_H

#include "function_offload_model_hook.h"
#include "function_offload_phantom_marker.h"
#include <stdint.h>

#ifdef ASMJIT_INTERPRETER_H
extern int asmjit_interpreter_toggle;
#endif

typedef struct MemoryRegion {
  uint8_t memory;
  uint32_t mask;
} MemoryRegion;

typedef struct X64V3InternalClock {
  uint32_t processing_unit_clock_address;
} X64V3InternalClock;

typedef struct X64V3RegionBundle {
  MemoryRegion *memory_region;
  X64V3InternalClock x64v3_internal_clock;
} X64V3RegionBundle;

void load_maked_coreboot_bios(int(*unix_nan_boxing));
int get_x64v3_memory_region(uint32_t address, int is_written,
                            MemoryRegion *memory_region);

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address);
uint64_t get_internal_system_clock_cycles(int n_cycles);
uint64_t set_x64v3_memory_region_timings(uint32_t starting_address,
                                         uint32_t ending_address,
                                         uint32_t memory_region, int bus_width,
                                         int non_sequential, int sequential);
void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address);

typedef struct X64V3Jit {
} X64V3Jit;

typedef struct X64V3JitAdapter {
} X64V3JitAdapter;

typedef struct X64V3JitInterpreter {
  FunctionOffloadPhantomMarker *phantom_marker;
} X64V3JitInterpreter;

typedef struct X64V3DataBundle {
  X64V3Jit *jit;
  X64V3JitAdapter *adapter;
  X64V3JitInterpreter *interpreter;
} X64V3DataBundle;

int x64v3_jit_startup_sentinel();

X64V3JitInterpreter *
initialise_external_jit_interpreter(X64V3JitInterpreter *interpreter);
void deinitialise_external_jit_interpreter(X64V3JitInterpreter *interpreter);
void reset_external_jit_interpreter(X64V3JitInterpreter *interpreter);
void start_external_jit_interpreter(X64V3JitInterpreter *interpreter);
void stop_external_jit_interpreter(X64V3JitInterpreter *interpreter);

#endif // !ASMJIT_INTERPRETER_H
