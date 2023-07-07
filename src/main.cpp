#if _WIN32 || __linux__
#include <cstdio>
#include <cstdlib>
#endif

#if _WIN32
#include <C:/raylib/raylib/src/raylib.h>
#include <emscripten/emscripten.h>
#endif

#if __linux__
#include <raylib.h>
#endif

struct PlayerEntity; // Prototype Design

typedef struct PlayerBundle {
  struct PlayerEntity *entity;
  Vector2 position;
} PlayerBundle; // Flyweight Design

PlayerBundle *init_player_bundle(PlayerBundle *bundle,
                                 struct PlayerEntity *entity_new,
                                 Vector2 position_new) {
  bundle->entity = entity_new;
  bundle->position = position_new; // member : no pointer OD ~> non-heap object

  return bundle;
}

bool destroy_player_bundle(PlayerBundle &bundle_old,
                           struct PlayerEntity &entity_old) {
  std::free(&bundle_old);
  std::free(&entity_old);
  delete &bundle_old;
  // delete &entity_old; : cannot delete pointer of an incomplete type

  return true; // return true because we just destroyed heap-space objects.
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE void fn_init_main_thread(int argc, char *argv[]) {
  printf("Function: Initialise --- Main Thread program...");
}

int main(int argc, char *argv[]) {
  struct PlayerEntity *entity;
  Vector2 position =
      Vector2{0, 0}; // No pointer OD, so we use an Address symbol in the `fn
                     // init(..)`. Thus is now a non-heap object

  enum WorldTerrains { CHECKERED_TEXTURE, STRIPED_TEXTURE };
  enum WorldTerrains terrain;
  int textures_matrices[8][8]; // match the 32-bit register

  PlayerBundle *player = init_player_bundle(player, entity, position);

  switch (terrain) {
  case 0:
    terrain = CHECKERED_TEXTURE;
  case 1:
  default:
    terrain = STRIPED_TEXTURE;
  }

  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      textures_matrices[x][y] = terrain;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }
  CloseWindow();

  destroy_player_bundle(*player, *entity);

  return 0;
}
