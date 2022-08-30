#ifndef RDDA_BASE_H
#define RDDA_BASE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rdda_ecat.h"
#include "shm.h"

void rdda_update(ecat_slaves *ecatSlaves, Rdda *rdda);
void rddaStop(ecat_slaves *ecatSlaves);
int rdda_gettime(ecat_slaves *ecatSlaves);
void rdda_sleep(ecat_slaves *ecatSlaves, int cycletime);
void initRddaStates(ecat_slaves *ecatSlaves, Rdda *rdda);
double saturation(double max_torque, double raw_torque);
int errorCheck(ecat_slaves *ecatSlaves);

#endif //RDDA_BASE_H