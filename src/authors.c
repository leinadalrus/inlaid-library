#include <corecrt.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h> // windows equal to unistd
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifndef CHUNK_BUFFER_SLICE
#define CHUNK_BUFFER_SLICE 1024
#endif

const int _va_args_filedescs_sentinel(int argc, char *argv[]) {
  int input_filedesc, output_filedesc, open_flags;
  char buffers[CHUNK_BUFFER_SLICE];
  int ret_val = 0;

  if (argc != 3 || strcmp(argv[1], "--help") == 0)
    ret_val = 1;

  // NOTE: open(...) is an <fcntl.h> function
  errno_t errno_strf = _sopen_s(&input_filedesc, argv[1], O_RDONLY, _SH_DENYNO,
                                0); // open is deprecated. Use: _sopen_s

  if (input_filedesc == -1)
    ret_val = -1;

  if (_close(input_filedesc) == -1)
    ret_val = -1;

  if (_close(output_filedesc) == -1)
    ret_val = -1;

  return ret_val;
}
