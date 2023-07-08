#if _WIN32 || __linux__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#endif

#if _WIN32
#include <C:/raylib/raylib/src/raylib.h>
#endif

#if __linux__
#include <raylib.h>
#endif

#include "../inc/coverage_testassert_module.h"
#include "../inc/current_process_modal_registry.h"

class SelectiveGridmapMatrix {
public:
};

class IntermediateCommand {
public:
  void execute_intermediate_command();
};

class AttachAttackInputHandle : public IntermediateCommand {};

class AttachDelayInputHandle : public IntermediateCommand {};

class AttachSustainInputHandle : public IntermediateCommand {};

class AttachReleaseInputHandle : public IntermediateCommand {};

class AttachSignalTransgressionHandler {
  AttachAttackInputHandle *attack_attachment;
  AttachDelayInputHandle *delay_attachment;
  AttachSustainInputHandle *sustain_attachment;
  AttachReleaseInputHandle *release_attachment;

public:
};

class OpaqueAimAssist {
  SelectiveGridmapMatrix selective_gridmap_matrix;
  AttachSignalTransgressionHandler signal_transgression_handler;
};

class PlayerEntity {};

class PlayerPosition {
public:
  Vector2 position;
};

class PlayerBundle {
public:
  PlayerEntity entity;
  PlayerPosition position;
};

PlayerEntity *designate_player_entity_scalar(PlayerEntity player_instance) {
  // TODO: move player_entity data into a new ServiceLocator function

  PlayerEntity *new_player = &player_instance;

  return new_player; // return address of stack memory associated with local
                     // variable
}

PlayerBundle *init_player_bundle_instance(PlayerBundle *bundle_instance,
                                          PlayerEntity player_instance) {
  bundle_instance->entity = *designate_player_entity_scalar(
      player_instance); // pointer-to-address because
                        // of address of stack memory
  bundle_instance->position.position.x = GetScreenWidth() / 2.f;
  bundle_instance->position.position.y = GetScreenHeight() / 2.f;

  memmove(bundle_instance, bundle_instance,
          sizeof(&bundle_instance)); // the memory in memmove can overlap,
                                     // whereeas memcpy cannot or it will cause
                                     // undefined behavior

  return bundle_instance; // may need memcpy and memmove
}

int process_world_relative_terrain() {
  enum WorldTerrains { CHECKERED_TEXTURE, STRIPED_TEXTURE };
  enum WorldTerrains terrain;

  switch (terrain) {
  case 0:
    terrain = CHECKERED_TEXTURE;
  case 1:
  default:
    terrain = STRIPED_TEXTURE;
  }

  int textures_matrices[8][8]; // match the 32-bit register

  for (int i = 0; i < GetScreenWidth(); i++) {
    for (int j = 0; j < GetScreenHeight(); j++) {
      textures_matrices[i][j] = STRIPED_TEXTURE; // match the 32-bit register
    }
  }

  return 0;
}

struct FrameData {
  int current_frame;
  int frame_count;
  int frame_speed;
};

int MINIMAL_TESTS_RUN = 0;
char *test_frame_data() {
  struct FrameData frame_data;
  std::string message = "error, current_frame != 0";
  char *converted_message = new char[message.length() + 1];
  // don't use std::strcpy, use std::memcpy instead.
  std::memcpy(converted_message, message.c_str(), sizeof(&converted_message));
  MINIMAL_UNIT_ASSERT(converted_message, frame_data.current_frame == 0);
  return 0;
} // std::string to char*, https://stackoverflow.com/a/7352131.

char *run_tests() {
  MINIMAL_RUN_TEST(test_frame_data);
  return 0;
}

int main() {
  InitWindow(640, 400, "Slow Dive. Slow Crush.");

  struct FrameData frame_data; // have this value in the "stack-space"

  int current_frame = 0;
  int frame_count = 0;
  int frame_speed = 8;

  frame_data.current_frame = current_frame;
  frame_data.frame_count = frame_count;
  frame_data.frame_speed = frame_speed;

  const int max_frame_speed = 16;
  const int min_frame_speed = 1;

  struct PlayerEntity *player_instance;

  struct PlayerBundle player_bundle;
  struct PlayerBundle bundle_instance;

  PlayerBundle *player =
      init_player_bundle_instance(&bundle_instance, *player_instance);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    frame_count++;
    // TODO(Daniel): change all this into a Strategy design pattern
    if (frame_count >= (60 / frame_speed)) {
      frame_count = 0;
      current_frame++;
      if (current_frame > 4)
        current_frame = 0;
    }

#ifndef LocalDirections
    // Pre-processor boolean statement for enum declaration protection
    enum LocalDirections { UP, DOWN, LEFT, RIGHT };
#endif
    enum LocalDirections directions;

    for (int x = 0; x < 8; x++) {
      player->position.position.x = x;
      for (int y = 0; y < 8; y++) {
        player->position.position.y = y;

        switch (directions) {
        case UP:
          if (IsKeyPressed(KEY_W))
            frame_speed++; // do an opposing velocity check
          else if (IsKeyPressed(KEY_S))
            frame_speed--; // and then frame_speed++
          //
        case DOWN:
          if (IsKeyPressed(KEY_S))
            frame_speed++; // do an opposing velocity check
          else if (IsKeyPressed(KEY_W))
            frame_speed--; // and then frame_speed++
          //
        case LEFT:
          if (IsKeyPressed(KEY_A))
            frame_speed++; // do an opposing velocity check
          else if (IsKeyPressed(KEY_D))
            frame_speed--; // and then frame_speed++
          //
        case RIGHT:
          if (IsKeyPressed(KEY_D))
            frame_speed++; // do an opposing velocity check
          else if (IsKeyPressed(KEY_A))
            frame_speed--; // and then frame_speed++

        default:
          if (frame_speed > max_frame_speed)
            frame_speed = max_frame_speed;
          else if (frame_speed < min_frame_speed)
            frame_speed = min_frame_speed;
        }
      }
    }

    EndDrawing();
  }

  for (int i = 0; i < sizeof(bundle_instance); ++i) {
    free(player); // free called on unallocated object
    // free and annul all player resources
  }

  // finally close the window instance
  CloseWindow();

  return 0;
}
