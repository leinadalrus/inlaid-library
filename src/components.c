#include "../inc/i386_x86_64_architecture.h"

inline const int derive_platform_derived_data(
  QVirtualDeviceData *virtual_device_data,
  QVirtualDeviceInformation *device_info)
{
  return 0;
}

inline const int attribute_sysfs_group(
  LocatorService *locator_service,
  QVirtualDeviceInformation *device_info)
{
  QVirtualDeviceData *cloned_virtual_device_data = &device_info->virtual_device_data;
  DecryptedCommandBuffer *decrypted_command_buffer = &locator_service->decrypted_command_buffer;
  return 0;
}
