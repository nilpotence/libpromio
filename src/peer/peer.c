#include <stdlib.h>
#include <string.h>

#include "peer.h"


promio_peer_t * promio_peer_create(const char name[]){
	promio_peer_t * peer = (promio_peer_t*) malloc(sizeof(promio_peer_t));
	strcpy(peer->name, name);

	return peer;
}


void promio_peer_destroy(promio_peer_t * peer){
	free(peer);
}


void promio_peer_start(promio_peer_t * peer){

}

void promio_peer_stop(promio_peer_t * peer){

}