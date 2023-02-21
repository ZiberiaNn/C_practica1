#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peoplePerCity.h"
#include "base_struct.h"

unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};

const char * printPeoplePerCity(item_t items[], int size){
	addPeoplePerCity(items, size);

	static char peoplePerCity[] = "";
	char *str;
	size_t nbytes;
	for (int i = 0; i < 9; i++)
 	{	
		nbytes = snprintf(NULL, 0, "Número de personas en %s", city_names[i]) + 1; /*  find out the size to use. +1 for the '\0' */
		str = malloc(nbytes);
		snprintf(str, nbytes, "Número de personas en %s", city_names[i]);
 		strcat(peoplePerCity, str);

		nbytes = snprintf(NULL, 0,": %d.\n",cityCount[i]) + 1; /*  find out the size to use. +1 for the '\0' */
		str = malloc(nbytes);
		snprintf(str, nbytes,": %d.\n",cityCount[i]);
 		strcat(peoplePerCity, str);
  	}	
	free(str);
  	return peoplePerCity;
}

void addPeoplePerCity(item_t items[], int size){
	for(int i = 0; i < size; i++)
	{
		cityCount[items[i].city] = cityCount[items[i].city]+1;
	}
}

