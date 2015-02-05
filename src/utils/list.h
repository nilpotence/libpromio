#ifndef __PROMIO_LIST_H
#define __PROMIO_LIST_H

typedef struct promio_list_elem_t {
	void * val;

	struct promio_list_elem_t * prev;
	struct promio_list_elem_t * next;
} promio_list_t;


promio_list_t *		promio_list_create();
void				promio_list_destroy(promio_list_t * list);

promio_list_t *		promio_list_push(promio_list_t * list, void * val);
void				promio_list_add(promio_list_t * list, void * val);

void *				promio_list_pop(promio_list_t * list);



#endif