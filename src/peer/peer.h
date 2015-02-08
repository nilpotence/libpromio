#ifndef __PROMIO_PEER_H
#define __PROMIO_PEER_H


#include "../utils/list.h"

/*========== PEER STRUCT ==============*/
typedef struct{
	char name[255];
	promio_list_t * ios;
} promio_peer_t;


/*========== IO STRUCT ================*/
#define PROMIO_TYPE_INPUT 0
#define PROMIO_TYPE_OUTPUT 1

typedef struct{
	char name[255];
	int size;
	int type;
} promio_io_t;

typedef struct{
	promio_io_t base;

} promio_input_t;

typedef struct{
	promio_io_t base;

} promio_output_t;



/*================ PEER FUNCTIONS ===================*/
promio_peer_t *		promio_peer_create(const char name[]);
void				promio_peer_destroy(promio_peer_t * peer);

void				promio_peer_start(promio_peer_t * peer);
void				promio_peer_stop(promio_peer_t * peer);

void				promio_peer_register_io(promio_peer_t * peer, promio_io_t *io);
void				promio_peer_unregister_io(promio_peer_t * peer, promio_io_t *io);


/*================== IO FUNCTIONS ===================*/
promio_input_t *	promio_input_create(promio_peer_t * peer, const char name[], int size);
void				promio_input_destroy(promio_peer_t * peer, promio_input_t * input);

promio_output_t *	promio_output_create(promio_peer_t * peer, const char name[], int size);
void				promio_output_destroy(promio_peer_t * peer, promio_output_t * output);



#endif