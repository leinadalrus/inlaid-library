#ifdef __linux__
#include "/llvm/adt/stringref.h"
#include "/llvm/executionengine/orc/compileutils.h"
#include "/llvm/executionengine/orc/core.h"
#include "/llvm/executionengine/orc/executionutils.h"
#include "/llvm/executionengine/orc/ircompilelayer.h"
#include "/llvm/executionengine/orc/jittargetmachinebuilder.h"
#include "/llvm/executionengine/orc/rtdyldobjectlinkinglayer.h"
#include "/llvm/executionengine/sectionmemorymanager.h"
#include "/llvm/ir/datalayout.h"
#include "/llvm/ir/llvmcontext.h"
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#endif // !__linux__

#ifdef _WIN32
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef DETOURS_INTERNAL
#include <detours.h> // NOTE: ifdef detours.h
#endif
#include <memory.h>
#ifndef PCONTEXT
#define PCONTEXT
#define pContextRecord
#endif // !_CONTEXT
#endif

#ifndef NDEBUG_TASSERT_MESSAGES_H
#define NDEBUG_TASSERT_MESSAGES_H

#define DEBUG_CHECK(_str, ...)

#define ASSERT_VARGS(_str)                                                     \
  {                                                                            \
    if (!(_str, ...))                                                          \
      DEBUG_CHECK(#_str, __FILE__, __LINE__);                                  \
  }

#define ASSERT_MESSAGE(sz_message)                                             \
  { printf("%s in %s, line: %d", sz_message, __FILE__, __LINE__); }

#define ASSERT_VERBOSE(sz_message, sz_file, xn_line)                           \
  { printf("%s in %s, line %ld", sz_message, sz_file, xn_line); }

#endif // !NDEBUG_TASSERT_MESSAGES_H
