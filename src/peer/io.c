#include <stdlib.h>
#include <string.h>

#include "peer.h"


promio_io_init(promio_io_t * io, promio_peer_t * peer, const char name[], int size, int type){
	strcpy(io->name, name);
	io->size = size;
	io->type = type;

	promio_peer_register_io(peer, io);
}

promio_io_reset(promio_peer_t * peer, promio_io_t *io){
	promio_peer_unregister_io(peer, io);
}

promio_input_t * promio_input_create(promio_peer_t * peer, const char name[], int size){
	promio_input_t * input = (promio_input_t*) malloc(sizeof(promio_input_t));
	promio_io_init((promio_io_t*) input, peer, name, size, PROMIO_TYPE_INPUT);

	return input;
}

void promio_input_destroy(promio_peer_t *peer, promio_input_t * input){
	promio_io_reset(peer, (promio_io_t*) input);
	free(input);
}

promio_output_t * promio_output_create(promio_peer_t * peer, const char name[], int size){
	promio_output_t * output = (promio_output_t*) malloc(sizeof(promio_output_t));
	promio_io_init((promio_io_t*) output, peer, name, size, PROMIO_TYPE_OUTPUT);

	return output;
}

void promio_output_destroy(promio_peer_t * peer, promio_output_t * output){
	promio_io_reset(peer, (promio_io_t*) output);
	free(output);
}