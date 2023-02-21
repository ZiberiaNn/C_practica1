#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.c"
#include "peoplePerCity.c"
#include "getById.c"
#include "lista_ligada.c"
#include "averageIncome.c"
#include "probabilitySick.c"
#include "peoplePerCityWithAge.c"

const int SIZE = 150000;

int main(int argc, char *argv[]){
    FILE * fp, *fileOut;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    	exit(EXIT_FAILURE);
    item_t element;
    int line_number = 0;
    item_t items[SIZE];
	Node_Item *head, *temp;
    while ((read = getline(&line, &len, fp)) != -1) {
   	if(line_number > 0){
		char *token;
		char *s = NULL;
   		int i=0;
   		while ((token = strtok_r(line , ",", &line))) {
       		city_t result_city;
			gender_t result_gender;
			bool_t result_illness;
			switch(i){
				case 0:
					element.id = atoi(token);
					break;
				case 1:
					result_city = get_city_t(token);
					if(result_city == E)
						printf("City not defined\n");
					element.city = result_city;
					break;
				case 2:
					result_gender = get_gender_t(token);
					if(result_gender == NO)
						printf("Gender not defined\n");
					element.gender = result_gender;
					break;
				case 3:
					element.age = atoi(token);
					break;
				case 4:
					element.income = atoi(token);
					break;
				case 5:
					s = token;
                    while(*s != '\n') {
                            ++s;
			        }
                    *s = '\0';
					result_illness = get_illness_t(token);
					if(result_illness == fuzzy)
						printf("Value not defined\n");
					element.illness = result_illness;
					break;
			}
			i++;
    		}
			items[line_number - 1] = element;
			//insert(&head, &element);
    	}
	line = NULL;
	line_number++;
    }
	//head = reverseList(head);
	//printList(head);
	//probability_disease(50, head);
	//insert_middle(head);
	//Node_Item *nodeFound=search_by_id(head, 75000);
	//printf("id: %d, ciudad: %s, edad: %d, genero: %s, ingresos: %d , enfermo:%s  \n", nodeFound->data.id, city_names[nodeFound->data.city], nodeFound->data.age, gender_names[nodeFound->data.gender], nodeFound->data.income, illness_values[nodeFound->data.illness] );
	
	fileOut = fopen("results.txt","w");
	fprintf(fileOut,"%s",printPeoplePerCity(items, SIZE));

	const char * resultGetById = getElementById(items, 149998);
	fprintf(fileOut,"%s",resultGetById);
	free(resultGetById);

	// Guarda el promedio de ingresos por ciudad en el documento results.txt
	//fprintf(fileOut,"%s",printAverageIncome(items, SIZE));
	//fprintf(fileOut,"%s",printProbabilitySick(items, SIZE));
	//fprintf(fileOut,"%s",printPeoplePerCityWithAge(items, SIZE));
	//Quitar esta linea cuando se corrija la impresión en el documento.
	printAverageIncome(items, SIZE);
	printProbabilitySick(items, SIZE);
	printPeoplePerCityWithAge(items, SIZE);
	//---------------------------------------------
	
   	fclose(fileOut);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

