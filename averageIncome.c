#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"
#include "peoplePerCity.h"
#include <setjmp.h>

jmp_buf env;

// Calculate the average income of the people in a city and with a certain age

// Contiene el promedio de ingresos de las personas en una ciudad
unsigned int averageIncome[9] = {0,0,0,0,0,0,0,0,0};

const char * printAverageIncome(item_t items[], int size, int ageMinimum, int ageMaximum, int cityAverageIncome){

    if(ageMaximum < ageMinimum){
        printf("Edad máxima no puede ser menor que edad mínima\n");
        longjmp(env, 1);
    }
    if(ageMaximum <= 0 || ageMinimum <= 0){
        printf("Los valores deben ser positivos\n");
        longjmp(env, 1);
    }
    
    memset(averageIncome, 0, sizeof(averageIncome));

    int cityCountPerAge[9] = {0,0,0,0,0,0,0,0,0};
    // Pide la edad minima y maxima por consola
    if(cityAverageIncome>8){
        cityAverageIncome = 8;
    }
    // Valida que la edad del elemento se encuentra entre la edad minima y maxima
    // Y suma el ingreso de la persona a la ciudad correspondiente
    for(int i = 0; i<size; i++){
        if(items[i].age >= ageMinimum && items[i].age <= ageMaximum){
            averageIncome[items[i].city] += items[i].income;
            cityCountPerAge[items[i].city]++;
        }
    }

    //Crea un string para el resultado general de la función
    static char averageIncomePerCity[500];
    //Reinicializa el string en null
    memset(averageIncomePerCity, 0, sizeof(averageIncomePerCity));
    //String auxiliar que sirve para concatenar cada linea en el string del resultado general
    char str[100];

    int i = cityAverageIncome;
    if(cityCountPerAge[i] == 0){
        //Guarda el resultado i en str
        snprintf(str, sizeof(str), "No hay personas en %s en el rango de edad ingresado.\n", city_names[i]);
        //Concatena str con el resultado general
        strcat(averageIncomePerCity, str);
    }
    //Guarda el resultado i en str
    averageIncome[i] = averageIncome[i]/cityCountPerAge[i]; 
    snprintf(str, sizeof(str), "Promedio de ingresos en %s: %d.\n", city_names[i], averageIncome[i]);
    //Concatena str con el resultado general
    strcat(averageIncomePerCity, str);
    return averageIncomePerCity;
}