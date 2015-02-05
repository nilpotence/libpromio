#include <stdlib.h>

#include "list.h"

promio_list_t *	promio_list_create(){
	promio_list_t * list = (promio_list_t*) malloc(sizeof(promio_list_t));
	list->prev = NULL;
	list->next = NULL;
	list->val = NULL;
}

void promio_list_destroy(promio_list_t * list){
	promio_list_t * tmp = NULL;
	while(list != NULL){
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

promio_list_t * promio_list_push(promio_list_t * list, void * val){
	promio_list_t * elem = promio_list_create();
	elem->val = val;
	elem->next = list;
	list->prev = elem;
}
void				promio_list_add(promio_list_t * list, void * val);

void *				promio_list_pop(promio_list_t * list);