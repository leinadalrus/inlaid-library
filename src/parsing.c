#include "../inc/amd_command_ring_buffer.h"
// #include "../inc/amd_command_buffer_handler.h"
// #include "../inc/powerpc_virtual_storage_model.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Amd64GuestPolicy { NODBG = 0x0000 };

typedef struct ArenaData {
} ArenaData; // NOTE TODO Arrays-of-Structs

typedef struct ArenaState {
  enum Amd64GuestPolicy guest_policy;
  ArenaData *arena_data;
} ArenaState;

typedef struct Amd64Interpreter {
  enum Amd64GuestPolicy guest_policy;
} Amd64Interpreter;

typedef struct Amd64Recompiler {
} Amd64Recompiler;

const int *arena_alloc_cacheblock_token(ArenaState arena_state) { return 0; }

const int *parse_cacheblock_token(Amd64Interpreter *interpreter) {
  interpreter = malloc(sizeof(char));

  free(interpreter);

  return 0;
}
