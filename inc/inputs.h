#include "../inc/buffered_drawing_renders.h"
#include "../inc/ordnance_service_locator.h"
#include "game_actor_entity.h"
#include <raylib.h>

#ifndef INPUTS_H
#define INPUTS_H

#define RESERVED_CURRENT_PROGRAM_REGISTER_SIZE 4
#define SPRITE_TEXTURE_WIDTH 255
#define TILEMAP_SIZE_MIN 16 // could represent the top half of the register
#define PADDING_SIZE 3
#define MARGIN_SIZE 4
// the padding and margin are combined for texture culling
// TODO(Daniel): create a single 'sect' like room, similar to the Build Engine
typedef struct TilemapFloor {
  Vector2 tiles;
  unsigned char *id;
} TilemapFloor;

typedef struct ConcaveBackdrop {
  Image image;
} ConcaveBackdrop;

typedef struct SectVertexMatrix {
  VertexPoints *vertex_point_matrices[RESERVED_CURRENT_PROGRAM_REGISTER_SIZE];
} SectVertexMatrix;

int refer(TilemapFloor floor);

int update(TilemapFloor floor, PlayerBundle player);

int destroy(TilemapFloor floor);

#endif
