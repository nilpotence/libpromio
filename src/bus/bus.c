#include <stdlib.h>

#include "bus.h"



promio_bus_t * promio_bus_create(){
	promio_bus_t * bus = (promio_bus_t*) malloc(sizeof(promio_bus_t));
	bus->id = 0;

	return bus;
}
void promio_bus_destroy(promio_bus_t * bus){
	free(bus);
}

void promio_bus_send(promio_bus_t * bus, const char msg[]){
	//TODO
}