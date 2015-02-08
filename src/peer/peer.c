#include <stdlib.h>
#include <string.h>

#include "peer.h"


promio_peer_t * promio_peer_create(const char name[]){
	promio_peer_t * peer = (promio_peer_t*) malloc(sizeof(promio_peer_t));
	strcpy(peer->name, name);

	peer->ios = promio_list_create();

	return peer;
}


void promio_peer_destroy(promio_peer_t * peer){
	promio_list_destroy(peer->ios);
	free(peer);
}


void promio_peer_start(promio_peer_t * peer){

}

void promio_peer_stop(promio_peer_t * peer){

}

void promio_peer_register_io(promio_peer_t * peer, promio_io_t * io){
	promio_list_push(peer->ios, (void *) io);
}

void promio_peer_unregister_io(promio_peer_t * peer, promio_io_t * io){
	promio_list_remove(peer->ios, (void *) io);
}