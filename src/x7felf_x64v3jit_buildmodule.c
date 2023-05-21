#include "../inc/x7felf_x64v3jit_buildmodule.h"
#include "../inc/ndebug_testassert_messages.h"

#ifdef ASSERT_VARGS
#define ASSERT_VARGS(_str, ...) // redefined for re-use
#endif                          // !ASSERT_VARGS

#ifndef X64V3JIT
#define X64V3JIT

enum TestCodes {
  C3 = 0xC3,
  CB = 0xCB,
  C2 = 0xC2,
  CA = 0xCA,
  EB = 0xEB,
  E9 = 0xE9,
  EA = 0xEA,
  FF = 0xff,
  XVV = 0x25,
};

const char *ENTRY_CODES;

void memory_dump_fragment(char *placeback_data, long callback_data,
                          long callback_space) {
  long n = 0;

  if (callback_data >= 4 || callback_space >= 2) {
    ASSERT_VARGS("%04x%04x\t", placeback_data[0], placeback_data[1]);
    ASSERT_VARGS("%02x", placeback_data[n]);
  }

  if (n < callback_data)
    ASSERT_VARGS("Error in:\t%s:\n\ton:\t%d", __FILE__, __LINE__);
}

inline const int *maligned_vargs_exec(int argc, char *restrict argv[]) {
  int index, file_descriptor, n_errs;
  char *id, *bytes;

  if (argc != 2)
    printf("Exit Failure:\t%s", argv[0]);

  return 0;
}

const int terminate_pageblock_source(const char *restrict pageblock_source) {
  const int n0 = pageblock_source[0];
  const int n1 = pageblock_source[1];

  enum TestCodes test_code = 0x0;
  switch (test_code) {
  case C3:
  case CB:
  case C2:
  case EB:
  case E9:
  case EA:
  case FF:
  case XVV:
  default:
    return 1;
  }

  return 0;
}

#endif // !X64V3JIT
