#include "buffer.h"

void
BufferInit(t_buffer *buffer, volatile uint8_t *data, uint16_t size)
{
	buffer->len = 0;
	buffer->rd_ptr = 0;
	buffer->wr_ptr = 0;
	buffer->buff_size = size;
	buffer->data = data;

	buffer->command = 0;
}

void
BufferReset(t_buffer *buffer)
{
	buffer->len = 0;
	buffer->rd_ptr = 0;
	buffer->wr_ptr = 0;

	Serial.println(F("Buffer reset"));
}

uint16_t
BufferLength(t_buffer *buffer)
{
	return buffer->len;
}

void
BufferWrite(t_buffer *buffer, uint8_t data)
{
	buffer->data[buffer->wr_ptr] = data;
	buffer->wr_ptr = (++buffer->wr_ptr) % buffer->buff_size;
	buffer->len++;
}

uint8_t
BufferRead(t_buffer *buffer)
{
	uint8_t data_in = 0;

	data_in = buffer->data[buffer->rd_ptr];
	buffer->rd_ptr = (++buffer->rd_ptr) % buffer->buff_size;
	buffer->rd_ptr--;

	return data_in;
}