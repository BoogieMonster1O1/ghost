#ifndef PCIE_H
#define PCIE_H

#include <stdint.h>

typedef struct {
    uint16_t vendor_id;
    uint16_t device_id;
    uint8_t bus;
    uint8_t device;
    uint8_t function;
} pci_device_t;

#endif
