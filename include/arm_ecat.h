#ifndef ARM_ECAT_H
#define ARM_ECAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#include "ethercat.h"
#include "init_AEV.h"
#include "shm.h"

/** AEV drive CSP Mode inputs to master */
typedef struct PACKED
{
    /* PDO */
    uint16 stat_wd;   /* status word (0x6041) */
    int32 load_pos;    /* position actual value (0x6064) */ // same as load encoder position when active load encoder enabled
    int32 pos_err;    /* position error (0x60F4) */
    int32 act_vel;    /* actual velocity (0x606C) */
    int16 act_tau;    /* torque actual value (0x6077) */
    int32 load_vel;   /* load encoder velocity (0x2231) */
    // int32 load_pos;   /* load encoder position (0x2242) */
    int32 act_pos;   /* load encoder position (0x2240) */
    uint32 latching_fault; /* load latching fault (0x2183)*/
} motor_input;

/** AEV drive CSP Mode outputs from master */
typedef struct PACKED
{
    uint16 ctrl_wd;   /* control word (0x6040) */
    int32 tg_pos;     /* target position (0x607A) */
    int32 vel_off;    /* velocity offset (0x60B1) */
    int16 tau_off;    /* torque offset (0x60B2) */
} motor_output;

/** AEV slave class */
typedef struct
{
    uint16 slave_id;
    /* Input/output interface */
    motor_input *in_motor;
    motor_output *out_motor;
    /* Motor attributes */
    int32 init_pos_cnts;
    int32 load_init_pos_cnts;
    double counts_per_rad;
    double counts_per_rad_sec;
    double load_counts_per_rad;
    double load_counts_per_rad_sec;
    double units_per_nm;
} aev_slave;

/** EtherCAT slave class */
typedef struct
{
    aev_slave aev[AEV_NUM];
    struct timespec ts;
} ecat_slaves;

ecat_slaves *initEcatConfig(void *ifnameptr);
void add_timespec(struct timespec *ts, int64 addtime);
int64 ec_sync(int64 reftime, int64 cycletime);
int32 positionSDOread(uint16 slave_id);
int32 loadPositionSDOread(uint16 slave_id);
void pivGainSDOwrite(uint16 slave_id, uint16 Pp, uint16 Vp);
int armDriverErrorSDOcheck(uint16 slave_id);

#endif //ARM_ECAT_H