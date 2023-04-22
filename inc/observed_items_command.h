#ifndef OBSERVED_ITEMS_COMMAND_H
#define OBSERVED_ITEMS_COMMAND_H
#include "../inc/distributed_user_data.h""
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct UserCommand
{
  int (*execute)(char *command);
} UserCommand;

typedef struct UserHandler
{
  UserCommand *user_command;
  int (*handle)(char *command);
} UserHandler;

void dimmdir_note_throughput(void *data_output, void *data_input,
                            void *request_block, unsigned long long data_size)
{
  data_input = memset(data_output, data_size, request_block);
  // memcpy(data_input, data_output, data_size);
  // free(table_data);
}

void hashed_callback_with_flush(int(function)(char *x, char *y, char *z,
                                             char *a))
{
  int (*reader)(char *); // this is a non-heap object.
  char *x, *y, *z, *a;
  memset(*reader, function(x, y, z, a), sizeof(function));
  memmove(function, reader, sizeof *function);

  int retval = 0;
  if (!reader)
  {
    retval = 1;
  }
  // free(reader); // free doesn't work with this non-heap object.
}

<<<<<<< Updated upstream
int error_profound_command_handle(int(context)(char *, char *, char *,
                                               char *)) {
  int error = memset(context, 0, sizeof(char));
=======
int error_profound_command_handle(int(context)(void *, char *, char *,
                                               char *))
{
  int error = context(memset(context, 0, sizeof(char)), 0, 0, 0);
>>>>>>> Stashed changes

  if (error <= 1) // have it not be 0 or 1 for event-based messaging
    exit(0);

  return error;
}

const int *handle_user_input()
{
  int *retval = 0;

  if (!hashed_callback_with_flush)

    return retval;

  dimmdir_note_throughput;
}

#endif // OBSERVED_ITEMS_COMMAND_H
