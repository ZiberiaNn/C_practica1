#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peoplePerCity.h"
#include "base_struct.h"

unsigned int cityAgeCount[9] = {0,0,0,0,0,0,0,0,0};

const char * printPeoplePerCityWithAge(item_t items[], int size){
	memset(cityAgeCount, 0, sizeof(cityAgeCount));
    int ageCity;
    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad a buscar: ");
    scanf("%d", &ageCity);
    for(int i = 0; i < size; i++)
	{
        if(items[i].age == ageCity){
            cityAgeCount[items[i].city]++;
        }
	}

	static char peoplePerCityWithAge[500];
	memset(peoplePerCityWithAge, 0, sizeof(peoplePerCityWithAge));
    char str[100];

	for (int i = 0; i < 9; i++)
 	{	
        snprintf(str, sizeof(str),"Número de personas con %d años en %s: %d.\n", ageCity, city_names[i], cityAgeCount[i]);
		strcat(peoplePerCityWithAge, str);
  	}	
  	return peoplePerCityWithAge;
}