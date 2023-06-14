// Stack Pointer Register
// : SP
// Link Register
// : LR
// Program Counter
// : PC
// Current Program Status Register
// : CPSR
// := SPLRSP

enum GeneralPurposeRegisters {
  R0 = 0x0300700,
};
enum StackPointerRegistrs {
  R13 = 0x30070D0,
};
enum DefaultProcessorModes {
  USER_SYSTEM = 0x03007F00,
  IRQ = 0x03007FA0,
  SUPERVISOR = 0x03007FE0,
};
enum CurrentProgramStatusRegisters {
  USER_MODE = 0b10000,
  FIQ_MODE = 0b10001,
  IRQ_MODE = 0b10010,
  SUPERVISOR_MODE = 0b10011,
  ABORT_MODE = 0b10111,
  UNDEFINED_MODE = 0b11011,
  SYSTEM_MODE = 0b11111,
};
enum VisualBoyAdvanceSystemInterrupts {
  SOFT_RESET = 0x00,
  REGISTER_RAM_RESET = 0x01,
  HALT = 0x02,
  STOP = 0x03,
  INTERRUPT_WAIT = 0x04,
  VIRTUAL_BLANK_INTERRUPT_WAIT = 0x05,
  // TODO: and many more other system interrupts
};
