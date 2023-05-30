#include "../inc/libgxxjit_interpreter.h"
#include "../inc/amd64_command_buffer_handler.h"
#include "../inc/amd64_command_ring_buffer.h"
#include "../inc/components.h"
#include "../inc/coverage_testassert_debug_mod.h"
#include "../inc/handling.h"
#include "../inc/ndebug_testassert_messages.h"
#include "../inc/powerpc_virtual_storage_model.h"

#if _WIN32
#include <memory.h>
#include <string.h>
#elif __linux__
#include <libgccjit.h>
#include <memory.h>
#include <string.h>
#endif
// need to have this include file separated
// and outside of include guards

#ifdef LIBGXXJIT_INTERPRETER_H
extern int libgxxjit_interpreter_toggle;
#endif

void load_maked_coreboot_bios(int(*unix_nan_boxing)) {
  switch (*unix_nan_boxing) {
  default:
    break;
  }
}

int get_x64v3_memory_region(uint32_t address, int is_written,
                            MemoryRegion *memory_region) {
  return 0;
}

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address) {
  return 0;
}

uint64_t get_internal_system_clock_cycles(int n_cycles) { return 0; }

uint64_t set_x64v3_memory_region_timings(uint32_t starting_address,
                                         uint32_t ending_address,
                                         uint32_t memory_region, int bus_width,
                                         int non_sequential, int sequential) {
  return 0;
}

void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address) {}

int x64v3_jit_runtime_sentinel() {
  enum RingBufferStatusCodes rb_status_code = 0;

  switch (rb_status_code) {
  case INVALID_ADDRESS:
  case INVALID_ASID:
  case INVALID_CERTIFICATE:
  case INVALID_COMMAND:
  case INVALID_CONFIG:
  case INVALID_LENGTH:
  case INVALID_PARAM:
  case INVALID_PLATFORM_STATE:
  default:
    break;
  }

  return 0;
}

int jit_startup_sentinel() {
  switch (libgxxjit_interpreter_toggle) {
  case 0:
    x64v3_jit_runtime_sentinel();
  case 1:
  default:
    break;
  }

  return 0;
}

LibGxxJitInterpreter *
initialise_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {
  const char buffer[254];
  LibGxxDataBundle *data_bundle =
      memset(interpreter, (int)buffer[254],
             sizeof(LibGxxDataBundle)); // root table data
  MemoryRegion *memory_locale =
      memcpy(data_bundle, interpreter,
             sizeof(ArenaState)); // restricted table data
  ArenaState *memory_state =
      memcpy(data_bundle, memory_locale, (size_t)buffer); // mutable table data

  uint8_t destination = (uint8_t)memory_state->arena_data.destination;
  // arena_data->destination is mutable:
  destination = destination >> memory_locale->memory;
  // arena_data->table_data is the bitmask for bit-ops
  uint32_t table = (uint32_t)memory_state->arena_data.table_data;
  table = table >> memory_locale->mask;

  return interpreter;
}

void deinitialise_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  interpreter = initialise_external_jit_interpreter(interpreter);
  LibGxxRegionBundle *bundled_region = NULL;
  LibGxxJitInterpreter *new_interpreter =
      memset(interpreter, bundled_region->memory_region->memory,
             sizeof(LibGxxJitInterpreter));
  interpreter = new_interpreter;
}

void reset_external_jit_interpreter(LibGxxJitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  jit_startup_sentinel();
}

// Tutorial part 1: “Hello world” — libgccjit 14.0.0 (experimental )
// documentation (no date). Available at:
// https://gcc.gnu.org/onlinedocs/jit/intro/tutorial01.html.
void start_external_jit_interpreter(LibGxxJitInterpreter *interpreter,
                                    gcc_jit_context *ctxt) {
  /* Let's try to inject the equivalent of:
       void
       greet (const char *name)
       {
          printf ("hello %s\n", name);
       }
    */
  gcc_jit_type *void_type = gcc_jit_context_get_type(ctxt, GCC_JIT_TYPE_VOID);
  gcc_jit_type *const_char_ptr_type =
      gcc_jit_context_get_type(ctxt, GCC_JIT_TYPE_CONST_CHAR_PTR);
  gcc_jit_param *param_name =
      gcc_jit_context_new_param(ctxt, NULL, const_char_ptr_type, "name");
  gcc_jit_function *func =
      gcc_jit_context_new_function(ctxt, NULL, GCC_JIT_FUNCTION_EXPORTED,
                                   void_type, "greet", 1, &param_name, 0);

  gcc_jit_param *param_format =
      gcc_jit_context_new_param(ctxt, NULL, const_char_ptr_type, "format");
  gcc_jit_function *printf_func = gcc_jit_context_new_function(
      ctxt, NULL, GCC_JIT_FUNCTION_IMPORTED,
      gcc_jit_context_get_type(ctxt, GCC_JIT_TYPE_INT), "printf", 1,
      &param_format, 1);
  gcc_jit_rvalue *args[2];
  args[0] = gcc_jit_context_new_string_literal(ctxt, "hello %s\n");
  args[1] = gcc_jit_param_as_rvalue(param_name);

  gcc_jit_block *block = gcc_jit_function_new_block(func, NULL);

  gcc_jit_block_add_eval(
      block, NULL, gcc_jit_context_new_call(ctxt, NULL, printf_func, 2, args));
  gcc_jit_block_end_with_void_return(block, NULL);
}

void stop_external_jit_interpreter(LibGxxJitInterpreter *interpreter,
                                   gcc_jit_context *ctxt) {}

int run() {
  gcc_jit_context *ctxt;
  gcc_jit_result *result;

  /* Get a "context" object for working with the library.  */
  ctxt = gcc_jit_context_acquire();
  if (!ctxt) {
    fprintf(stderr, "NULL ctxt");
    exit(1);
  }

  /* Set some options on the context.
     Let's see the code being generated, in assembler form.  */
  gcc_jit_context_set_bool_option(ctxt, GCC_JIT_BOOL_OPTION_DUMP_GENERATED_CODE,
                                  0);

  /* Populate the context.  */
  create_code(ctxt);

  /* Compile the code.  */
  result = gcc_jit_context_compile(ctxt);
  if (!result) {
    fprintf(stderr, "NULL result");
    exit(1);
  }

  /* Extract the generated code from "result".  */
  typedef void (*fn_type)(const char *);
  fn_type greet = (fn_type)gcc_jit_result_get_code(result, "greet");
  if (!greet) {
    fprintf(stderr, "NULL greet");
    exit(1);
  }

  /* Now call the generated function: */
  greet("world");
  fflush(stdout);

  gcc_jit_context_release(ctxt);
  gcc_jit_result_release(result);
  return 0;
}
