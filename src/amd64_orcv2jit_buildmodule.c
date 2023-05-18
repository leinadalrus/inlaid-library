#include "../inc/amd64_orcv2jit_libexec.h"
#include "../inc/ndebug_tassert_messages.h"

#ifdef ASSERT_VARGS
#define ASSERT_VARGS(_str, ...) // redefined for re-use
#endif                          // !ASSERT_VARGS

#if defined(ORCV2JIT_X86) || defined(ORCV2JIT_X64)

const char *TEST_CODES;

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

#endif // !ORCV2JIT_X86 || ORCV2JIT_X64
