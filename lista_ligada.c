#include <stdio.h>
#include <stdlib.h>
#include "base_struct.h"

typedef struct Node_Item{
    item_t data;
    struct Node_Item *next;
}Node_Item;

Node_Item* createNodeItem(item_t *data);
void insert(Node_Item **head, item_t *data);
void printList(Node_Item *head);
void probability_disease(int age, Node_Item *head);
Node_Item *search_by_id(Node_Item *head, int id);
Node_Item *reverseList(Node_Item *head);
void insert_middle(Node_Item *head);
void increment_id(Node_Item *head);
char * quantityByCity(Node_Item *head);
char * incomeCity(Node_Item *head, char city[], int x, int y);
char * ageByCity(Node_Item *head, int edad);

Node_Item *createNodeItem(item_t *data){
    Node_Item *new = (Node_Item*)malloc(sizeof(Node_Item));
    new->data = *data;
    new->next = NULL;
    return new;
}

void insert(Node_Item **head, item_t *data){
    Node_Item *new = createNodeItem(data);
    new->next = *head;
    *head = new;
}

Node_Item *reverseList(Node_Item *head) {
    Node_Item *newHead = NULL;
    Node_Item *current = head;
    while (current != NULL) {
        Node_Item *next = current->next;
        current->next = newHead;
        newHead = current;
        current = next;
    }
    return newHead;
}

void printList(Node_Item *head){
    Node_Item *temp = head;
    int i=0;
    while(i<5){
        printf("id: %d, city: %s, age: %d  \n", temp->data.id, city_names[temp->data.city], temp->data.age);
        temp = temp->next;
        i+=1;
    }
}

void probability_disease(int age, Node_Item *head){
    int quantity = 0, patients=0;
    Node_Item *temp = head;
    while(temp != NULL){
        if(temp->data.age>=age){
            quantity += 1;
            if(temp->data.illness == true){
                patients += 1;
            }
        }
        temp = temp->next;
    }
    printf("La probabilidad de que una persona de %d años o más esté enferma es de %f\n", age, (float)patients/quantity);
}

Node_Item *search_by_id(Node_Item *head, int id){
    Node_Item *temp = head;
    while(temp != NULL){
        if(temp->data.id == id){
            printf("%d", temp->data.id);
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insert_middle(Node_Item *head){
     Node_Item *temp = head;
    while(temp != NULL){
        if(temp->data.id==74999){
            item_t data={75000, M, 34,FEMALE, 100000, true};
            Node_Item *new = createNodeItem(&data);
            new->next=temp->next;
            temp->next=new;
            temp = new->next;
            increment_id(temp);
            return;
            
        }
        temp->data.id += 1;
        temp = temp->next;
    }
}

void increment_id(Node_Item *head){
    Node_Item *temp = head;
    while(temp != NULL){
        temp->data.id += 1;
        temp = temp->next;
    }
}

char * quantityByCity(Node_Item *head){
    unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};
    char str[100];
    static char peopleByCity[500];
    for(int i=0; i < 9; i++){
        Node_Item *temp = head;
        while(temp != NULL){
            if(city_names[temp->data.city] == city_names[i]){
                cityCount[i]++;
            }
            temp = temp->next;
        }
        snprintf(str, sizeof(str), "El número de personas en %s es %d\n", city_names[i], cityCount[i]);
        strcat(peopleByCity, str);
    }
    return peopleByCity;
}


char * incomeCity(Node_Item *head, char city[], int x, int y){
    Node_Item *temp = head;
    int income = 0;
    int quantity = 0.0;
    float average = 0;
    static char str[100];    
    while(temp != NULL){
        if(city_names[temp->data.city] == city){
            if(temp->data.age >= x && temp->data.age <= y){
                income += temp->data.income;
                quantity++;
            }
        }
        temp = temp->next;
    }
    average = income/quantity;
    snprintf(str, sizeof(str), "El salario promedio de personas que viven en %s que tienen entre %d y %d es de: %f\n", city, x, y, average);
    return str;
}

char * ageByCity(Node_Item *head, int edad){
    unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};
    char str[100];
    static char ageByCity[500];
    for(int i=0; i < 9; i++){
        Node_Item *temp = head;
        while(temp != NULL){
            if(city_names[temp->data.city] == city_names[i] && temp->data.age == edad){
                cityCount[i]++;
            }
            temp = temp->next;
        }
        snprintf(str, sizeof(str), "Las cantidad de personas con %d años que viven en %s es de %d\n", edad, city_names[i], cityCount[i]);
        strcat(ageByCity, str);
    }
    return ageByCity;
}