#include "../inc/ordnance_service_locator.h"

int output_shader_info_log(GLuint shader_index) {
  int max_length = 2048;
  int index = 0;
  char buffer[max_length];
  glGetShaderInfoLog(shader_index, max_length, &index, buffer);
  printf("%u:\n%s\n", shader_index, buffer);
  return 0;
}

int check_shader_linking_errors(int params) {
  params = -1;
  GLuint shader_program;
  glGetProgramiv(shader_program, GL_LINK_STATUS, &params);

  if (GL_TRUE != params)
    output_shader_info_log(shader_program);

  return params;
}

int output_program_info_log(GLuint program_index) {
  int max_length = 2048;
  int index = 0;
  char buffer[max_length];
  glGetProgramInfoLog(program_index, max_length, &index, buffer);
  return 0;
}

int check_program_is_valid(GLuint program_index) {
  glValidateProgram(program_index);
  int params = -1;
  glGetProgramiv(program_index, GL_VALIDATE_STATUS, &params);

  if (GL_TRUE != params)
    output_program_info_log(program_index);

  return 0;
}

int init_itemized_vbs(GLuint vbo_points, GLuint vbo_colors) {
  struct VertexBufferOrdnance {
    GLuint points, colors;
  } ordnance = {
      .points = vbo_points,
      .colors = vbo_colors,
  };

  return 0;
} // NOTE: we use int as a primitive type for a boolean

struct VertexBufferOrdnance *
create_itemized_vbos(struct VertexBufferOrdnance ordnance, GLuint vbo_points,
                     GLuint vbo_colors) {
  GLfloat points[] = {0.f, .2f, 0.f, .2f, .1f, 0.f, .1f, .1f, 0.f};
  GLfloat colors[] = {0.f, .2f, 0.f, .2f, .1f, 0.f, .1f, .1f, 0.f};

  // points are defined by user. we don't need this: // vbo_points = 0;
  // colors are defined by user. we don't need this: // vbo_colors = 0;

  glGenBuffers(1, &vbo_points);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_points);
  glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

  glGenBuffers(1, &vbo_colors);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

  // *cloned_ordnance = ordnance; // get the address
  // NOTE: two different things.
  struct VertexBufferOrdnance *cloned_ordnance = &ordnance; // get the value
  cloned_ordnance->points = vbo_points;
  cloned_ordnance->colors = vbo_colors;

  return cloned_ordnance; // is dynamically stored in heap.
}

void define_itemized_vaos(struct VertexBufferOrdnance ordnance) {
  GLuint vao = 0;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, ordnance.points);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

  glBindBuffer(GL_ARRAY_BUFFER, ordnance.colors);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void enable_ordnance_attrib_arrs() {
  struct VertexBufferOrdnance *ordnance =
      malloc(sizeof(struct VertexBufferOrdnance));
  struct VertexBufferOrdnance *cloned_ordnance =
      create_itemized_vbos(*ordnance, 0, 0);
  define_itemized_vaos(*cloned_ordnance);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

int annul_vertex_buffer_service(VertexBufferOrdnance *ordnance_self) {
#ifndef ordnance_self // ordnance_self has already been defined in this fn
                      // params
#if ordnance_self != 0
  for (int i = 0; i < sizeof *ordnance_self;
       ++i) { // ++i to have it increment beforehand
    free(ordnance_self);
    ordnance_self = NULL;
  }
#endif
#endif // ifndef ordnance_self
  return 0;
}
