#ifndef x86_COMMAND_BUFFER_HANDLER_H
#define x86_COMMAND_BUFFER_HANDLER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct PhantomMarker {
  char *token_byte;
  char *heap_slice;
  signed int cursor_position;
  signed int read_position;
} PhantomMarker;

typedef struct LintCommandBufferCursor {
  PhantomMarker phantom_marker[sizeof(char)][sizeof(char)]; // reference-based
                                                            //
} LintCommandBufferCursor;

typedef struct LintCommandBufferTree {
  PhantomMarker phantom_sizes[sizeof(char)][sizeof(char)]; // note: need matrix
                                                           //
} LintCommandBufferTree;

typedef struct LintCommandHandler {
  LintCommandBufferTree *lint_command_buffer_tree;
} LintCommandHandler;

typedef struct LintCommandContext {
  void *lint_command_context;
} LintCommandContext;

typedef struct LintServiceLocator {
  LintCommandBufferTree *lint_command_buffer_tree;
  LintCommandHandler *lint_command_handler;
} LintServiceLocator;

const int defer_context(LintCommandContext *lint_command_context);
int handled_deferred_context(int (*defer_context_callback)(), void *user_data,
                             void *iomem_source, void *table_data,
                             uint64_t data_size);

typedef struct LintAnnulService {
  LintCommandBufferTree *lint_command_buffer_tree;
  LintCommandHandler *lint_command_handler;
} LintAnnulService;

// `handle_context` of singleton strategy function pointers/contexts
const int handle_context(char *destination, char *source, uint8_t data_size,
                         char *user_data);
int read_handled_context_argument(int (*interface_handle_callback)(),
                                  char *user_data_header,
                                  signed int status_flag, uint64_t data_size);

#endif // x86_COMMAND_BUFFER_HANDLER_H
