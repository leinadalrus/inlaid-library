#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
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

#ifndef ORDNANCE_SERVICE_LOCATOR_H
#define ORDNANCE_SERVICE_LOCATOR_H

int output_shader_info_log(GLuint shader_index);
int check_shader_linking_errors(int params);
int output_program_info_log(GLuint program_index);
int check_program_is_valid(GLuint program_index);

typedef struct VertexBufferOrdnance {
  GLuint points, colors;
} VertexBufferOrdnance;

int init_itemized_vbs(GLuint vbo_points, GLuint vbo_colors);
struct VertexBufferOrdnance *
create_itemized_vbos(struct VertexBufferOrdnance ordnance, GLuint vbo_points,
                     GLuint vbo_colors);
void define_itemized_vaos(struct VertexBufferOrdnance ordnance);
void enable_ordnance_attrib_arrs();

typedef struct VertexBufferServiceLocator {
  VertexBufferOrdnance
      vertex_buffer_ordnance; // don't point to type. We want the address.
} VertexBufferServiceLocator;

typedef struct AnnulVertexBufferService {
  VertexBufferServiceLocator
      vertex_buffer_service; // don't point to type. We want the address.
} AnnulVertexBufferService;  // created class for additional checking overhead

int annul_vertex_buffer_service(VertexBufferOrdnance *ordnance_self);

#endif
