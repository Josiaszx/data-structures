/*
    Estructura de pila estatica para menejo de enteros
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int size;
    int capacity;
    int *numbers;
}stack;

int push(stack *stack, int num); // apilar elemento
int pop(stack *stack); // desapilar
int peek(stack *stack); // retornar el primer elemento
void printstack(stack *stack); // mostrar pila

stack *newstack(size_t capacity) {
    stack *newstack = (stack *) malloc(sizeof(stack));
    if (newstack == NULL) return NULL;
    newstack->capacity = capacity;
    newstack->numbers = (int *) calloc(newstack->capacity, sizeof(int));
    if (newstack->numbers == NULL) return NULL;
    newstack->size = 0;
    return newstack;
}

int push(stack *stack, int num) {
    if (stack->size >= stack->capacity) return -1;
    stack->numbers[stack->size] = num;
    stack->size++;
    return 1;
}

int pop(stack *stack) {
    if (stack->size == 0) return -1;
    stack->size--;
    return 1;
}

int peek(stack *stack) {
    if (stack->size == 0) return -1;
    return stack->numbers[stack->size - 1];
}

void printstack(stack *stack) {
    if (stack->size == 0) return;
    for (int i = stack->size - 1; i >= 0; i--) {
        printf("%d ", stack->numbers[i]);
    }
}

void freestack(stack *stack) {
    free(stack->numbers);
    free(stack);
}

int main() {

    stack *stack = newstack(5);

    for (int i = 0; i < 5; i++) {
        push(stack, i * 10);
    }

    printstack(stack);

    printf("\n");
    for (int i = 0; i < 6; i++) {
        printf("\nTop number: %d\n", peek(stack));
        printstack(stack);
        pop(stack);
    }

    freestack(stack);

    return 0;
}