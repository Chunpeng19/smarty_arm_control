#ifndef ARM_INIT_AEV_H
#define ARM_INIT_AEV_H

#include <stdio.h>
#include <stdlib.h>

#include "ethercat.h"

int SDO_write8(uint16 slave, uint16 index, uint8 subindex, uint8 value);
int SDO_write16(uint16 slave, uint16 index, uint8 subindex, uint16 value);
int SDO_write32(uint16 slave, uint16 index, uint8 subindex, uint32 value);
int mapMotorPDOs_callback(uint16 slaveIdx);
int initMotorACD(uint16 slaveIdx);

#endif //ARM_INIT_AEV_H