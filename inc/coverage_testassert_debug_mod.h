#ifndef COVERAGE_TESTASSERT_DEBUG_MOD_H
#define COVERAGE_TESTASSERT_DEBUG_MOD_H

#ifndef COVER_TESTASSERT_IF
#define COVER_TESTASSERT_IF(_ifstate, _str, _iof, ...)                         \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_ifstate || #_str == "for") {                                         \
      if (__LINE__ == #_ifstate) {                                             \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_ifstate, #_str);                 \
        printf("\n%v:\n\t:%s", #_iof, __FILE__);                               \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_IF

#ifndef COVER_TESTASSERT_FOR
#define COVER_TESTASSERT_FOR(_forloop, _str, _iof, ...)                        \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_forloop || #_str == "for") {                                         \
      if (__LINE__ == #_forloop) {                                             \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_forloop, #_str);                 \
        printf("\n%v:\n\t:%s", #_iof, __FILE__);                               \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_FOR

#ifndef COVER_TESTASSERT_WHILE
#define COVER_TESTASSERT_WHILE(_whileloop, _str, _iof, ...)                    \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_whileloop || #_str == "while") {                                     \
      if (__LINE__ == #_whileloop) {                                           \
        \ printf("%s\n:\t%d", __FILE__, __LINE__);                             \
        printf("\n%v:\n\tStored Value: %v", #_whileloop, #_str);               \
        printf("\n%v:\n\t:%s", #_iof, __FILE__);                               \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_WHILE

#ifndef COVER_TESTASSERT_ANYOPAQUE
#define COVER_TESTASSERT_ANYOPAQUE(_opaqueswitch, _str, _iof, ...)             \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_opaqueswitch || #_str == "switch") {                                 \
      if (__LINE__ == #_opaqueswitch) {                                        \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_opaqueswitch, #_str);            \
        printf("\n%v:\n\t:%s", #_iof, __FILE__);                               \
      }                                                                        \
    }                                                                          \
  }

#endif // !COVER_TESTASSERT_ANYOPAQUE
#endif // !COVERAGE_TESTASSERT_DEBUG_MOD_H
