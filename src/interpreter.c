#if _WIN32 || __linux
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#endif

#if _WIN32
#include <C:\\llvm\\llvm\\include\\llvm-c\\ExternC.h>
#endif

#ifdef _WIN32
#include <C:\\llvm\\llvm\\include\\llvm-c\\Analysis.h>
#include <C:\\llvm\\llvm\\include\\llvm-c\\BitWriter.h>
#include <C:\\llvm\\llvm\\include\\llvm-c\\Core.h>
#include <C:\\llvm\\llvm\\include\\llvm-c\\ExecutionEngine.h>
#include <C:\\llvm\\llvm\\include\\llvm-c\\Target.h>
#include <C:\\llvm\\llvm\\include\\llvm-c\\Types.h>
#endif

#ifdef __linux__
#include <llvm-c/Analysis.h>
#include <llvm-c/BitWriter.h>
#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Types.h>
#endif

int init(int argc, char *argv[]) {
  LLVMModuleRef module = LLVMModuleCreateWithName("PPUFunctionPass");
  LLVMTargetDataRef LHS;
  LLVMTargetDataRef RHS;
  LLVMTargetDataRef VAL;
  LLVMTypeRef matrix_comparisons[] = {LLVMIntPtrType(LHS), LLVMIntPtrType(RHS)};
  LLVMTypeRef matrix_type_referee = LLVMFunctionType(
      LLVMIntPtrType(VAL), matrix_comparisons, *argv[1], *argv[2]);
  // argv[0] is for reading the filename as an argument
  // we use argv[1] and argv[2] for our comparators

  LLVMValueRef comparator_function =
      LLVMAddFunction(module, "comparator", matrix_type_referee);
  // add a module, name, and type into an LLVM function. This is not a
  // function for 'addition'. Don't confuse it for so.

  LLVMTypeRef given_arguments[] = {
      LLVMGetParam(comparator_function, (int)*argv[1]),
      LLVMGetParam(comparator_function, (int)*argv[2])};
  // [!] Incompatible pointer types initializing ...

  LLVMTypeRef observed_type = LLVMFunctionType(
      LLVMIntPtrType(LHS), given_arguments, *argv[1], *argv[2]);
  LLVMValueRef actually_observed =
      LLVMAddFunction(module, "observer", observed_type);

  LLVMBasicBlockRef memblc_entry =
      LLVMAppendBasicBlock(comparator_function, "entry");
  // append a basic block to the end of a function

  LLVMBuilderRef builder = LLVMCreateBuilder();
  LLVMPositionBuilderAtEnd(builder, memblc_entry);

  LLVMValueRef temp_ppu_params =
      LLVMBuildPtrDiff2(builder, LLVMIntPtrType(LHS), comparator_function,
                        actually_observed, "in for: SPU Block");
  // TODO(Daniel): code ...
  // LLVMBuildGEP(...); // get element pointer(s)
  // LLVMBuildStore(...); // store element pointers as SPU Blocks
  LLVMBuildRet(builder, temp_ppu_params);
  LLVMBuildFree(builder, temp_ppu_params);
  LLVMBuildRetVoid(builder);

  char *error_message = NULL;
  LLVMVerifyModule(module, LLVMAbortProcessAction, &error_message);
  LLVMDisposeMessage(error_message);

  error_message = NULL;
  LLVMExecutionEngineRef engine;
  LLVMLinkInMCJIT();            // or link in Interpreter[?]
  LLVMInitializeNativeTarget(); // gotta link with our target architecture

  // TODO: code ...

  LLVMDisposeBuilder(builder);
  LLVMDisposeExecutionEngine(engine);

  return 0;
}
