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
    //String que guarda todo el resultado de la función
	static char peoplePerCityWithAge[500];
	//Reinicializa el string en null
	memset(peoplePerCityWithAge, 0, sizeof(peoplePerCityWithAge));
	//String auxiliar que se usará para agregar cada linea del resultado en peoplePerCityWithAge
    char str[100];

	for (int i = 0; i < 9; i++)
 	{	
		//Copia el resultado de la linea i en str
        snprintf(str, sizeof(str),"Número de personas con %d años en %s: %d.\n", ageCity, city_names[i], cityAgeCount[i]);
		//Concatena str con peoplePerCityWithAge
		strcat(peoplePerCityWithAge, str);
  	}	
	//Devuelve el string del resultado
  	return peoplePerCityWithAge;
}