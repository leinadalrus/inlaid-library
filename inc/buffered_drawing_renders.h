#if _WIN32
#include <C:/raylib/raylib/src/raylib.h>
#include <io.h> // equivalent to <unistd.h>
#elif __linux__
#include <raylib.h>
#include <unistd.h> // equivalent to <io.h>
#endif

#if _WIN32
#include "C:\\dev\\vcpkg\\packages\\glew_x86-windows\\include\\GL\\glew.h"
#include "C:\\dev\\vcpkg\\packages\\glfw3_x86-windows\\include\\GLFW\\glfw3.h"
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

#ifndef BUFFERED_DRAWING_RENDERS_H
#define BUFFERED_DRAWING_RENDERS_H

typedef struct ImagePosition {
  int x, y;
} ImagePosition;

typedef struct ImageName {
  const char *name;
} ImageName;

typedef struct VertexPoints {
  GLfloat a2[3];
  GLfloat b2[3];
  GLfloat c2[3];
} VertexPoints;

int initialise_trig_vbos();
GLfloat *transform_a2_buffers(VertexPoints a2_buffers);
GLfloat *transform_b2_buffers(VertexPoints b2_buffers);
GLfloat *transform_c2_buffers(VertexPoints c2_buffers);

int create_graphx_lang_vbos();
int view_graphx_lang_vbos();
int update_graphx_lang_vbos();
int render_graphx_lang_vao(GLuint vao);
int annul_graphx_lang_bufs();
int destroy_graphx_lang_bufs();

#endif // !BUFFERED_DRAWING_RENDERS_H
