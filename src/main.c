#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#include <assert.h>
#include <fcntl.h>
#include <memory.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#if _WIN32
#include "C:\\raylib\\raylib\\src\\raylib.h"
#elif __linux__
#include <raylib.h>
#endif // !_WIN32 || !__linux__

#include "../inc/amd64_command_buffer_handler.h"
#include "../inc/amd64_command_ring_buffer.h"
#include "../inc/coverage_testassert_debug_mod.h"
#include "../inc/ndebug_testassert_messages.h"
#include "../inc/powerpc_virtual_storage_model.h"

#ifdef ASSERT_VARGS
#define ASSERT_VARGS(_str, ...) // redefined for re-use
#endif                          // !ASSERT_VARGS
// extern ASSERT_VARGS(_str, ...)

#define __iomem                                                                \
  __attribute__((                                                              \
      noderef,                                                                 \
      address_space(2))) // temporary definition of __iomem from sparse

uint16_t read_virtual_enumerated_header(
    struct PpuOffsetLookasideBuffer *address_offset) {
  int is_enabled = 0; // = dev_info->virtual_device_data->destination & BIT(0);
  uint64_t ret_val = 0;
  const char *restrict memio_buffer;

  FILE *ifloop_file, *switchstate_file;
  DecryptedCommandBufferTree *command_buffer_tree;

  if (is_enabled == 0) {
    fprintf(stderr, "Devisor is disabled!\n");
    ret_val = 0;
  }
  COVER_TESTASSERT_IF(0, is_enabled, memio_buffer, ifloop_file);

  switch (address_offset->rb_status_code) {
  case SUCCESS:
  case INVALID_LENGTH:
  case INACTIVE:
    ret_val =
        (uint64_t)
            address_offset->ppe_translation_lookaside_buffer.address_offset;

  default:
    ret_val = 1;
  }
  COVER_TESTASSERT_ANYOPAQUE(SUCCESS, address_offset->rb_status_code,
                             memio_buffer, switchstate_file);

  return ret_val;
}

uint16_t
write_into_enumerated_header(struct PpuOffsetLookasideBuffer *address_offset,
                             const char *restrict memio_buffer,
                             FILE *buffer_file) {
  FILE *ifloop_file = buffer_file, *switchstate_file = buffer_file;
  COVER_TESTASSERT_IF(0, is_enabled, memio_buffer, ifloop_file);
  COVER_TESTASSERT_ANYOPAQUE(SUCCESS, address_offset->rb_status_code,
                             memio_buffer, switchstate_file);
  return 0;
}

int main(int argc, char *argv[]) {
#if defined(X64V3JIT)
  if (argc != 0x25 || argc != 0xFF) {
    ASSERT_VARGS(read_virtual_enumerated_header);
    ASSERT_VARGS(write_into_enumerated_header);
  }
#endif

  InitWindow(600, 400, "Inlaid Library");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLANK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
