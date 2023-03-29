#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// struct reference list
struct nodoList
{
    char d;
    struct nodoList *ptrS;
};

typedef nodoList NodoList;
typedef NodoList *ptrNodoList;

// struct reference pila
struct nodoPila
{
    char d;
    struct nodoPila *ptrS;
};

typedef nodoPila NodoPila;
typedef NodoPila *ptrNodoPila;

// prototypes functions pila
void push(ptrNodoPila *ptr, char info);
char pop(ptrNodoPila *ptr);
int isEmptyPila(ptrNodoPila ptr);
void printPila(ptrNodoPila *ptr);

// prototypes functions list
void insert(ptrNodoList *ptrS, char valor);
int isEmptyList(ptrNodoList ptrS);
void printLista(ptrNodoList ptrActual);

// all app
void generateData();
void SubInstructions();
void instructions();

// https://www.techiedelight.com/es/select-random-letters-in-cpp/
// https://ccodigo.wordpress.com/2010/09/21/generar-un-string-aleatorio-en-c/

int main()
{
    ptrNodoPila ptrPila = NULL;
    ptrNodoList ptrList = NULL;
    int op;
    int value;
    instructions();
    printf("\n Que desea realizar?");
    scanf("%d", op);
    while (op != 5)
    {
        switch (op)
        {
        case 1:
        {
            
            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {

            break;
        }
        case 4:
        {

            break;
        }
        case 5:
        {

            break;
        }

        default:
        {
            cout << "Error - opcion no valida!";
            break;
        }
        }
    }
}

// functions All App
void generateData(int cant, ptrNodoPila *ptrP, ptrNodoList *ptrL, bool listOrPila)
{
    char data[cant];
    // generate data

    // save
    //  true == pila
    //  false == list
    if (listOrPila)
    {
        for (int i = 0; i < cant; i++)
        {
            push(ptrP, data[i]);
        }
    }
    else
    {
        for (int i = 0; i < cant; i++)
        {
            insert(ptrL, data[i]);
        }
    }
}
void SubInstructions() {}
void instructions() {}

// functions pila
void push(ptrNodoPila *ptr, char info)
{
    ptrNodoPila ptrNuevo;
    ptrNuevo = (NodoPila *)malloc(sizeof(nodoPila));

    if (ptrNuevo != NULL)
    {
        ptrNuevo->d = info;
        ptrNuevo->ptrS = *ptr;
        *ptr = ptrNuevo;
    }
    else
    {
        printf("%d no se inserto", info);
    }
}

char pop(ptrNodoPila *ptr)
{
    ptrNodoPila ptrTemp;
    char valueDelete;
    ptrTemp = *ptr;
    valueDelete = (*ptr)->d;
    *ptr = (*ptr)->ptrS;
    free(ptrTemp);
    return valueDelete;
}

int isEmptyPila(ptrNodoPila ptr)
{
    return ptr == NULL;
}

void printPila(ptrNodoPila ptr)
{
    if (ptr == NULL)
    {
        printf("La pila esta vacia");
    }
    else
    {
        printf("La pila es: \n");
        while (ptr != NULL)
        {
            printf("| %d |\n", ptr->d);
            ptr = ptr->ptrS;
        }
        printf("NULL\n\n");
    }
}

// functions list
void insert(ptrNodoList *ptrS, char valor)
{
    ptrNodoList ptrNuevo;
    ptrNodoList ptrAnterior;
    ptrNodoList ptrActual;
    ptrNuevo = (NodoList *)malloc(sizeof(NodoList));
    if (ptrNuevo != NULL)
    {
        ptrNuevo->d = valor;
        ptrNuevo->ptrS = NULL;
        ptrAnterior = NULL;
        ptrActual = *ptrS;
        while (ptrActual != NULL && valor > ptrActual->d)
        {
            ptrAnterior = ptrActual;     /* entra al ... */
            ptrActual = ptrActual->ptrS; /* ... siguiente nodo */
        }                                /* fin de while */
        if (ptrAnterior == NULL)
        {
            ptrNuevo->ptrS = *ptrS;
            *ptrS = ptrNuevo;
        }
        else
        {
            ptrAnterior->ptrS = ptrNuevo;
            ptrNuevo->ptrS = ptrActual;
        }
    }
    else
    {
        printf("No se inserto %c. No hay memoria disponible.\n", valor);
    }
}

int isEmptyList(ptrNodoList ptrS)
{
    return ptrS == NULL;
}

void printLista(ptrNodoList ptrActual)
{
    if (ptrActual == NULL)
    {
        printf("La lista esta vacia.\n\n");
    }
    else
    {
        printf("La lista es:\n");
        while (ptrActual != NULL)
        {
            printf("%c -> ", ptrActual->d);
            ptrActual = ptrActual->ptrS;
        }
        printf("NULL\n\n");
    }
}
