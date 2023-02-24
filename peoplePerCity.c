#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peoplePerCity.h"
#include "base_struct.h"

unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};

const char * printPeoplePerCity(item_t items[], int size){
	static char peoplePerCity[500];
	memset(peoplePerCity, 0, sizeof(peoplePerCity));

	addPeoplePerCity(items, size);

	char str[250];
	for (int i = 0; i < 9; i++)
 	{	
		snprintf(str, sizeof(str), "Número de personas en %s", city_names[i]);
 		strcat(peoplePerCity, str);

		snprintf(str, sizeof(str),": %d.\n",cityCount[i]);
 		strcat(peoplePerCity, str);
  	}	
  	return peoplePerCity;
}

void addPeoplePerCity(item_t items[], int size){
	memset(cityCount, 0, sizeof(cityCount));
	for(int i = 0; i < size; i++)
	{
		cityCount[items[i].city] = cityCount[items[i].city]+1;
	}
}

