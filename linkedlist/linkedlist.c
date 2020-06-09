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
int listInfo(nod* head);
void push(nod* head, int val);
void pop(nod* head);
void remove_head(nod* head);



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

// return length of list and prints list values
int listInfo(nod* head)
{
    nod* aux = head;
    int counter = 0;
    if(aux != NULL)
    {
        counter++;
        while(aux->next != NULL)
        {
            printf("Valoarea nodului %d este %d\n",counter,aux->value);
            counter ++;
            aux = aux->next;
        }
        printf("Valoarea nodului %d este %d\n",counter,aux->value); 
    }
    else
    {
        printf("Lista este goala!\n");
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

// delete last element from the list
void pop(nod* head)
{
    nod* current = NULL;
    nod* previous = NULL;

    if(head->next == NULL)
    {
        free(head);
    }
    else
    {
        current = head;
        while(current->next != NULL)
        {
            previous = current;
            current = current->next;            
        }
        previous->next = NULL;
        free(current);
    }
    
}

void main()
{
    nod* head = initList();

    push(head,1);
    push(head,2);
    push(head,3);
    push(head,5);
    printf("Lungimea listei este : %d\n",listInfo(head));
    pop(head);
    printf("POPED!\n");
    printf("Lungimea listei este : %d\n",listInfo(head));
}
