#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct DoubleLinkedList_struct;

typedef struct DoubleLinkedList_struct DoubleLinkedList;

struct DoubleLinkedList_struct {
    int value;
    DoubleLinkedList* prev;
    DoubleLinkedList* next;
};



DoubleLinkedList* Init(int val) {
    DoubleLinkedList* list;
    list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));

    list->value = val;
    list->next = list->prev = NULL;

    return(list);
}
//
DoubleLinkedList* Append(DoubleLinkedList* root, int val) {
    DoubleLinkedList* temp, * new_node;
    temp = root;
    
    new_node = Init(val);

    for (;temp->next!=NULL;) {
        temp = temp->next;
    }
    
    temp->next = new_node;

    temp->next->prev = temp;
    
    return(temp);
}
//
DoubleLinkedList* Add(DoubleLinkedList* element, int val) {
    DoubleLinkedList* previous_element, *new_node, *next_element;
    previous_element = element;
    new_node = Init(val);
    next_element = previous_element->next;

    if (next_element == NULL) {
        new_node->prev = previous_element;

        previous_element->next = new_node;
    }
    else {
        new_node->next = next_element;
        new_node->prev = previous_element;

        next_element->prev = new_node;
        previous_element->next = new_node;
    }

    

    return(new_node);
}
//
DoubleLinkedList* DeleteItem(DoubleLinkedList* element, DoubleLinkedList* root) {
    DoubleLinkedList* element_to_delete,* previous_element,*next_element;
    element_to_delete = root;
    
    for (;element_to_delete != element;)
    {
        element_to_delete = element_to_delete->next;
    }
    
    previous_element = element_to_delete->prev;
    next_element = element_to_delete->next;

    if (next_element == NULL) {
        previous_element->next = NULL;
    }
    else {
        previous_element->next = next_element;
        next_element->prev = previous_element;
    }
    
    free(element_to_delete);
    
    return(previous_element);
}
//
DoubleLinkedList* DeleteHead(DoubleLinkedList* root) {
    DoubleLinkedList* head;
    head = root->next;
    head->prev = NULL;

    free(root);
    
    return(head);
}

void ListPrint(DoubleLinkedList* list) {
    DoubleLinkedList* temp;
    temp = list;

    for (; temp != NULL; temp = temp->next) {
        printf("%d ", temp->value);
    }
    
}

void main()
{
    DoubleLinkedList* list = Init(15);
    ListPrint(list);
    printf("\n");
    Append(list, 20);
    Append(list, 30);
    ListPrint(list);
    printf("\n");
    DoubleLinkedList* lnk1 = list->next;
    Add(lnk1, 25);
    ListPrint(list);
    printf("\n");
    lnk1 = list->next->next->next;
    Add(lnk1, 35);
    ListPrint(list);
    printf("\n");
    lnk1 = lnk1->prev;
    DeleteItem(lnk1, list);
    ListPrint(list);
    printf("\n");
    list = DeleteHead(list);
    ListPrint(list);
    printf("\n");
    
    //printf("Hello!");
}