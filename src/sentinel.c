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

int render(GLuint vao) {
  const char *vertex_shader =
      read_shader_idl_content("#version430\n"
                              "in vec3 vp;"
                              "void main () {"
                              "\tgl_Position = vec4 (vp, 1.0);"
                              "}");
