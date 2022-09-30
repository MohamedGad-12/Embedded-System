/* Eng.Mohamed Gamal */

#include "fifo.h"



buffer_status fifo_init (fifo* fo , element_type* buf, unsigned int length)
{
	if (buf == NULL)
		return fifo_null;

	fo->head = buf;
	fo->base = buf;
	fo->tail = buf;
	fo->count = 0;
	fo->length = length;

	return fifo_no_error;
}

buffer_status fifo_check_full (fifo* fo)
{
	if (fo->count == fo->length)
		return  fifo_full;

	/*
	if (fo->head == ( (fo->base) + ( (fo->length) * (sizeof(element_type) ) ) ) ){
		return  fifo_full;
	}*/

	if ( (!fo->head) || (!fo->base) || (!fo->tail) )
		return  fifo_null;

	if ((fo->count == 0 ))
		return  fifo_empty;

	return fifo_no_error;
}

buffer_status fifo_enqueue  (fifo* fo , element_type item)
{
	if ( fifo_check_full (fo) == fifo_full)
		return  fifo_full;

	if ( (fifo_check_full (fo) == fifo_null) || (!fo))
		return  fifo_null;

	*(fo->tail) = item;
	fo->count++;
	if (fo->tail == ( (fo->base) + ( ((fo->length)-1) * (sizeof(element_type) ) ) ) )
		fo->tail = fo->base;
	else
		fo->tail++;

	return fifo_no_error;
}

buffer_status fifo_dequeue   (fifo* fo , element_type* item)
{
	if ( (fifo_check_full (fo) == fifo_null) || (!fo))
		return  fifo_null;

	if ( fifo_check_full (fo) == fifo_empty)
		return  fifo_empty;


	*item = *(fo->head);
	fo->count--;
	if (fo->head == ( (fo->base) + ( (fo->length) * (sizeof(element_type) ) ) ) )
		fo->head = fo->base;
	else
		fo->head++;


	return fifo_no_error;
}

void print (fifo* fo)
{

	if ( fifo_check_full (fo) == fifo_empty)
		Mprint("Empty fifo :) \n");

	element_type* temp = fo->head;
	int t = 0;

	for(t = 0 ; t< fo->count ; t++){

		if (temp == ( (fo->base) + ( (fo->length) * (sizeof(element_type) ) ) ) )
			temp = fo->base;

		Mprint("the element (%d) is %d \n" , t+1 ,*temp );
		temp++;
	}
	if(t == fo->length)
		Mprint("fifo is full :) \n");
}


