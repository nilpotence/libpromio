#ifndef __PROMIO_IO_H
#define __PROMIO_IO_H

#include "peer.h"

typedef struct{
	char name[255];
	int size;
	promio_peer_t * peer;
} promio_io_t;

typedef struct{
	promio_io_t base;

} promio_input_t;

typedef struct{
	promio_io_t base;

} promio_output_t;


promio_input_t *	promio_input_create(promio_peer_t * peer, const char name[], int size);
void				promio_input_destroy(promio_input_t * input);

promio_output_t *	promio_output_create(promio_peer_t * peer, const char name[], int size);
void				promio_output_destroy(promio_output_t * output);

#endif