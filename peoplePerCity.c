#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};

void addPeoplePerCity(unsigned int cityNumber){
	cityCount[cityNumber] = cityCount[cityNumber]+1;
}

const char * printPeoplePerCity(){
	char arr[9][20] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston","Washington D.C.", "San Diego", "Austin", "Not found"};
	static char peoplePerCity[400];
	char str1[50], str2[50];
	for (int i = 0; i < 9; i++)
 	{	
 		sprintf(str1,"Número de personas en %s", arr[i]);
 		sprintf(str2,": %d.\n",cityCount[i]);
 		strcat(peoplePerCity, str1);
 		strcat(peoplePerCity, str2);
  	}	
  	return peoplePerCity;
}
