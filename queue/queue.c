/*
    Estructura de cola estatica para manejar enteros
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int capacity;
    int size;
    int first_index;
    int last_index;
    int *nums;
}queue;

int push(queue *q, int num); // agregar a la cola
int pop(queue *q); // eliminar primer elemento
int front(queue *q); // retornar primer elemento
int back(queue *q); // retornar ultimo elemento
void printqueue(queue *q); // mostrar elementos

queue *newqueue(size_t capacity) {
    queue *q = (queue *) malloc(sizeof(queue));
    if (q == NULL) return NULL;
    q->capacity = capacity;
    q->size = 0;
    q->first_index = -1;
    q->last_index = -1;
    q->nums = (int *) calloc(capacity, sizeof(int));
    if (q->nums == NULL) return NULL;
    return q;
}

int push(queue *q, int num) {
    if (q->size == q->capacity) return -1;
    q->size++;
    q->last_index = q->last_index == q->capacity - 1 ? 0 : q->last_index + 1;
    q->nums[q->last_index] = num;
    if (q->size == 1) q->first_index = 0;
    return 1;
}

int pop(queue *q) {
    if (q->size == 0) return -1;
    q->size--;
    if (q->size == 0) q->first_index = -1;
    else q->first_index = q->first_index + 1 == q->capacity ? 0 : q->first_index + 1;
    return 1;
}

int front(queue *q) {
    if (q->size == 0) return -1;
    return q->nums[q->first_index];
}

int back(queue *q) {
    if (q->size == 0) return -1;
    return q->nums[q->last_index];
}

void printqueue(queue *q) {
    if (q->size == 0) return;
    int index = q->first_index;
    int checked_numbers = 0;
    while (checked_numbers < q->size) {
        printf("%d ", q->nums[index]);
        checked_numbers++;
        index = index == q->capacity - 1 ? 0 : index + 1;
    }
    printf("\n");
}

void freequeue(queue *q) {
    if (q == NULL) return;
    free(q->nums);
    free(q);
}

int main() {

    queue *q = newqueue(5);

    for (int i = 0; i < 5; i++) {
        push(q, i * 10);
        printqueue(q);
    }

    printf("\noriginal list: ");
    printqueue(q);
    for (int i = 0; i < 5; i++) {
        printf("deleting %d: \n", q->nums[q->first_index]);
        pop(q);
        printqueue(q);
    }

    freequeue(q);

    return 0;
}