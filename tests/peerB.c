#include <stdio.h>
#include <stdlib.h>

#include <promio/utils/list.h>
#include <promio/peer/peer.h>


int main(int argc, char * argv[]){

	promio_peer_t * peer = promio_peer_create("PeerB");

	printf("Peer %s created !\n", peer->name);

	promio_output_t * output1 = promio_output_create(peer, "ctrl.speed", 1);
	promio_input_t * input1 = promio_input_create(peer, "common.led", 3);

	printf("\n%s I/Os :\n", peer->name);
	promio_iterator_t * it = promio_iterator_create(peer->ios);
	while(promio_iterator_has_next(it)){
		promio_io_t * io = (promio_io_t*)promio_iterator_next(it);

		if(io->type == PROMIO_TYPE_INPUT)
			printf("	input : ");
		else
			printf("	output : ");

		printf("%s, size : %i\n", io->name, io->size);
	}
	promio_iterator_destroy(it);

	promio_input_destroy(peer, input1);
	promio_output_destroy(peer, output1);
	promio_peer_destroy(peer);

	printf("\nGood Bye !\n");

	return EXIT_SUCCESS;
}