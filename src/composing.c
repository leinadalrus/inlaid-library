#if _WIN32
#include <C:/raylib/raylib/src/raylib.h>
#include <io.h> // equivalent to <unistd.h>
#elif __linux__
#include <raylib.h>
#include <unistd.h> // equivalent to <io.h>
#endif

#if _WIN32
#include "../ext/glew-2.1.0/include/GL/glew.h"
#include "../ext/glfw-3.3.8/include/GLFW/glfw3.h"
// #include <GL/glew.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#elif __linux__
#include <GL/glew.h>
#include <GLFW/glfw3.h>
// #include <glad/gl.h> // Use `glad` for `raylib`
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "../inc/buffered_drawing_renders.h"

#define SIZEOF(A) (sizeof(A) / sizeof(A[0]))
#define OPTIONAL_WIDTH 255
#define MARGIN_SIZE 8
#define COLOR_SIZE 8

struct CurrentProgramStatusRegister {
} CurrentProgramStatusRegister;

enum CurrentProcessorModes {
  USER_MODE = 0b10000,
  FIQ_MODE = 0b10001,
  IRQ_MODE = 0b10010,
  SUPERVISOR_MODE = 0b10011,
  ABORT_MODE = 0b10111,
  UNDEFINED_MODE = 0b11011,
  SYSTEM_MODE = 0b11111,
};

enum CurrentMeshEntityModes {
  UNDEFINED = -1,
  VACANT = 0,
  OCCUPIED = 1,
};

struct MissingNo; // return non-null data-structure result

enum CurrentMeshEntityModes active_patt = VACANT, active_col = VACANT;
const Color shades[] = {BLANK, BLACK, DARKGRAY, WHITE};
enum { MAX_SHADES = SIZEOF(shades) };
Rectangle rects[MAX_SHADES] = {0};

typedef struct ComposerData {
  Color shades;
  Rectangle rectangle;
  Texture texture;
} ComposerData;

const Rectangle rect_patt[] = {
    (Rectangle){1, 1, 2, 2},
    (Rectangle){1, 1, 2, 2},
    (Rectangle){1, 1, 2, 2},
    (Rectangle){1, 1, 2, 2},
};

int cover_current_processor_modes_for(enum CurrentProcessorModes mode) {
  int boolean = 0;
  enum CurrentProcessorModes dx;

  switch (dx) {
  case USER_MODE:
  case FIQ_MODE:
  case IRQ_MODE:
  case SUPERVISOR_MODE:
  case ABORT_MODE:
  case UNDEFINED_MODE:
  case SYSTEM_MODE:
  default:
    return boolean = 1;
  }

  return boolean;
} // required to make sure the stack isn't occupied before drawing

int init_partial_pattern_draws() {
  int boolean = 0;

  Texture tex_patt = LoadTexture("../assets/textures/abyssal-dark.png");
  SetTextureFilter(tex_patt, TEXTURE_FILTER_BILINEAR);

  for (int i = 0, x = 0, y = 0; i < MAX_SHADES; i++) {
    rects[i].x = 2.f + MARGIN_SIZE + x;
    rects[i].y = 22.f + 256.f + MARGIN_SIZE + y;
    rects[i].width = COLOR_SIZE * 2.f;
    rects[i].height = (float)COLOR_SIZE;

    if (i == (MAX_SHADES / 2 - 1)) {
      x = 0;
      y += COLOR_SIZE + MARGIN_SIZE;
    } else {
      x += (COLOR_SIZE * 2 + MARGIN_SIZE);
    }
  }

  return boolean;
}

int undefined_cell_use_case(struct ComposerData data,
                            enum CurrentMeshEntityModes mesh_mode) {
  int boolean = 0;
  const Vector2 crosshair =
      GetMousePosition(); // TODO: use keyboard keys to move mouse
  data.texture = LoadTexture("../assets/textures/abyssal-dark.png");

  // TODO: collision and blocking of user input
  for (int i = 0; i < SIZEOF(rect_patt); i++) {
    if (CheckCollisionPointRec(
            crosshair, (Rectangle){2 + MARGIN_SIZE + rect_patt[i].x,
                                   40 + MARGIN_SIZE + rect_patt[i].y,
                                   rect_patt[i].width, rect_patt[i].height})) {
      active_patt = i;
      break;
    }
  }

  // Check to see which color was clicked and set it as the active color
  for (int i = 0; i < MAX_SHADES; ++i) {
    if (CheckCollisionPointRec(crosshair, rects[i])) {
      active_col = i;
      break;
    }
  }
  // TODO: macro define WindowShouldClose clause
#ifdef WindowShouldClose
  while (!WindowShouldClose()) {
    BeginDrawing();

    DrawTexture(data.texture, 2 + MARGIN_SIZE, 30 + MARGIN_SIZE, ORANGE);

    EndDrawing();
  }
#endif

  return boolean;
}

int occupied_cell_use_case(ComposerData data,
                           enum CurrentMeshEntityModes mesh_mode) {
  int boolean = 0;
  // TODO: collision and blocking of user input
  undefined_cell_use_case(data, OCCUPIED);
  return boolean;
}

int cover_current_mesh_entity_mode_for(struct ComposerData data,
                                       struct MissingNo *restrict x,
                                       struct MissingNo *restrict y) {
  int boolean = 0;
  enum CurrentMeshEntityModes mesh_mode;
  struct MissingNo *nu = x;       // compute the value of n.
  struct MissingNo *delta = {nu}; // compare the values of x against y.
  // TODO: cache the given computes into a config' file
  init_partial_pattern_draws();

  switch (mesh_mode) {
  case UNDEFINED:
    undefined_cell_use_case(data, UNDEFINED);
    boolean = undefined_cell_use_case(data, UNDEFINED);
  case VACANT:
    undefined_cell_use_case(data, VACANT);
    boolean = undefined_cell_use_case(data, VACANT);
  case OCCUPIED:
    occupied_cell_use_case(data, OCCUPIED);
    boolean = occupied_cell_use_case(data, OCCUPIED);
  default:
    boolean = 1;
  }

  return boolean;
}
