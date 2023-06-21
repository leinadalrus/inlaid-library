#include "../inc/buffered_drawing_renders.h"
#include "../inc/ordnance_service_locator.h"

#define RESERVED_CURRENT_PROGRAM_REGISTER_SIZE 4
#define SPRITE_TEXTURE_WIDTH 255
#define TILEMAP_SIZE_MIN 16 // could represent the top half of the register
#define PADDING_SIZE 3
#define MARGIN_SIZE 4
// the padding and margin are combined for texture culling
// TODO(Daniel): create a single 'sect' like room, similar to the Build Engine
typedef struct TilemapFloor {
  Vector2 tiles;
} TilemapFloor;

typedef struct ConcaveBackdrop {
  Image image;
} ConcaveBackdrop;

typedef struct SectVertexMatrix {
  VertexPoints *vertex_point_matrices[RESERVED_CURRENT_PROGRAM_REGISTER_SIZE];
} SectVertexMatrix;

int create() {
  int boolean;
  TilemapFloor tilemap_floor;
  tilemap_floor.tiles.x = 8;
  tilemap_floor.tiles.y = 8;
  return boolean;
}

int refer() {
  int boolean = 0;
  return boolean;
}

int update() {
  int boolean;
  return boolean;
}

int destroy() {
  int boolean;
  return boolean;
}
