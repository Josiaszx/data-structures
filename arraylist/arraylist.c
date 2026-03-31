#include <stdio.h>
#include <stdlib.h>
// implementacion de arraylist para enteros en C
// caracteristicas:
//  - la lista debe ser implementada con arrays y debe ser dinamica
//  - si la lista se llena y se desea agregar otro elemento, se debe reservar otro array con el doble de capacidad del actual
//    y se deben copiar todos los elementos al nuevo array
//  - si la lista se va vaciando y llega a 1/4 de su capacidad, reducir el tamaño del array a la mitad

typedef struct arraylist {
    int size;
    int capacity;
    int *array;
} arraylist;

// metodos a implementar:
int size(arraylist *list); // --> retorna el tamaño del array
int add(arraylist *list, int value); // --> agregar elemento al final
int del(arraylist *list); // --> elimina el ultimo elemento
int get(arraylist *list, int index); // --> retorna el elemento en el indice dado
int find(arraylist *list, int element); // --> retorna el indice del elemento dado o -1 si no se encuentra
int del_list(arraylist *list); // --> eliminar lista - libera la memoria ocupada por la lista
int resize(arraylist *list); // --> duplicar capacidad de la lista
int downsize(arraylist *list); // --> reducir tamaño de la lista



arraylist *init_arraylist(int capacity) {
    arraylist *list =  malloc(sizeof(arraylist));
    list->capacity = capacity;
    list->array = malloc(list->capacity * sizeof(int));
    list->size = 0;
    return list;
}

int size(arraylist *list) {
    return list->size;
}

int add(arraylist *list, int value) {
    if (list->size == list->capacity) {
        int result = resize(list);
        if (result == -1) return -1;
    }
    *(list->array + list->size) = value;
    list->size++;
    return 1;
}

int del(arraylist *list) {
    if (list->size == 0) return -1;
    list->size--;
    if (list->size == (int) (list->capacity * 0.25)) {
        downsize(list);
    }
}

int get(arraylist *list, int index) {
    if (index < 0 || index >= list->size) index = list->size - 1;
    return list->array[index];
}

int resize(arraylist *list) {
    return 0;
}

int downsize(arraylist *list) {
    return 0;
}

int main() {

    arraylist *list = init_arraylist(10);
    printf("%d\n", size(list));
    printf("list size: %d\n", list->size);
    printf("list capacity: %d\n", list->capacity);



    return 0;
}
