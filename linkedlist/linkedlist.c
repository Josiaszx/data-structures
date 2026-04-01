/*
    Lista enlazada simple para manejar enteros
*/

#include <stdio.h>
#include <stdlib.h>

#include "../generic-node/node.c"

typedef struct linkedlist {
    node *first;
    node *last;
    int size;
}linkedlist;

// Metodos a implementar
linkedlist *init_linkedlist(); // crear nueva lista
int add(linkedlist *list, int num); // agregar elemento al final
int del(linkedlist *list); // eliminar ulitmo elemento
int get(linkedlist *list, int index); // obtener elemento
int find(linkedlist *list, int num); // buscar elemento
void printlist(linkedlist *list); // imprimir la lista

linkedlist *init_linkedlist() {
    linkedlist *list = (linkedlist *) malloc(sizeof(linkedlist));
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

int add(linkedlist *list, int num) {
    if (list == NULL) return -1;

    node *newnode = malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;

    if (list->size == 0) {
        list->first = newnode;
        list->last = newnode;
    }
    else {
        list->last->next = newnode;
        list->last = newnode;
    }

    list->size++;
    return 1;
    /* Antiguo
    if (list->size == 0) {
        list->first = malloc(sizeof(node));
        list->first->data = num;
        list->first->next = list->first;
    } else if (list->size == 1) {
        list->last = malloc(sizeof(node));
        list->last->next = NULL;
        list->last->data = num;
        list->first->next = list->last;
    } else {
        node *tmp = malloc(sizeof(node));
        tmp->data = num;
        tmp->next = NULL;
        list->last->next = tmp;
        list->last = tmp;
    }
    list->size++;
    return 1;
    */
}

int del(linkedlist *list) {
    if (list == NULL || list->size == 0) return -1;

    if (list->size == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        list->size--;
        return 1;
    }

    node *tmp = list->first;
    while (tmp->next != list->last) {
        tmp = tmp->next;
    }
    free(list->last);
    tmp->next = NULL;
    list->last = tmp;
    list->size--;
    return 1;

    /* Antiguo
    if (list->size == 0) return -1;
    if (list->size == 1) {
        free(list->first);
        free(list->last);
        list->first = NULL;
        list->size--;
        return 1;
    }
    if (list->size == 2) {
        free(list->last);
        list->last = NULL;
        list->size--;
        return 1;
    }
    node *tmp = list->first;
    for (int i = 1; i < list->size - 1; i++) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    list->last = tmp;
    list->size--;
    return 1;
    */
}

int find(linkedlist *list, int num) {
    if (list->size == 0) return -1;
    node *tmp = list->first;
    int index = 0;
    while (tmp != NULL) {
        if (tmp->data == num) return index;
        index++;
        tmp = tmp->next;
    }
    return -1;
}

void printlist(linkedlist *list) {
    if (list->size == 0) return;
    node *tmp = list->first;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    linkedlist *list = init_linkedlist();

    add(list, 19);
    add(list, 119);
    add(list, 191);
    add(list, 919);
    add(list, 9191);

    printf("list size: %d\n", list->size);
    printlist(list);
    printf("\n919 is in the index: %d\n", find(list, 919));

    del(list);
    del(list);
    del(list);
    del(list);
    del(list);
    del(list);

    printf("\nlist size: %d\n", list->size);
    printlist(list);

    add(list, 190);
    add(list, 191);
    add(list, 192);
    add(list, 193);

    printf("\nlist size: %d\n", list->size);
    printlist(list);

    return 0;
}