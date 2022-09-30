/* Eng.Mohamed Gamal */

#include "lifo.h"



buffer_status lifo_init (lifo* fo , element_type* buf, unsigned int length)
{
	if (buf == NULL)
		return lifo_null;

	fo->head = buf;
	fo->base = buf;
	fo->count = 0;
	fo->length = length;

	return lifo_no_error;
}

buffer_status lifo_check_full (lifo* fo)
{
	if (fo->count == fo->length)
		return  lifo_full;

	/*
	if (fo->head == ( (fo->base) + ( (fo->length) * (sizeof(element_type) ) ) ) ){
		return  lifo_full;
	}*/

	if ( (!fo->head) || (!fo->base))
		return  lifo_null;

	if ((fo->count == 0 ))
		return  lifo_empty;

	return lifo_no_error;
}

buffer_status lifo_add (lifo* fo , element_type item)
{
	if ( lifo_check_full (fo) == lifo_full)
		return  lifo_full;

	if ( (lifo_check_full (fo) == lifo_null) || (!fo))
		return  lifo_null;

	if (fo->count != fo->length){
		fo->head++;
		*(fo->head) = item;
		fo->count++;
	}
	return lifo_no_error;
}

buffer_status lifo_get (lifo* fo , element_type* item)
{
	if ( (lifo_check_full (fo) == lifo_null) || (!fo))
		return  lifo_null;

	if ( lifo_check_full (fo) == lifo_empty)
		return  lifo_empty;


	*item = *(fo->head);
	fo->count--;
	if (fo->head != fo->base)
		fo->head--;


	return lifo_no_error;
}

void print (lifo* fo)
{

	if ( lifo_check_full (fo) == lifo_empty)
		Mprint("Empty LIfo :) \n");

	element_type* temp = fo->head;
	int t = 0;

	while( temp != fo->base){
		Mprint("the element (%d) is %d \n" , t+1 ,*temp );
		temp--;
		t++;
	}
	if(t == fo->length)
		Mprint("Lifo is full :) \n");
}

void print_pop (lifo* fo){

	element_type temp;

	if ( lifo_check_full (fo) == lifo_empty)
		Mprint("Empty LIfo :) \n");

	while( fo->count ){

		lifo_get(fo,&temp);
		Mprint("the element (%d) %d \n" ,fo->count ,temp);
	}
	Mprint("Empty LIfo :) \n===========================\n");
}

