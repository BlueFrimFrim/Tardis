#ifndef TARDIS_H
#define TARDIS_H

/* Version: 0v00 */

/*----------------------------------------------*/
/* Includes */

#include "Arduino.h"
#include <Wire.h>

#include "buffer.h"
#include "dtmf.h"

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
extern void InitializeDTMF(void);

#endif /* TARDIS_H */