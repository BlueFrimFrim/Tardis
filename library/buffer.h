#ifndef BUFFER_H
#define BUFFER_H

#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

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
void BufferInit(t_buffer *buffer, uint8_t *data, uint16_t size);
void BufferReset(t_buffer *buffer);
uint16_t BufferLength(t_buffer *buffer);
void BufferWrite(t_buffer *buffer, uint8_t data);
uint8_t BufferRead(t_buffer *buffer);

#ifdef __cplusplus
}
#endif /* extern __cplusplus */
#endif /* BUFFER_H */