#ifndef TARDIS_H
#define TARDIS_H

/*----------------------------------------------*/
/* Includes */

#include "Arduino.h"
#include <Wire.h>

#include "buffer.h"
#include "dtmf.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------*/
/* Definitions */
#define TONE_SIZE 256

/*----------------------------------------------*/
/* Type definitions */
typedef struct
{
    uint8_t irq_flg;
}t_sysflgs;

/*----------------------------------------------*/
/* Function declarations */
void InitializeDTMF(void);

#ifdef __cplusplus
}
#endif /* extern __cplusplus */
#endif /* TARDIS_H */