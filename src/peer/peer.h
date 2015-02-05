#ifndef __PROMIO_PEER_H
#define __PROMIO_PEER_H

typedef struct{
	char name[255];
} promio_peer_t;

promio_peer_t *		promio_peer_create(const char name[]);
void				promio_peer_destroy(promio_peer_t * peer);

void				promio_peer_start(promio_peer_t * peer);
void				promio_peer_stop(promio_peer_t * peer);


#endif