#include "../inc/amd64_orcv2jit_libexec.h"
#include "../inc/ndebug_tassert_messages.h"

#ifdef ASSERT_VARGS
#define ASSERT_VARGS(_str, ...) // redefined for re-use
#endif                          // !ASSERT_VARGS

#ifndef ORCV2JIT_X86
#define ORCV2JIT_X86

enum TestCodes {
  C3 = 0xC3,
  CB = 0xCB,
  C2 = 0xC2,
  CA = 0xCA,
  EB = 0xEB,
  E9 = 0xE9,
  EA = 0xEA,
  FF = 0xff,
  TWENTY_FIVE = 0x25,
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
    fprintf(EXIT_FAILURE, "%s", argv[0]);

  return 0;
}

const int terminate_pageblock_source(const char *restrict pageblock_source) {
  const int n0 = pageblock_source[0];
  const int n1 = pageblock_source[1];

  enum TestCodes test_code;
  switch (test_code) {
  case C3:
  case CB:
  case C2:
  case EB:
  case E9:
  case EA:
  case FF:
  case TWENTY_FIVE:
  default:
    return 1;
  }

  return 0;
}

#endif // !ORCV2JIT_X86

#if defined(ORCV2JIT_X86) || defined(ORCV2JIT_X64)
#endif // !ORCV2JIT_X86 || ORCV2JIT_X64
