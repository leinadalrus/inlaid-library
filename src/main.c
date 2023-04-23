#include "../inc/distributed_user_data.h" // Enumerated Chord DHT controller-daemon
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define Z_CHUNK 16384

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

int allocated_deflated_state(FILE *source_buffer, FILE *destination_buffer, int level, char *argv[])
{
  int retval = Z_OK;
  int flush;
  unsigned have;
  unsigned char input_data[Z_CHUNK];
  unsigned char output_data[Z_CHUNK];
  // allocate deflate state
  z_stream buffer_streamer;
  buffer_streamer.zfree = Z_NULL;
  buffer_streamer.opaque = Z_NULL;
  buffer_streamer.avail_in = (uInt)strlen(source_buffer);
  buffer_streamer.next_in = (Bytef *)source_buffer;
  buffer_streamer.avail_out = (uInt)sizeof(destination_buffer);
  buffer_streamer.next_out = (Bytef *)destination_buffer;

  deflateInit(&buffer_streamer, Z_BEST_COMPRESSION);
  deflate(&buffer_streamer, Z_FINISH);
  deflateEnd(&buffer_streamer);

  do
  {
    buffer_streamer.avail_in = fread(input_data, 1, Z_CHUNK, source_buffer);

    if (ferror(source_buffer))
    {
      (void)deflateEnd(&buffer_streamer);
      retval = Z_ERRNO;
    }

    flush = feof(source_buffer) ? Z_FINISH : Z_NO_FLUSH;
    buffer_streamer.next_in = input_data;

    do
    {
      buffer_streamer.avail_out = CHUNK;
      buffer_streamer.next_out = output_data;

      retval = deflate(&buffer_streamer, flush);
      assert(retval != Z_STREAM_ERROR);

      have = CHUNK - buffer_streamer.avail_out;
      if (fwrite(output_data, 1, have, destination_buffer) != have || ferror(destination_buffer))
      {
        (void)deflateEnd(&buffer_streamer);
        retval = Z_ERRNO;
      }
    } while (buffer_streamer.avail_out == 0);

    assert(buffer_streamer.avail_in == 0);
  } while (flush != Z_FINISH);

  assert(retval == Z_STREAM_END);
  // clean up and return
  (void)deflateEnd(&buffer_streamer);
  return retval;
}

int main(int argc, char *argv[])
{
  char source_buffer[sizeof(char)] = argv;
  char destination_buffer[sizeof(char)] = {0};
  allocated_deflated_state(source_buffer, destination_buffer, 0, argv);

  return 0;
}
