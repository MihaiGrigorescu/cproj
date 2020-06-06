#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// structura unui nod
typedef struct Nod
{
    int value;
    struct Nod* next;
}nod;

// prototipuri
nod* initList();
int listLength(nod* head);
void push(nod* head, int val);



// initialize the list with the first node
nod* initList()
{
    nod* head = NULL;
    head = (nod*) malloc(sizeof(nod));
    
    if(head == NULL)
    {
        return NULL;
    }

    head->value = 0;
    head->next = NULL;

    return head;
}

// return length of list
int listLength(nod* head)
{
    nod* aux = head;
    int counter = 0;
    if(aux != NULL)
    {
       while(aux->next != NULL)
        {
            counter ++;
            aux = aux->next;
        } 
    }

    return counter;   
}

//add a node at the end of the list
void push(nod* head, int val)
{
    nod* currentnode = head;
    while (currentnode->next !=NULL)
    {
        currentnode = currentnode->next;
    }

    nod* newnode = (nod*)malloc(sizeof(nod));
    newnode->value = val;
    newnode->next = NULL;
    currentnode->next = newnode;
    
}

void main()
{
    nod* head = initList();
    printf("Valoarea primului nod este %d",head->value);
    printf("XXX");
    
}
