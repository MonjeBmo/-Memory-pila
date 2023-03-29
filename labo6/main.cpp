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
void printPila(ptrNodoPila ptr);

// prototypes functions list
void insert(ptrNodoList *ptrS, char valor);
int isEmptyList(ptrNodoList ptrS);
void printLista(ptrNodoList ptrActual);

// all app
void generateData(int cant, ptrNodoPila *ptrP, ptrNodoList *ptrL, bool listOrPila);
void SubInstructions();
void instructions();
bool listOrPila(char value);
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
    scanf("%d", &op);
    while (op != 5)
    {
        switch (op)
        {
        case 1:
        {
            int c = 0;
            char lp;

            cout << endl;
            SubInstructions();
            cout << endl
                 << "Ahora que desea Realizar : ";
            cin >> lp;
            switch (lp)
            {
            case 'a':
            {
                cout << "Ingrese la cantidad de caracteres: ";
                cin >> c;
                while (c >= 21)
                {
                    cout << endl
                         << "Error - No mayor a 20" << endl;
                    cout << "Ingrese la cantidad de caracteres: ";
                    cin >> c;
                }
                generateData(c, &ptrPila, &ptrList, true);
                break;
            }
            case 'b':
                printPila(ptrPila);
                cin.get();
                break;
            case 'c':
                cout << "Regresando ...";
                return 0;
                break;

            default:
                cout << endl
                     << "Opcion no valida!";
                break;
            }

            break;
        }
        case 2:
        {
            int c = 0;
            char lp;

            cout << endl;
            SubInstructions();
            cout << endl
                 << "Ahora que desea Realizar : ";
            cin >> lp;
            switch (lp)
            {
            case 'a':
            {
                cout << "Ingrese la cantidad de caracteres: ";
                cin >> c;
                while (c >= 21)
                {
                    cout << endl
                         << "Error - No mayor a 20" << endl;
                    cout << "Ingrese la cantidad de caracteres: ";
                    cin >> c;
                }
                generateData(c, &ptrPila, &ptrList, false);
                break;
            }
            case 'b':
                printLista(ptrList);
                cin.get();
                break;
            case 'c':
                cout << "Regresando ...";
                return 0;
                break;

            default:
                cout << endl
                     << "Opcion no valida!";
                break;
            }

            break;
        }
        case 3:
        {
            cout << "Mostrar Lista y Pila" << endl << endl;
            cout << "<----------------Lista---------------->" << endl;
            printLista(ptrList);
            cout << "<----------------Pila---------------->" << endl;
            printPila(ptrPila);
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
        instructions();
        cout << "Que desea realizar? ";
        cin >> op;
    }
}

// functions All App

bool listOrPila(char value)
{
    return value == 'a';
}

void generateData(int cant, ptrNodoPila *ptrP, ptrNodoList *ptrL, bool listOrPila)
{
    char data[cant];
    // generate data
    srand(time(NULL));
    for (int i = 0; i <= cant; i++)
    {
        data[i] = 33 + rand() % (126 - 33);
    }
    // save
    //  true == pila
    //  false == list
    if (listOrPila)
    {
        for (int i = 0; i <= cant; i++)
        {
            cout << endl
                 << "llenado pila! ...";
            push(ptrP, data[i]);
        }
    }
    else
    {
        for (int i = 0; i <= cant; i++)
        {
            cout << endl
                 << "llenado fila! ...";
            insert(ptrL, data[i]);
        }
    }
}
void SubInstructions()
{
    cout << "a - Ingresar" << endl;
    cout << "b - Mostrar" << endl;
    cout << "c - Regresar" << endl;
}
void instructions()
{
    cout << "<-- Laboratorio #6 -->" << endl
         << endl;
    cout << "1 - lista" << endl;
    cout << "2 - pila" << endl;
    cout << "3 - Mostrar" << endl;
    cout << "4 - Destruir" << endl;
    cout << "5 - Salir" << endl;
}

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
    if (isEmptyPila(ptr))
    {
        printf("La pila esta vacia\n");
    }
    else
    {
        printf("La pila es: \n");
        while (ptr != NULL)
        {
            cout << "| " << ptr->d << " |\n";
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
