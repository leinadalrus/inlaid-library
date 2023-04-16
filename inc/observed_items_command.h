#ifndef OBSERVED_ITEMS_COMMAND_H
#define OBSERVED_ITEMS_COMMAND_H
#include "../inc/disty_hashed_data.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct UserCommand
{
  int (*execute)(char *command);
} UserCommand;

typedef struct UserHandle
{
  UserCommand *user_command;
  int (*handle)(char *command);
} UserHandle;

int dimmdir_note_throughput(void *table_data, void *data_input, void *data_output, size_t data_size)
{
  table_data = malloc(sizeof(data_size));
  memcpy(data_input, data_output, data_size);
  free(table_data);

  return 0;
}

int hashed_callback_with_flush(int(function)(char *x, char *y, char *z, char *a))
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
  flushall(); // don't forget to flush!
  // free(reader); // this is a non-heap object.

  return retval; // return false as a boolean check codition.
}

const int *handle_user_input()
{
  int *retval = 0;

  if (!hashed_callback_with_flush)

    return retval;

  dimmdir_note_throughput;
}

#endif // OBSERVED_ITEMS_COMMAND_H