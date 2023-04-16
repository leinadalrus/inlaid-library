#include "../inc/disty_hashed_data.h" // Enumerated Chord DHT controller-daemon
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file_throughput(char *table_data, char *data_input, char *data_size,
                         char *data_output) {
  table_data = malloc(sizeof(data_size));
  memcpy(data_input, data_output, *table_data);
  free(table_data);

  return 0;
}

int reading_author_callback(int(function)(char *, char *, char *, char *)) {
  int (*reader)(void *) = malloc(sizeof function); // this is a non-heap object.
  memmove(function, reader, sizeof *function);

  int retval = 0;
  if (!reader) {
    retval = 1;
  }

  return retval; // return false as a boolean check codition.
}

int main(int argc, char *argv[]) { return 0; }
