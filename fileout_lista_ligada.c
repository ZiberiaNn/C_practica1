#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFileOutListaLigada(struct Node_Item *head, int ageMinimum, int ageMaximum, int cityAverageIncome, int ageMin, int id, int ageCity, item_t element){
    
    FILE *fileOut_lista_ligada;
    fileOut_lista_ligada = fopen("listaLigadaResults.txt","w");
    
	//Imprime el archivo de salida
	fprintf(fileOut_lista_ligada,"%s", quantityByCity(head));
    
    fprintf(fileOut_lista_ligada,"%s",incomeCity(head, cityAverageIncome, ageMinimum, ageMaximum));
    
    fprintf(fileOut_lista_ligada,"%s", probability_disease(ageMin, head));
    
    char * getById = search_by_id(head, id);
    fprintf(fileOut_lista_ligada,"%s",getById);
    
    char * insertElement = insert_middle(head, element);
    fprintf(fileOut_lista_ligada,"%s",insertElement);
    
    fprintf(fileOut_lista_ligada,"%s", ageByCity(head, ageCity));
    
    fclose(fileOut_lista_ligada);
}
