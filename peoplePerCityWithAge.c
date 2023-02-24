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


	static char peoplePerCityWithAge[] = "";
	//char *strCityAge;
	//size_t nbytesCity;
	for (int i = 0; i < 9; i++)
 	{	
        printf("Número de personas con %d años en %s: %d.\n", ageCity, city_names[i], cityAgeCount[i]);
/*
		nbytesCity = snprintf(NULL, 0, "Número de personas con %d años en %s", ageCity, city_names[i]) + 1;
		strCityAge = malloc(nbytesCity);
		snprintf(strCityAge, nbytesCity, "Número de personas con %d años en %s", ageCity, city_names[i]);
 		strcat(peoplePerCityWithAge, strCityAge);

		nbytesCity = snprintf(NULL, 0,": %d.\n",cityAgeCount[i]) + 1;
		strCityAge = malloc(nbytesCity);
		snprintf(strCityAge, nbytesCity,": %d.\n",cityAgeCount[i]);
 		strcat(peoplePerCityWithAge, strCityAge);
*/
  	}	
	//free(strCityAge);
  	return peoplePerCityWithAge;
}