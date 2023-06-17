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

#define WINDOW_SCREEN_SIZE_WIDTH 600
#define WINDOW_SCREEN_SIZE_HEIGHT 480
#define WINDOW_APPLICATION_TITLE "Pfks!AnamNemesis!"
// FPS is defined as so to be base-10:
#define FPS_SET_TARGET 60
// FPS target is 10, but -2 for 8 to reflect spritesheet animation indices
// +2 additional frames for collision and invincibility

#ifndef GAME_ACTOR_ENTITY_H
#define GAME_ACTOR_ENTITY_H

typedef struct Collision {
  Rectangle hitbox;
} Collision;

typedef struct Position {
  Vector2 position;
} Position;

typedef struct Health {
  uint8_t health;
} Health;

typedef struct PlayerServiceLocator {
  void *destination, *source, *data;
  uint16_t size;
} PlayerServiceLocator; // TODO: turn into a temporary address array system

typedef struct PlayerServiceAvails {
  PlayerServiceLocator *live_services;
} PlayerServiceAvails;

typedef struct AnnulPlayerService {
  PlayerServiceLocator *player_service_locator;
} AnnulPlayerService;

int annul_player_service_location(
    PlayerServiceLocator *player_service_locator) {
  free(player_service_locator);
  player_service_locator = NULL;
  return 0;
}

typedef struct PlayerEntity {
  PlayerServiceLocator *player_service_locator;
} PlayerEntity;

typedef struct InputCommand {
  void *(command);
} InputCommand;

void execute_command(InputCommand command);

typedef struct AttackCommand {
  InputCommand *command;
} AttackCommand;

typedef struct DelayCommand {
  InputCommand *command;
} DelayCommand;

typedef struct SustainCommand {
  InputCommand *command;
} SustainCommand;

typedef struct ReleaseCommand {
  InputCommand *command;
} ReleaseCommand;

typedef struct InputHandler {
  InputCommand *attack_command;
  InputCommand *delay_command;
  InputCommand
      *sustain_command; // call the actual root member which manipulates
  InputCommand *release_command; // don't use the actual structs to call
} InputHandler;

void handle_command_inputs(InputHandler handler);

void execute_game_actor(InputCommand *command, PlayerEntity *player);

#endif // GAME_ACTOR_ENTITY_H
