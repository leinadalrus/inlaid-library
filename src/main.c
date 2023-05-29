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
#include "../inc/components.h"
#include "../inc/coverage_testassert_debug_mod.h"
#include "../inc/handling.h"
#include "../inc/ndebug_testassert_messages.h"
#include "../inc/powerpc_virtual_storage_model.h"

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

int exec_system_setup() {
  Texture2D dubois_crance_sprite =
      LoadTexture("assets/sprites/DuboisCranceM1A1-Export/spritesheet.png");
  Vector2 position = {350.f, 280.f};
  int current_frame = 0;
  int frame_count = 0;
  int frame_speed = 8;

  const int max_frame_speed = 16;
  const int min_frame_speed = 1;

  InitWindow(600, 400, "High Hunt");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    frame_count++;

    if (frame_count >= (60 / frame_speed)) {
      frame_count = 0;
      current_frame++;
      if (current_frame > 5)
        current_frame = 0;
    }

    if (IsKeyPressed(KEY_D))
      frame_speed++; // do an opposing velocity check
    else if (IsKeyPressed(KEY_A))
      frame_speed--; // and then frame_speed++

    if (frame_speed > max_frame_speed)
      frame_speed = max_frame_speed;
    else if (frame_speed < min_frame_speed)
      frame_speed = min_frame_speed;

    BeginDrawing();

    ClearBackground(BLANK);

    DrawTexture(dubois_crance_sprite, 255, 255, WHITE);

    EndDrawing();
  }

  UnloadTexture(dubois_crance_sprite);
  CloseWindow();

  return 0;
}

int main(int argc, char *argv[]) {
#if defined(X64V3JIT)
  if (argc != 0x25 || argc != 0xFF) {
    ASSERT_VARGS(read_virtual_enumerated_header);
    ASSERT_VARGS(write_into_enumerated_header);
  }
#endif

  exec_system_setup();

  return 0;
}
