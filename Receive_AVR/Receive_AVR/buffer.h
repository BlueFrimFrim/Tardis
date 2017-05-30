#ifndef BUFFER_H
#define BUFFER_H

/* Version: 0v00 */

#include "Arduino.h"

/*----------------------------------------------*/
/* Type definitions */
typedef struct
{
	uint16_t len;
	uint16_t wr_ptr;
	uint16_t rd_ptr;
	uint16_t buff_size;
	uint8_t *data;
} t_buffer;

/*----------------------------------------------*/
/* Function declarations */
extern void BufferInit(t_buffer *buffer, uint8_t *data, uint16_t size);
extern void BufferReset(t_buffer *buffer);
extern uint16_t BufferLength(t_buffer *buffer);
extern void BufferWrite(t_buffer *buffer, uint8_t data);
extern uint8_t BufferRead(t_buffer *buffer);

#endif /* BUFFER_H */