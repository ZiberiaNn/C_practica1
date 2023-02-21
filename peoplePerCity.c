#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peoplePerCity.h"

unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};

const char * printPeoplePerCity(item_t items[], int size){
	iterateItems(items, size);

	char arr[9][20] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston","Washington D.C.", "San Diego", "Austin", "Not found"};
	static char peoplePerCity[0];
	char *str;
	size_t nbytes;
	for (int i = 0; i < 9; i++)
 	{	
		nbytes = snprintf(NULL, 0, "Número de personas en %s", arr[i]) + 1; /*  find out the size to use. +1 for the '\0' */
		str = malloc(nbytes);
		snprintf(str, nbytes, "Número de personas en %s", arr[i]);
 		strcat(peoplePerCity, str);

		nbytes = snprintf(NULL, 0,": %d.\n",cityCount[i]) + 1; /*  find out the size to use. +1 for the '\0' */
		str = malloc(nbytes);
		snprintf(str, nbytes,": %d.\n",cityCount[i]);
 		strcat(peoplePerCity, str);
  	}	
	free(str);
  	return peoplePerCity;
}

void iterateItems(item_t items[], int size){
	for(int i = 0; i < size; i++)
	{
		addPeoplePerCity(items[i].city);
	}
}

void addPeoplePerCity(unsigned int cityNumber){
	cityCount[cityNumber] = cityCount[cityNumber]+1;
}