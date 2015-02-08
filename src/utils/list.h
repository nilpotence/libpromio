/**
 * @file list.h
 * @brief List collection
 *
 *  Created on: 1 janv. 2010
 *      Author: sylvain
 */

#ifndef __PROMIO_LIST_H
#define __PROMIO_LIST_H

#define EMPTY_LIST NULL

	/**
	 * @struct ListCell
	 * That structure represent one cell of a list
	 */
	typedef struct promio_list_elem_t{
		void * value; /*!< element contained in this cell */
		struct promio_list_elem_t *next; /*!< next cell */
	} promio_list_elem_t;

	/**
	 * @struct List
	 * This structure represent a simple linked list
	 */
	typedef struct {
		promio_list_elem_t * first; /*!< first cell of the list */
		int size; /*!< number of cells in the list */
	} promio_list_t;

	/**
	 * @struct ListIterator
	 * Used to iterate over a list in an efficient way
	 */
	typedef struct {
		promio_list_t * list; /*!< list to iterate */

		promio_list_elem_t * cur; /*!< current cell of the list iterated */

		promio_list_elem_t * prev; /*!< previous cell of the list iterated */
		promio_list_elem_t * next; /*!< next cell of the list iterated */

		int position; /*!< current position of the iterator in the list */

	} promio_list_iterator_t;


	typedef void (*iterate_collection_func)(void * elem, void * data); /*!< function applied on each element of a collection */


	promio_list_t *		promio_list_create();
	void				promio_list_destroy(promio_list_t * list);

	int					promio_list_empty(promio_list_t * list);

	void				promio_list_push(promio_list_t * list, void * value);
	void				promio_list_add(promio_list_t * list, void * value);
	void				promio_list_remove(promio_list_t * list, void * value);

	void *				promio_list_top(promio_list_t * list);
	void *				promio_list_pop(promio_list_t * list);

	void				promio_list_iterate(promio_list_t * list, iterate_collection_func func, void * user_data);


	promio_list_iterator_t *		promio_list_it_create(promio_list_t * list);
	void							promio_list_it_destroy(promio_list_iterator_t * it);
	void							promio_list_it_reset(promio_list_iterator_t * it);

	int 							promio_list_it_has_next(promio_list_iterator_t * it);
	int								promio_list_it_position(promio_list_iterator_t * it);

	void *							promio_list_it_next(promio_list_iterator_t * it);

	void							promio_list_it_remove(promio_list_iterator_t * it);
	void							promio_list_it_add(promio_list_iterator_t * it, void * value);

#endif /* __PROMIO_LIST_H */
