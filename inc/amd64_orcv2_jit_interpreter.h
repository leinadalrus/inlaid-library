#ifndef AMD64_ORCV2_JIT_INTERPRETER_H
#define AMD64_ORCV2_JIT_INTERPRETER_H

#include <stdint.h>

#ifdef AMD64_ORC_JIT_INTERPRETER_H
extern int amd64_orcv2_jit_interpreter_toggle;
#endif

typedef struct MemoryRegion {
  uint8_t memory;
  uint32_t mask;
} MemoryRegion;

typedef struct OrcV2Jit {
} OrcV2Jit;

typedef struct OrcV2JitAdapter {
} OrcV2JitAdapter;

typedef struct OrcV2JitInterpreter {
} OrcV2JitInterpreter;

#endif // !AMD64_ORCV2_JIT_INTERPRETER_H
