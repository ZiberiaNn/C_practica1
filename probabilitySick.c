#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

// Calculate the probability of being sick of a person in a range of ages

const char * printProbabilitySick(item_t items[], int size){

    int ageMin;
    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad minima: ");
    scanf("%d", &ageMin);

    //String que retorna el resultado de la probabilidad
    static char probabilitySick[100];
    //Reinicializa el string en "" (null)
    memset(probabilitySick, 0, sizeof(probabilitySick));

    int sickCount = 0;
    int totalCount = 0;
    for (int i = 0; i < size; i++)
    {   
        if(items[i].illness == true && items[i].age >= ageMin){
            sickCount++;
        }
        totalCount++;
    }
    //Copia el string del resultado en probabilitySick
    snprintf(probabilitySick, sizeof(probabilitySick),"La probabilidad de estar enfermo es: %d/%d = %f \n", sickCount, totalCount, (float)sickCount/totalCount);

    //Retorna el string del resultado
    return probabilitySick;
}