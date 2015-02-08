#ifndef __PROMIO_BUS_H
#define __PROMIO_BUS_H


typedef struct{
	int id;
} promio_bus_t;

promio_bus_t *		promio_bus_create();
void				promio_bus_destroy(promio_bus_t * bus);

void				promio_bus_send(promio_bus_t * bus, const char msg[]);
void				promio_bus_recv(promio_bus_t * bus, recv_callback_func * func);


#endif