#include "../inc/inputs.h"

int create() {
  int boolean;
  TilemapFloor tilemap_floor;
  tilemap_floor.tiles.x = 8;
  tilemap_floor.tiles.y = 8;

  tilemap_floor.id = (unsigned char *)calloc(
      tilemap_floor.tiles.x * tilemap_floor.tiles.y, sizeof(unsigned char));

  RenderTexture2D tile_occlusion =
      LoadRenderTexture(tilemap_floor.tiles.x, tilemap_floor.tiles.y);
  SetTextureFilter(tile_occlusion.texture, TEXTURE_FILTER_BILINEAR);

  return boolean;
}

int refer(TilemapFloor floor) {
  int boolean = 0;
  RenderTexture2D tile_occlusion =
      LoadRenderTexture(floor.tiles.x, floor.tiles.y);
  SetTextureFilter(tile_occlusion.texture, TEXTURE_FILTER_BILINEAR);
  int index[8];

  BeginTextureMode(tile_occlusion);
  ClearBackground(BLANK);
  // use a type-cast of: (int) for the array subscript
  for (int i = 0; i < floor.tiles.y; i++)
    for (int j = 0; j < floor.tiles.x; j++)
      if (floor.id[i * (int)floor.tiles.x + j] == 0)
        DrawRectangle(j, i, 1, 1, BLACK);
      else if (floor.id[i * (int)floor.tiles.x + j] == 2)
        DrawRectangle(i, j, 1, 1, Fade(BLACK, .9f));
  // NOTE(Daniel): Array subscript is not an integer[?]
  EndTextureMode();

  return boolean;
}

int update(TilemapFloor floor, PlayerBundle player) {
  int boolean;

  if (player.position.position.x < 0)
    player.position.position.x = 0;
  else if ((player.position.position.x +
            (player.sprite.width * player.sprite.height)) >
           (floor.tiles.x * TILEMAP_SIZE_MIN))
    player.position.position.x = (float)floor.tiles.x * TILEMAP_SIZE_MIN -
                                 (player.sprite.width * player.sprite.height);
  if (player.position.position.y < 0)
    player.position.position.y = 0;
  else if ((player.position.position.y +
            (player.sprite.width * player.sprite.height)) >
           (floor.tiles.y * TILEMAP_SIZE_MIN))
    player.position.position.y = (float)floor.tiles.y * TILEMAP_SIZE_MIN -
                                 (player.sprite.width * player.sprite.height);

  return boolean;
}

int destroy(TilemapFloor floor) {
  int boolean;
  free(floor.id);
  return boolean;
}
