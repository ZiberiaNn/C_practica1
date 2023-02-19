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
        printf("id: %d, city: %d, age: %d  \n", temp->data.id, temp->data.city, temp->data.age);
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

