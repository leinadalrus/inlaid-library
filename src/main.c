#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <io.h> // equivalent to <unistd.h>
#elif __linux__
#include <raylib.h>
#include <unistd.h> // equivalent to <io.h>
#endif

#if _WIN32 || __linux__
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "../inc/current_process_modal_registry.h"
#include "../inc/game_actor_entity.h"
#include "../inc/prototype_builder.h"

int annul_player_service_location(
    PlayerServiceLocator *player_service_locator) {
  free(player_service_locator);
  player_service_locator = NULL;
  return 0;
}

EntityPrototype init_prototype_via_execution(EntityPrototype prototype,
                                             InputCommand command) {
  return prototype;
}

PrototypeBuilder create_handler_for_prototype(PrototypeBuilder builder,
                                              InputHandler handler) {
  return builder;
} // TODO(Daniel): code ...

void execute_actor_prototype(InputCommand *command, PlayerEntity *player) {}

int check_init_player_instance(PlayerServiceLocator *service_instance) {
  struct PlayerEntity {
    PlayerServiceLocator player_service_locator;
  } player_entity = {
      .player_service_locator = service_instance,
  };

  return 0;
}

struct PlayerEntity *designate_entity_scalar(PlayerEntity player_instance) {
  PlayerServiceLocator *player_service_locator;
  // TODO: move player_entity data into a new ServiceLocator function

  PlayerEntity *new_player = &player_instance;
  new_player->player_service_locator = player_service_locator;

  return new_player; // return address of stack memory associated with local
                     // variable
}

int annul_player_entity_instance(PlayerEntity *player_entity) {
  free(player_entity);
  player_entity = NULL;
  return 0;
}

int (*on_notice)(const PlayerEntity entity, enum ArmRegisters registry);

PlayerBundle *init_player_bundle_instance(PlayerBundle *bundle_instance,
                                          PlayerEntity player_instance) {
  bundle_instance->entity =
      *designate_entity_scalar(player_instance); // pointer-to-address because
                                                 // of address of stack memory
  bundle_instance->position.position.x = GetScreenWidth() / 2.f;
  bundle_instance->position.position.y = GetScreenHeight() / 2.f;
  bundle_instance->health.health = 100;
  bundle_instance->sprite =
      LoadTexture("../assets/sprites/player-export/spritesheet.png");

  bundle_instance =
      malloc(sizeof(struct PlayerBundle)); // give stack-based address and size

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

int main() {
  InitWindow(WINDOW_SCREEN_SIZE_WIDTH, WINDOW_SCREEN_SIZE_HEIGHT,
             WINDOW_APPLICATION_TITLE);

  int current_frame = 0;
  int frame_count = 0;
  int frame_speed = 8;

  const int max_frame_speed = 16;
  const int min_frame_speed = 1;

  PlayerServiceLocator *service_instance;

  struct PlayerEntity *player_instance;
  player_instance->player_service_locator = service_instance;

  struct PlayerBundle player_bundle;
  struct PlayerBundle *bundle_instance = memset(
      &player_bundle, 0x0000,
      sizeof(
          player_bundle)); // memset sets all pieces of memory to the same value

  PlayerBundle *player =
      init_player_bundle_instance(bundle_instance, *player_instance);

  SetTargetFPS(FPS_SET_TARGET);

  while (!WindowShouldClose()) {
    frame_count++;
    // TODO(Daniel): change all this into a Strategy design pattern
    if (frame_count >= (FPS_SET_TARGET / frame_speed)) {
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

    DrawTexture(
        player->sprite, (256 / 32), (256 / 32),
        WHITE); // (256/32) 8-bit sprite conversion, to match display of a GBA

    EndDrawing();
  }

  for (int i = 0; i < sizeof(*bundle_instance); ++i) {
    free(player); // free called on unallocated object
    // free and annul all player resources
    annul_player_entity_instance(player_instance);
    annul_player_service_location(service_instance);
  }

  annul_player_service_location(player->entity.player_service_locator);
  annul_player_entity_instance(&player->entity);
  UnloadTexture(player->sprite);
  // finally close the window instance
  CloseWindow();

  return 0;
}
