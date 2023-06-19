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
#define WINDOW_APPLICATION_TITLE "High Hunt!"
// FPS is defined as so to be base-10:
#define FPS_SET_TARGET 60
// FPS target is 10, but -2 for 8 to reflect spritesheet animation indices
// +2 additional frames for collision and invincibility

enum CurrentProcessorModes {
  USER_MODE = 0b10000,
  FIQ_MODE = 0b10001,
  IRQ_MODE = 0b10010,
  SUPERVISOR_MODE = 0b10011,
  ABORT_MODE = 0b10111,
  UNDEFINED_MODE = 0b11011,
  SYSTEM_MODE = 0b11111,
};
// the other 20 remaining registers
enum ArmRegisters {
  R0,
  R1,
  R2,
  R3,
  R4,
  R5,
  R6,
  R7,
  R8,
  R9,
  R10,
  R11,
  R12,
  R13,
  R14,
  R15,
  REG_IP = 12,
  REG_SP = 13,
  REG_LR = 14,
  REG_PC = 15,
}; // 32 registers in total ends here

enum ArmConditions {
  COND_EQ,
  COND_NE,
  COND_CS,
  COND_CC,
  COND_MI,
  COND_PL,
  COND_VS,
  COND_VC,
  COND_HI,
  COND_LS,
  COND_GE,
  COND_LT,
  COND_GT,
  COND_LE,
  COND_AL,
};

enum KnownInstructions {
  INST_ADD_IMMEDIATE,
  INST_B_ADDRESS,
  INST_BL_ADDRESS,
  INST_BLX_ADDRESS,
  INST_BX_REGISTER,
  INST_MOV_REGISTER,
  INST_MOVT_IMMEDIATE,
  INST_MOVW_IMMEDIATE,
  INST_MVN_IMMEDIATE,
  INST_POP_REGMASK,
  INST_PUSH_REGMASH,
  INST_SUB_IMMEDIATE,
  INST_SVC_IMMEDIAT,
  N_KNOWN_INSTRUCTIONS,
};

enum ArgumentTypes {
  ARG_INVALID,
  ARG_CONDITION,
  ARG_REGISTER,
  ARG_IMMEDIATE,
  ARG_ADDRESS,
  ARG_DATA_SYMBOL_ADDRESS,
  ARG_DATA_SYMBOL_ADDRESS_TOP16,    // half of the 32 ...
  ARG_DATA_SYMBOL_ADDRESS_BOTTOM16, // ... other half of the 32 registers
  ARG_DATA_SYMBOL_SIZE,
  ARG_FRAME_ADDRESS,
  ARG_FRAME_ADDRESS_PC_RELATIVE,
  ARG_REGMASK,
};

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

int initd_checked_player_instance(PlayerServiceLocator *service_instance) {
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

typedef struct PlayerName {
  const char *name;
} PlayerName;

typedef struct PlayerBundle {
  PlayerEntity entity;
  Position position;
  Health health;
  Texture2D sprite;
} PlayerBundle;

typedef struct PlayerObserver {
  void(*notifier);
} PlayerObserver;

int (*on_notice)(const PlayerEntity entity, enum ArmRegisters registry);

int check_linked_bundle_instance(PlayerEntity *player_instance) {
  struct PlayerBundle {
    PlayerEntity entity;
    Position position;
    Health health;
    Texture2D sprite;
  } bundle_instance = {
      .entity = *designate_entity_scalar(
          *player_instance), // pointer-to-address because of
                             // address of stack memory
      .position = {350.f, 280.f},
      .health = 100,
      .sprite = LoadTexture(
          "./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png"),
  };

  return 0;
}

PlayerBundle *init_player_bundle_instance(PlayerBundle *bundle_instance,
                                          PlayerEntity player_instance) {
  bundle_instance->entity =
      *designate_entity_scalar(player_instance); // pointer-to-address because
                                                 // of address of stack memory
  bundle_instance->position.position.x = 350.f;
  bundle_instance->position.position.y = 280.f;
  bundle_instance->health.health = 100;
  bundle_instance->sprite =
      LoadTexture("./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png");

  PlayerBundle *bundled = bundle_instance;

  return bundled; // may need memcpy and memmove
}

int process_world_relative_terrain() {
  enum WorldTerrains { EARTH_TEXTURE, AIR_TEXTURE, WATER_TEXTURE };
  int textiles_matrices[8][8]; // match the 32-bit register

  for (int i = 0; i < GetScreenWidth(); i++) {
    for (int j = 0; j < GetScreenHeight(); j++) {
      textiles_matrices[i][j] = EARTH_TEXTURE;
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

  struct PlayerBundle {
    PlayerEntity entity;
    Position position;
    Health health;
    Texture2D sprite;
  } bundle_instance = {
      .entity = *designate_entity_scalar(
          *player_instance), // pointer-to-address because of
                             // address of stack memory
      .position = {350.f, 280.f},
      .health = 100,
      .sprite = LoadTexture(
          "./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png"),
  };

  PlayerBundle *bundled;
  bundled = memset(&bundle_instance, 0, sizeof bundle_instance);

  PlayerBundle *player = init_player_bundle_instance(bundled, *player_instance);

  SetTargetFPS(FPS_SET_TARGET);

  while (!WindowShouldClose()) {
    frame_count++;

    if (frame_count >= (FPS_SET_TARGET / frame_speed)) {
      frame_count = 0;
      current_frame++;
      if (current_frame > 4)
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

    DrawTexture(player->sprite, 255, 255, WHITE);

    EndDrawing();
  }

  for (int i = 0; i < sizeof *bundled; ++i) {
    // free(bundled); // free called on unallocated object
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
