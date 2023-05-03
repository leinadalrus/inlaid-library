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

#include "../inc/i386_x86_64_architecture.h"

#define __iomem                                                                \
  __attribute__((                                                              \
      noderef,                                                                 \
      address_space(2))) // temporary definition of __iomem from sparse

#define SLICE_ARRAY_SIZE 16384

void virtual_device_information_set_irq(QVirtualDeviceInformation *dev_info,
                                        int irq) {
  dev_info->status_flag = irq;
  qemu_set_irq(dev_info->irq,
               1); // NOTE: flagged data-status of 'irq' is separated.
}

void virtual_device_information_clear_irq(QVirtualDeviceInformation *dev_info) {
  qemu_set_irq(dev_info->irq, 0);
}

uint64_t
virtual_device_information_read(void *any_opaque,
                                hwaddr address_offset unsigned int data_size) {
  uint64_t ret_val = 0;
  QVirtualDeviceInformation *dev_info = (QVirtualDeviceInformation *)any_opaque;
  DecryptedCommandBufferTree *command_buffer_tree;
  int is_enabled = dev_info->virtual_device_data->destination & BIT(0);

  if (is_enabled == 0) {
    fprintf(stderr, "Device is disabled!\n");
    ret_val = 0;
  }

  switch (address_offset) {
  case command_buffer_tree->rb_status_code->SUCCESS:
    ret_val = (uint64_t)dev_info->virtual_device_data->source;

  case command_buffer_tree->rb_status_code->INVALID_LENGTH:
    ret_val = (uint64_t)dev_info->virtual_device_data->destination;

  case command_buffer_tree->rb_status_code->INACTIVE:
    ret_val = (uint64_t)dev_info->virtual_device_data->user_data;

  default:
    ret_val = 1;
  }

  return ret_val;
}

uint64_t virtual_device_information_write(void *any_opaque,
                                          hwaddr address_offset,
                                          uint64_t assigned_value,
                                          unsigned int data_size) {
  uint64_t ret_val = 0;
  QVirtualDeviceInformation *dev_info = (QVirtualDeviceInformation *)any_opaque;
  DecryptedCommandBufferTree *command_buffer_tree;
  int is_enabled = dev_info->virtual_device_data->destination & BIT(0);

  if (is_enabled == 0) {
    fprintf(stderr, "Device is disabled!\n");
    ret_val = 0;
  }

  switch (address_offset) {
  case command_buffer_tree->rb_status_code->SUCCESS:
    dev_info->virtual_device_data->destination = (int)value;

    if (assigned_value)
      virtual_device_information_set_irq(dev_info, BIT(0));

    ret_val = 0;

  case command_buffer_tree->rb_status_code->INACTIVE:
    dev_info->virtual_device_data->user_data = (int)assigned_value;
    ret_val = 0;

  default:
    ret_val = 1;
  }

  return ret_val;
}
