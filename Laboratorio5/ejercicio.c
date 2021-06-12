#include<stdio.h>
#include<stdlib.h>
// Nodo DDL
struct Node{
int data;
struct Node* next; // Puntero al siguiente nodo en DDL.
struct Node* prev; // Puntero al nodo anterior en DDL.
};

// Insertar un nuevo nodo al inicio: El nuevo nodo siempre se agrega antes del encabezado de la lista vinculada dada
//y el nodo recién agregado se convierte en el nuevo encabezado de DDL.
// Por ejemplo, si la lista vinculada es 20152025 y agregamos el elemento 8 al inicio, la lista vinculada se convierte en 820152025.
//La función que se agrega al principio de la lista es push (). Debe recibir un puntero en la cabeza.

void push (struct Node** head_ref, int new_data)
{
// Asignar nodo.
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

// Insertarlo a los datos.
new_node->data = new_data;

// Hacer el siguiente nuevo nodo como cabeza (head) y el anterior como NULO.
new_node->next =(*head_ref);
new_node->prev =NULL;

// Cambiar la cabeza del nodo anterior a un nuevo nodo.
if ((*head_ref) !=NULL)
	(*head_ref)->prev =new_node;

// Cambie la cabeza para que apunte al nuevo nodo.
(*head_ref) = new_node;
}

// Insertar un nuevo nodo al final: El nuevo nodo agregado, después del último nodo de la lista vinculada dada, la lista vinculada generalmente está representada por el encabezado, tenemos que ir a través de la lista hasta el final y luego cambiar el siguiente nodo (el ultimo) por el nuevo nodo.

void append(struct Node** head_ref, int new_data)
{
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
struct Node* last = *head_ref ;

new_node ->data = new_data ;
new_node ->next =NULL;

if (*head_ref ==NULL) {
	new_node ->prev =NULL;
	*head_ref = new_node;
return;
}
while(last->next !=NULL){
	last= last->next;
}
	last ->next =new_node;
	new_node = last;

return;
}

// Insertar un nuevo nodo después de un nodo específico: Se nos da un puntero a un nodo como prev_node,
// y se inserta un nuevo nodo después del nodo dado.

void insertAfter(struct Node* prev_node, int new_data)
{
if(prev_node ==NULL)
{
	printf("El nodo anterior no puede ser NULO\n");
return;
}
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = new_data;
new_node->next = new_node;
new_node->prev = prev_node;

if(new_node->next !=NULL)
	new_node->next->prev = new_node;
}

// Insertar un nuevo nodo antes de un nodo específico.

void insertBefore(struct Node** head_ref, struct Node* next_node , int new_data)
{
if((next_node)==NULL)
{
	printf("El proximo nudo seleccionado, no puede ser NULO\n");
return;
}
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = new_data;
new_node->prev = next_node->prev;
new_node->prev = new_node;
new_node->next = new_node;

if(new_node->prev !=NULL)
	new_node->prev->next = new_node;
else
(*head_ref) = new_node;
}

void printlist(struct Node* node)
{
struct Node* last ;
printf("\n Recorrido hacia adelante ");
while(node !=NULL)
{
	printf("%d", node->data);
	last = node;
	node = node->next;
}
	printf("\n Recorrido hacia atras");
while(last !=NULL)
{
	printf("%d", last ->data);
	last = last->prev;
}
}
int main()
{
struct Node* head =NULL;
push(&head , 7);
push(&head , 1);
push(&head , 4);

insertBefore (&head, head->next,8);
	printf("La lista doble enlazada es : \n");
	printlist(head);
getchar();
return 0;
}
