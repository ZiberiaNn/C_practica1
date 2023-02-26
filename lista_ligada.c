#include <stdio.h>
#include <stdlib.h>

/**
 * Estructura del nodo de la lista ligada.
 * data, hace referencia al tipo de dato que almacena el nodo.
 * next, es un apuntador al siguiente nodo de la lista.  
*/
typedef struct Node_Item{
    item_t data;
    struct Node_Item *next;
}Node_Item;

// Definición del método que crea un nodo de la lista ligada.
Node_Item* createNodeItem(item_t *data);
//Definición del método que inserta un nodo al inicio de la lista ligada.
void insert(Node_Item **head, item_t *data);
//Definicición del método que calcula la probabilidad de estar enfermo en un rango de edad si se tiene un rango de edad.
char * probability_disease(int age, Node_Item *head);
//Definición del método que busca un elemento por su id.
char * search_by_id(Node_Item *head, int id);
//Definición del método que invierte la lista ligada.
Node_Item *reverseList(Node_Item *head);
//Definición del método que inserta un elemento en la mitad de la lista ligada.
void insert_middle(Node_Item *head, item_t element);
//Definición del método que incrementa en 1 el id de los elementos de la lista ligada.
void increment_id(Node_Item *head);
char * quantityByCity(Node_Item *head);
char * incomeCity(Node_Item *head, int city, int minAge, int maxAge);
char * ageByCity(Node_Item *head, int edad);


//Método que crea un nodo de la lista ligada.
Node_Item *createNodeItem(item_t *data){
    //Se reserva memoria para el nuevo nodo.
    Node_Item *new = (Node_Item*)malloc(sizeof(Node_Item));
    //Se le inserta el dato al nodo.
    new->data = *data;
    //Se le asigna NULL al apuntador next.
    new->next = NULL;
    return new;
}

//Método que inserta un nodo al inicio de la lista ligada.
void insert(Node_Item **head, item_t *data){
    //Se crea un nuevo nodo.
    Node_Item *new = createNodeItem(data);
    //Se asigan el apuntador que puntaba al inicio de la lista, al apuntador de siguiente del nuevo nodo.
    new->next = *head;
    //Se asigna el nuevo nodo como el inicio de la lista.
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

char * probability_disease(int age, Node_Item *head){
    static char str[100];
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
    snprintf(str, sizeof(str),"La probabilidad de que una persona de %d años o más esté enferma es de %f\n", age, (float)patients/quantity);
    return str;
}

char * search_by_id(Node_Item *head, int id){
    static char str[100];
    Node_Item *temp = head;
    while(temp != NULL){
        if(temp->data.id == id){
            snprintf(str, sizeof(str),"id: %d, ciudad: %s, edad: %d, genero: %s, ingresos: %d , enfermo:%s  \n", temp->data.id, city_names[temp->data.city], temp->data.age, gender_names[temp->data.gender], temp->data.income, illness_values[temp->data.illness] );
            printf("%d", temp->data.id);
            return str;
        }
        temp = temp->next;
    }
    snprintf(str, sizeof(str),"No se encontró el usuario con el id %d", id);
    return str;
}

void insert_middle(Node_Item *head, item_t element){
     Node_Item *temp = head;
    while(temp != NULL){
        if(temp->data.id==74999){
            Node_Item *new = createNodeItem(&element);
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


char * incomeCity(Node_Item *head, int city, int minAge, int maxAge){
    Node_Item *temp = head;
    int income = 0;
    int quantity = 0.0;
    float average = 0;
    static char str[100];    
    while(temp != NULL){
        if(temp->data.city == city){
            if(temp->data.age >= minAge && temp->data.age <= maxAge){
                income += temp->data.income;
                quantity++;
            }
        }
        temp = temp->next;
    }
    average = income/quantity;
    snprintf(str, sizeof(str), "El salario promedio de personas que viven en %s que tienen entre %d y %d es de: %f\n", city_names[city], minAge, maxAge, average);
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