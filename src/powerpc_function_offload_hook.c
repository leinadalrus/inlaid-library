#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FunctionOffloadHookId {
  int bytes_n;
  char message[];
} FunctionOffloadHookId;
