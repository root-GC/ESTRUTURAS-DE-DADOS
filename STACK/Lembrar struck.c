#define MAXSIZE=30;

// Duas formas de declacar STRUCT

// 1. Usando só struct

// #Declaração
struct Node{
     int stack[MAXSIZE];
     int top;
};

// #Chamada
struct Node n1;

// 2.Usando typedef struct

// #Declaração
typedef struct {
     int stack[MAXSIZE];
     int top;
} Node;

// #Chamada
Node n1;


// Ponteiros e struct

// Declaração de ponteiro para struct

Node *ptr;

ptr=&n1;

(*ptr).top=-1;  ==  ptr->top=-1;

int item = ++top; //incrementa, depois atribui.
int item2=top++; //atribui, depois incrementa.
