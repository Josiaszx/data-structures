// Nodo generico para manejar enteros
typedef struct node {
    struct node *next;
    int data;
}node;
// si se quiere utilizar otras estructuras, se puede utilizar con (void *)