#include "function_offload_model_hook.h"
#include "ndebug_testassert_messages.h"

#ifndef LIBGXXJIT_BUILDMODULE_H
#define LIBGXXJIT_BUILDMODULE_H

#ifdef __linux__
#include <err.h>
#include <errno.h>
#include <gelf.h>
#endif

extern "C" const char *PpuEntries[]; // SPU into PPU Entry Codes
extern "C" const char *SpuEntries[]; // SPU from PPU Entry Codes

inline const uint16_t fetch_entrylist_opcode(intptr_t *opcode_ptr) {
  uint16_t opcode = (uint16_t)opcode_ptr[0];

  if (opcode >= 0xe800)
    opcode = (opcode << 16) | (uint16_t)opcode_ptr[2];

  return opcode;
}

#endif // !LIBGXXJIT_BUILDMODULE_H
