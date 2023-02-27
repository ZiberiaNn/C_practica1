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
char * quantityByCity(Node_Item *head);
char * incomeCity(Node_Item *head, int city, int minAge, int maxAge);
char * probability_disease(int age, Node_Item *head);
//Definición del método que busca un elemento por su id.
char * search_by_id(Node_Item *head, int id);
//Definición del método que invierte la lista ligada.
Node_Item *reverseList(Node_Item *head);
char * insert_middle(Node_Item *head, item_t element);
void increment_id(Node_Item *head);
char * ageByCity(Node_Item *head, int age);


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


//Método que reversa la lista ligada
Node_Item *reverseList(Node_Item *head) {
    //Se crea un apuntador que apuntará al inicio de la lista.
    Node_Item *newHead = NULL;
    //Se crea un apuntador que apuntará al nodo actual.
    Node_Item *current = head;
    //Se crea un apuntador que apuntará al nodo siguiente.
   
    //Se recorre la lista hasta que el apuntador current sea NULL.
    while (current != NULL) {       
        Node_Item *next = current->next;
        //Al nodo actual se le asigna como siguiente el nodo que apuntaba al inicio de la lista.
        current->next = newHead;
        //Se asigna el nodo actual como el inicio de la lista.
        newHead = current;
        //Se asigna el nodo siguiente como el nodo actual.
        current = next;
    }
    //Se regresa el nuevo inicio de la lista.
    return newHead;
}

//Método que calcula la probabilidad de estar enfermo si se tiene cierta edad o superior.
char * probability_disease(int age, Node_Item *head){
    //Se crea un arreglo de caracteres que almacenará el resultado.
    static char str[200];
    //Se inicializan las variables que almacenarán la cantidad de personas que tienen cierta edad o superior y la cantidad de personas enfermas.
    int quantity = 0, patients=0;
    //Se crea un apuntador que apuntará al nodo actual.
    Node_Item *temp = head;
    //Se recorre la lista hasta que el apuntador temp sea NULL.
    while(temp != NULL){
        //Se verifica si la información del nodo actual contiene una edad mayor o igual a la edad ingresada.
        if(temp->data.age>=age){
            //Se incrementa en 1 la cantidad de personas que tienen cierta edad o superior.
            quantity += 1;
            //Se verifica si la información del nodo actual dice si esta enfermo o no.
            if(temp->data.illness == true){
                //Se incrementa en 1 la cantidad de personas enfermas.
                patients += 1;
            }
        }
        //Se asigna el nodo siguiente como el nodo actual.
        temp = temp->next;
    }
    //Se almacena en el arreglo de caracteres el resultado.
    snprintf(str, sizeof(str),"La probabilidad de que una persona de %d años o más esté enferma es de %f\n", age, (float)patients/quantity);
    //Se regresa el arreglo de caracteres.
    return str;
}

//Método que busca un elemento por su id.
char * search_by_id(Node_Item *head, int id){
    //Se crea un arreglo de caracteres que almacenará el resultado.
    static char str[200];
    //Se crea un apuntador que apuntará al nodo actual.
    Node_Item *temp = head;
    //Se recorre la lista hasta que el apuntador temp sea NULL.
    while(temp != NULL){
        //Se verifica si la información del nodo actual contiene el id ingresado.
        if(temp->data.id == id){
            //Se almacena en el arreglo de caracteres el resultado.
            snprintf(str, sizeof(str),"id: %d, ciudad: %s, edad: %d, genero: %s, ingresos: %d , enfermo:%s  \n", temp->data.id, city_names[temp->data.city], temp->data.age, gender_names[temp->data.gender], temp->data.income, illness_values[temp->data.illness] );
            //Se regresa el arreglo de caracteres.
            return str;
        }
        //Se asigna el nodo siguiente como el nodo actual.
        temp = temp->next;
    }
    //Se almacena en el arreglo de caracteres el resultado.
    snprintf(str, sizeof(str),"No se encontró el usuario con el id %d", id);
    //Se regresa el arreglo de caracteres.
    return str;
}

char * insert_middle(Node_Item *head, item_t element){
    Node_Item *temp = head;
    static char result[100];
    while(temp != NULL){
        //Se verifica si el id del nodo actual es 74999.
        if(temp->data.id==74999){
            //Se crea un nuevo nodo.
            Node_Item *new = createNodeItem(&element);
            //Se asigna el nodo siguiente del nodo actual como el nodo siguiente del nuevo nodo.
            new->next=temp->next;
            //Se asigna el nuevo nodo como el nodo siguiente del nodo actual.
            temp->next=new;
            //Se asigna el nodo siguiente del nuevo nodo como el nodo actual.
            temp = new->next;
            //Se llama al método que incrementa en 1 el id de todos los nodos siguientes al nuevo nodo.
            increment_id(temp);
            snprintf(result, sizeof(result), "Elemento insertado\n");
        }
        temp = temp->next;
    }
    return result;
}

//Método que incrementa en 1 el id de todos los nodos siguientes al nuevo nodo.
void increment_id(Node_Item *head){
    //Se crea un apuntador que apuntará al nodo actual.
    Node_Item *temp = head;
    //Se recorre la lista hasta que el apuntador temp sea NULL.
    while(temp != NULL){
        //Se incrementa en 1 el id del nodo actual.
        temp->data.id += 1;
        //Se asigna el nodo siguiente como el nodo actual.
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

char * ageByCity(Node_Item *head, int age){
    unsigned int cityCount[9] = {0,0,0,0,0,0,0,0,0};
    char str[100];
    static char ageByCity[500];
    for(int i=0; i < 9; i++){
        Node_Item *temp = head;
        while(temp != NULL){
            if(city_names[temp->data.city] == city_names[i] && temp->data.age == age){
                cityCount[i]++;
            }
            temp = temp->next;
        }
        snprintf(str, sizeof(str), "La cantidad de personas con %d años que viven en %s es de %d\n", age, city_names[i], cityCount[i]);
        strcat(ageByCity, str);
    }
    return ageByCity;
}