#include "../inc/amd64_comptime_interpreter.h"
#include "../inc/amd64_command_ring_buffer.h"
#include "../inc/amd64_mailbox_protocol_handler.h"
// #include "../inc/amd_command_buffer_handler.h"
// #include "../inc/powerpc_virtual_storage_model.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int *arena_alloc_cacheblock_token(ArenaState arena_state) { return 0; }

const int *parse_cacheblock_token(Amd64Interpreter *interpreter) {
  interpreter = malloc(sizeof(char));

  free(interpreter);

  return 0;
}
