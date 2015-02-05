#include <stdlib.h>
#include <string.h>

#include "io.h"


promio_io_init(promio_io_t * io, promio_peer_t * peer, const char name[], int size){
	strcpy(io->name, name);
	io->size = size;
	io->peer = peer;
}


promio_input_t * promio_input_create(promio_peer_t * peer, const char name[], int size){
	promio_input_t * input = (promio_input_t*) malloc(sizeof(promio_input_t));
	promio_io_init((promio_io_t*) input, peer, name, size);

	return input;
}

void promio_input_destroy(promio_input_t * input){
	free(input);
}

promio_output_t * promio_output_create(promio_peer_t * peer, const char name[], int size){
	promio_output_t * output = (promio_output_t*) malloc(sizeof(promio_output_t));
	promio_io_init((promio_io_t*) output, peer, name, size);

	return output;
}

void promio_output_destroy(promio_output_t * output){
	free(output);
}