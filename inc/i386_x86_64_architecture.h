#ifndef i386_X86_64_ARCHITECTURE_H
#define i386_X86_64_ARCHITECTURE_H

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include <qemu/osdep.h>
#include <hw/hw.h>
#include <hw/sysbus.h>
#include <qemu/bitops.h>
#include <qemu/log.h>

enum RbStatusCodes {
  SUCCESS = 0x0000, // possibly change bytecode for bitwise ops
  INVALID_PLATFORM_STATE = 0x0001,
  INVALID_GUEST_STATE = 0x0002,
  INVALID_CONFIG = 0x0003,
  INVALID_LENGTH = 0x0004,
  ALREADY_OWNED = 0x0005,
  INVALID_CERTIFICATE = 0x0006,
  POLICY_FEATURE = 0x0007,
  INACTIVE = 0x008,
  INVALID_ADDRESS = 0x009,
  BAD_SIGNATURE = 0X000A,
  BAD_MEASUREMENT = 0x000B,
  ASID_OWNED = 0x000C,
  INVALID_ASID = 0x000D,
  WBINVD_REQUIRED = 0x000E,
  DF_FLUSH_REQUIRED = 0x000F,
  INVALID_GUEST = 0x0010,
  INVALID_COMMAND = 0x0011,
  ACTIVE = 0x0012,
  HWERROR_PLATFORM = 0x0013,
  HWERROR_UNSAFE = 0x0014,
  UNSUPPORTED = 0x0015,
  INVALID_PARAM = 0x0016,
  RESOURCE_LIMIT = 0x0017,
  SECURE_DATA_INVALID = 0x0018,
  RB_MODE_EXITED = 0x001F
};

typedef struct InhouseDevice {
  struct SerialDevice *device;
  char (*iomem)(__iomem *throughput);
} InhouseDevice;

typedef struct UserData {
  void *destination, *source, *user_data;
  unsigned long long data_size;
} UserData;

typedef struct DecryptedCommandBuffer {
} DecryptedCommandBuffer;

typedef struct DecryptedCommandBufferTree {
  RbStatusCodes rb_status_code;
} DecryptedCommandBufferTree;

typedef struct DecryptedCommandHandler {
  DecryptedBufferTree *decrypted_command_buffer_tree;
} DecryptedCommandHandler;

typedef struct LocatorService {
} LocatorService;

typedef struct AnnulService {
} AnnulService;

#endif // i386_X86_64_ARCHITECTURE_H
