#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __iomem                                                                \
  __attribute__((                                                              \
      noderef,                                                                 \
      address_space(2))) // temporary definition of __iomem from sparse

#define SLICE_ARRAY_SIZE 16384

struct SlicedUserMemoryMap {
  enum {
    VIRT_GPIO,        // This redistributor space allows up to 2*64kB*123 CPUs
    VIRT_SECURE_UART, // This redistributor space allows up to 2*64kB*123 CPUs
    VIRT_SECURE_MEM,  // ...repeating for a total of NUM_VIRTIO_TRANSPORTS, each
                      // of that size
    VIRT_USER_DATA,   // Our own user-data to bundle and siphon through
  };                  // have an enum inside a struct to next it further
} SlicedUserMemoryMap; // write a struct over a typedef struct for private usage

struct MemoryMapEntry {
  enum {
    // Space up to 0x8000000 is reserved for a boot ROM
    VIRT_FLASH,
    VIRT_CPUPERIPHS,
    // GIC distributor and CPU interfaces sit inside the CPU peripheral space
    VIRT_GIC_DIST,
    VIRT_GIC_CPU,
    VIRT_GIC_V2M,
    // The space in between here is reserved for GICv3 CPU/vCPU/HYP
    VIRT_GIC_ITS,
    // This redistributor space allows up to 2*64kB*123 CPUs
    VIRT_GIC_REDIST,
    VIRT_UART,
    VIRT_RTC,
    VIRT_FW_CFG,
    VIRT_MMIO,
    // ...repeating for a total of NUM_VIRTIO_TRANSPORTS, each of that size
    VIRT_PLATFORM_BUS,
    VIRT_PCIE_MMIO,
    VIRT_PCIE_PIO,
    VIRT_PCIE_ECAM,
    VIRT_MEM,
    // Second PCIe window, 512GB wide at the 512GB boundary
    VIRT_PCIE_MMIO_HIGH,
  };
} MemoryMapEntry;

struct MemoryDevice {
  struct device *device_pt;
  char *user_data; // supposed __iomem *io
} MemoryDevice;

struct DeviceAttribute {
  int device_id;
  char *stored_command[];
} DeviceAttribute;

struct VirtualTable {
  struct serial_bus *bus;
  char *destination;
  char *source;
  char *user_data;
  size_t *data_size;
} VirtualTable;

size_t memory_device_store_command(struct MemoryDevice *device_pt,
                                   struct DeviceAttribute device_attr,
                                   const char *buffer_string[],
                                   size_t t_length) {
  return t_length;
}

int main(int argc, char *argv[]) { return 0; }
