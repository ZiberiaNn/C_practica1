#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"


void insertElement(item_t items[], int size, item_t element){
	for(int i = size; i >= size/2; i--)
	{
        items[i] = items[i-1];
        items[i].id = items[i].id +1;
	}
    items[(size/2)-1]=element; 
}