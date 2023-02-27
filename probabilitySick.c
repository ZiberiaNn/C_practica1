#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"
#include <setjmp.h>

jmp_buf env;

// Calculate the probability of being sick of a person in a range of ages

const char *printProbabilitySick(item_t items[], int size, int ageMin)
{
    if(ageMin < 0){
        printf("La edad no debe ser negativa\n");
        longjmp(env, 1);
    }
    // String que retorna el resultado de la probabilidad
    static char probabilitySick[100];
    // Reinicializa el string en "" (null)
    memset(probabilitySick, 0, sizeof(probabilitySick));

    int sickCount = 0;
    int totalCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (items[i].age >= ageMin)
        {
            if (items[i].illness == true)
            {
                sickCount++;
            }
            totalCount++;
        }
    }
    // Copia el string del resultado en probabilitySick
    snprintf(probabilitySick, sizeof(probabilitySick), "La probabilidad de estar enfermo es: %d/%d = %f \n", sickCount, totalCount, (float)sickCount / totalCount);

    // Retorna el string del resultado
    return probabilitySick;
}