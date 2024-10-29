#ifndef PCIE_H
#define PCIE_H

#include <stdint.h>

#define PCIE_FUNCTION_BRIDGE 0x0
#define PCIE_FUNCTION_USB_CONTROLLER 0x1
#define PCIE_FUNCTION_SATA_CONTROLLER 0x3

#define PCIE_VENDOR_ID_INTEL 0x8086

typedef struct {
    uint16_t vendor_id;
    uint16_t device_id;
    uint8_t bus;
    uint8_t device;
    uint8_t function;
} pci_device_t;

#endif
