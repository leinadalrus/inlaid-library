#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#include <assert.h>
#include <fcntl.h>
#include <memory.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../inc/amd64_command_buffer_handler.h"
#include "../inc/amd64_command_ring_buffer.h"
#include "../inc/powerpc_virtual_storage_model.h"

#define __iomem                                                                \
  __attribute__((                                                              \
      noderef,                                                                 \
      address_space(2))) // temporary definition of __iomem from sparse

uint64_t
virtual_device_information_read(void *any_opaque,
                                struct PpuOffsetLookasideBuffer *address_offset,
                                unsigned int data_size) {
  uint64_t ret_val = 0;
  DecryptedCommandBufferTree *command_buffer_tree;
  int is_enabled = 0; // = dev_info->virtual_device_data->destination & BIT(0);

  if (is_enabled == 0) {
    fprintf(stderr, "Device is disabled!\n");
    ret_val = 0;
  }

  switch (address_offset->rb_status_code) {
  case SUCCESS:
    ret_val =
        (uint64_t)
            address_offset->ppe_translation_lookaside_buffer.address_offset;

  case INVALID_LENGTH:
    ret_val =
        (uint64_t)
            address_offset->ppe_translation_lookaside_buffer.address_offset;

  case INACTIVE:
    ret_val =
        (uint64_t)
            address_offset->ppe_translation_lookaside_buffer.address_offset;

  default:
    ret_val = 1;
  }

  return ret_val;
}

uint64_t virtual_device_information_write(
    void *any_opaque, struct PpuOffsetLookasideBuffer *address_offset,
    uint64_t assigned_value, unsigned int data_size) {
  uint64_t ret_val = 0;
  DecryptedCommandBufferTree *command_buffer_tree;
  int is_enabled = 0; // = dev_info->virtual_device_data->destination & BIT(0);

  if (is_enabled == 0) {
    fprintf(stderr, "Device is disabled!\n");
    ret_val = 0;
  }

  switch (address_offset->rb_status_code) {
  case SUCCESS:

    assigned_value =
        address_offset->ppe_translation_lookaside_buffer.address_offset
        << (signed char)0; // don't do (signed char*)0
    // do (signed char)0 to get address instead

    ret_val = assigned_value;

  case INACTIVE:
    // TODO fix dumb code
    // NOTE use powerpc_virtual_storage_model's memory management functions for
    // the virtual storages
    assigned_value =
        address_offset->ppe_translation_lookaside_buffer.address_offset
        << (signed char)0; // don't do (signed char*)0
    // do (signed char)0 to get address instead
    ret_val = assigned_value;

  default:
    ret_val = 1;
  }

  return ret_val;
}
