#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

// Calculate the probability of being sick of a person in a range of ages

const char * printProbabilitySick(item_t items[], int size){

    int ageMin;
    int ageMax;
    printf("(Punto 3) Probabilidad de estar enfermo cuando se tienen X o más años\n");
    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad minima: ");
    scanf("%d", &ageMin);

    static char probabilitySick[] = "";
    //char *str;
    //size_t nbytes;
    int sickCount = 0;
    int totalCount = 0;
    for (int i = 0; i < size; i++)
    {   
        if(items[i].illness == true && items[i].age >= ageMin){
            sickCount++;
        }
        totalCount++;
    }

    printf("La probabilidad de estar enfermo es: %d/%d = %f \n", sickCount, totalCount, (float)sickCount/totalCount);
    /*
    nbytes = snprintf(NULL, 0, "La probabilidad de estar enfermo es: %d/%d = %f", sickCount, totalCount, (float)sickCount/totalCount) + 1;
    str = malloc(nbytes);
    snprintf(str, nbytes, "La probabilidad de estar enfermo es: %d/%d = %f", sickCount, totalCount, (float)sickCount/totalCount);
    strcat(probabilitySick, str);
    free(str);
    */
    return probabilitySick;
}