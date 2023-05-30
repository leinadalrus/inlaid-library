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
