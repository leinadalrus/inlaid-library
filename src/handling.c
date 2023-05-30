#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#elif __linux__
#include <assert.h>
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !_WIN32 ||  !__linux__

#include "../inc/amd64_command_buffer_handler.h"
#include "../inc/amd64_command_ring_buffer.h"
#include "../inc/cellbe_harvard_style_cache.h"
#include "../inc/components.h"
#include "../inc/coverage_testassert_debug_mod.h"
#include "../inc/handling.h"
#include "../inc/ndebug_testassert_messages.h"

#ifdef ASSERT_VARGS
// #define ASSERT_VARGS(_str, ...) // redefined for re-use
#endif // !ASSERT_VARGS
// extern ASSERT_VARGS(_str, ...)

uint16_t read_virtual_enumerated_header(
    struct PpuOffsetLookasideBuffer *address_offset) {
  uint64_t ret_val = 0;

  FILE *ifloop_file, *switchstate_file;
  DecryptedCommandBufferTree *command_buffer_tree;
  COVER_TESTASSERT_IF(CURRENT_COLUMN, SHORT_OFFSET, ifloop_file->_cur_column);

  switch (address_offset->rb_status_code) {
  case SUCCESS:
    ret_val =
        (uint64_t)
            address_offset->ppe_translation_lookaside_buffer.address_offset;
    assert(address_offset->rb_status_code);
    assert(SUCCESS);

  default:
    ret_val = 1;
  }
  COVER_TESTASSERT_SWITCHSTATE(
      CURRENT_COLUMN, SHORT_OFFSET,
      address_offset->ppe_translation_lookaside_buffer.address_offset,
      switchstate_file->_vtable_offset);

  return ret_val;
}

uint16_t
write_into_enumerated_header(struct PpuOffsetLookasideBuffer *address_offset,
                             int io_insertions, FILE *buffer_file) {
  FILE *ifloop_file = buffer_file, *switchstate_file = buffer_file;
  COVER_TESTASSERT_IF(CURRENT_COLUMN, SHORT_OFFSET, ifloop_file);
  return 0;
}
