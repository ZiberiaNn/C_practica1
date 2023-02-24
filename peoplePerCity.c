#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peoplePerCity.h"
#include "base_struct.h"

unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};

const char * printPeoplePerCity(item_t items[], int size){
	//String que retorna el resultado
	static char peoplePerCity[500];
	//Reinicializa el string en "" (null)
	memset(peoplePerCity, 0, sizeof(peoplePerCity));

	//Función que añade el número de habitantes por ciudad en el array cityCount
	addPeoplePerCity(items, size);

	//String auxiliar que se usará para agregar cada linea del resultado en el string peoplePerCity
	char str[250];
	for (int i = 0; i < 9; i++)
 	{	
		//Copia el resultado de la linea i en str
		snprintf(str, sizeof(str), "Número de personas en %s", city_names[i]);
		//Concatena str con peoplePerCity
 		strcat(peoplePerCity, str);

		snprintf(str, sizeof(str),": %d.\n",cityCount[i]);
 		strcat(peoplePerCity, str);
  	}	
  	return peoplePerCity;
}

void addPeoplePerCity(item_t items[], int size){
	//Reinicializa el array cityCount en 0 cada vez que se llama la función
	memset(cityCount, 0, sizeof(cityCount));
	for(int i = 0; i < size; i++)
	{
		cityCount[items[i].city] = cityCount[items[i].city]+1;
	}
}

