/**
 * @file list.c
 * @brief List functions
 *
 *  Created on: 1 janv. 2010
 *      Author: sylvain
 */
#include <stdlib.h>

#include "list.h"

/**
 * Create an empty list
 * @return empty list
 */
promio_list_t * promio_list_create(){
	promio_list_t * l;

	l = (promio_list_t*) malloc(sizeof(promio_list_t));
	l->first=EMPTY_LIST;
	l->size=0;

	return l;
}

/**
 * free a given list
 * @param list list to free
 */
void promio_list_destroy(promio_list_t * list){

	promio_list_elem_t * tmp;
	while(list->first != EMPTY_LIST){
		tmp = list->first->next;
		free(list->first);
		list->first=tmp;
	}

	free(list);
}

/**
 * create a new list cell
 * @param value value of the new cell
 * @param next pointer to the next cell of the new cell
 * @return the cell created
 */
static promio_list_elem_t * promio_list_createElem(void * value, promio_list_elem_t * next){
	promio_list_elem_t * l;
	l = (promio_list_elem_t*) malloc(sizeof(promio_list_elem_t));
	l->value = value;
	l->next = next;

	return l;
}

/**
 * free a given list cell
 * @param list list cell to free
 * @return return the next cel of the cell to free
 */
static promio_list_elem_t * promio_list_freeElem(promio_list_elem_t * list){
	promio_list_elem_t * l = list->next;
	free(list);
	return l;
}

/**
 * push an element at the begining of a given list
 * @param list list where to add element
 * @param value value to add
 */
void promio_list_push(promio_list_t * list, void * value){
	promio_list_elem_t * l = promio_list_createElem(value,list->first);
	list->first = l;
	list->size++;
}

/**
 * get the top element of a given list
 * @param list list where to get top element
 * @return the top element if exist, -1 otherwise
 */
void * promio_list_top(promio_list_t * list){
	if(list->first == EMPTY_LIST) return NULL;
	return list->first->value;
}

/**
 * pop the top element of a given list.
 * @param list list where to pop the top element
 * @return return the top element
 */
void *	promio_list_pop(promio_list_t * list){
	void * value;

	if(list->first == EMPTY_LIST) return NULL;

	value = list->first->value;
	list->first = promio_list_freeElem(list->first);

	list->size--;

	return value;
}

/**
 * add a value at the end of a given list
 * @param list list where to add element
 * @param value value to add
 */
void	promio_list_add(promio_list_t * list, void * value){

	promio_list_elem_t * tmp;

	if(list->first == EMPTY_LIST){
		list->first = promio_list_createElem(value,EMPTY_LIST);
	}else{
		tmp = list->first;
		while(tmp->next != EMPTY_LIST){
			tmp = tmp->next;
		}

		tmp->next = promio_list_createElem(value,EMPTY_LIST);
	}
	list->size++;
}

/**
 * Removes a given element from the list
 * @param list  list from which to remove element
 * @param value element to be removed
 */
void promio_list_remove(promio_list_t * list, void * value){
	promio_list_elem_t * tmp = list->first;
	promio_list_elem_t * prev = NULL;

	while(tmp != NULL){
		if(tmp->value == value){
			if(prev != NULL){
				prev->next = tmp->next;
			}else{
				list->first = tmp->next;
			}

			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}


/**
 * check if a given list is empty.
 * @param list list to check
 * @return 1 if list is empty, 0 otherwise
 */
int	promio_list_empty(promio_list_t * list){
	return list->first == EMPTY_LIST;
}

/**
 * iterate over a given list. apply a given function on each list value
 * @param list list to iterate
 * @param func func to apply on each elem
 * @param user_data user data given to the function
 */
void promio_list_iterate(promio_list_t * list, iterate_collection_func func, void * user_data){
	promio_list_elem_t * tmp;
	tmp = list->first;
	while(tmp != EMPTY_LIST){
		func(tmp->value,user_data);
		tmp = tmp->next;
	}
}


/**
 * Create a new list iterator for a given list
 * @param list list that will be iterated by the new iterator
 * @return iterator created
 */
promio_iterator_t * promio_iterator_create(promio_list_t * list){
	promio_iterator_t * it;
	it = (promio_iterator_t*) malloc(sizeof(promio_iterator_t));
	it->list = list;
	promio_iterator_reset(it);

	return it;
}

/**
 * Free a given iterator
 * @param it iterator to free
 */
void promio_iterator_destroy(promio_iterator_t * it){
	free(it);
}

/**
 * Reset position to -1 for a given iterator
 * @param it
 */
void promio_iterator_reset(promio_iterator_t * it){
	it->cur = EMPTY_LIST;
	it->prev = EMPTY_LIST;
	it->next = it->list->first;
	it->position = -1;
}

/**
 * Check if there is another value next the current one
 * for a given iterator
 * @param it iterator given
 * @return
 */
int promio_iterator_has_next(promio_iterator_t * it){
	return it->next != EMPTY_LIST;
}

/**
 * move a given iterator to it next value.
 * Warning : You must call list_it_has_next before
 * call this function, if an iterator has no next value,
 * this function will throw a Segment Fault
 * @param it iterator to forward
 * @return the next value of the given iterator
 */
void *	promio_iterator_next(promio_iterator_t * it){
	it->prev = it->cur;
	it->cur = it->next;
	it->next = it->next->next;

	it->position++;

	return it->cur->value;
}

/**
 * return the current position of a given iterator
 * @param it iterator
 * @return the current position
 */
int promio_iterator_position(promio_iterator_t * it){
	return it->position;
}

/**
 * Remove the current element of a given iterator,
 * and move iterator to the previous val
 * @param it given iterator
 */
void promio_iterator_remove(promio_iterator_t * it){

	if(it->position == 0){
		it->list->first = promio_list_freeElem(it->cur);
		it->cur = EMPTY_LIST;
		it->next = it->list->first;
	}
	else{
		it->prev->next = promio_list_freeElem(it->cur);
		it->cur = it->prev;
		it->next = it->cur->next;
	}

	it->list->size--;

	it->position--;
}

/**
 * add an element in a given iterator, and place iterator
 * on the new value added
 * @param it given iterator
 * @param value value to add
 */
void promio_iterator_add(promio_iterator_t * it, void * value){

	if(it->position == -1) return;
	if(it->position == 0){
		it->list->first = promio_list_createElem(value,it->list->first);
		it->cur = it->list->first;
		it->next = it->cur->next;
	}else{
		it->prev = promio_list_createElem(value,it->cur);
		it->cur = it->prev->next;
		it->next = it->cur->next;
	}

	it->list->size++;
}
