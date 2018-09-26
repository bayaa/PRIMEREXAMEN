#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct NUMEROSESTRUCTURA
{

    int numeross;
    struct NUMEROSESTRUCTURA *siguiente;
}*inicio,*aux,*actual, producto;

void insertarNUMEROSESTRUCTURA(int);
void mostrarNUMEROSESTRUCTURA();
void ordenar(int);
void posicion(int);
int total=0;
int main()
{
    inicio = NULL;
    int numeross;

    int salida,cuenta=0;
    int menu;
    do
    {

        cout<<"Ingresar numeros (1)\n Ver numeros (2)\n salir (3)";
        cin>> menu;
        if (menu==1)
        {
            do
            {

                cout << "\t NUMERO (SALIR OPRIMA -1)  : >>>>>>>>   ";
                cin >> numeross;
                if(numeross != -1)
                {
                    cuenta++;
                    insertarNUMEROSESTRUCTURA(numeross);
                }


            }
            while (numeross != -1 );
        }
        else if (menu==2)
        {


            cout<<"\t\tNUMEROS ORDENADOS\n";
            mostrarNUMEROSESTRUCTURA();
        }



    }
    while (menu!=3);





    cout<<"\n\tFINAL";




    cin.get();
    return 0;
}

void insertarNUMEROSESTRUCTURA(int valor)
{
    actual=inicio;
    if(actual == NULL)
    {
        aux = new NUMEROSESTRUCTURA();
        aux->numeross = valor;
        aux->siguiente = NULL;
        inicio = aux;
    }
    else
    {
        while(actual->siguiente != NULL)
        {
            actual=actual->siguiente;
        }
        aux = new NUMEROSESTRUCTURA();
        aux->numeross = valor;
        aux->siguiente = NULL;
        actual->siguiente = aux;
    }

}

void mostrarNUMEROSESTRUCTURA()
{
    actual = inicio;

    int contador=0;
    do
    {
        contador++;


        cout <<"\t\t"<<"NUMERO.-  "<< contador <<"   ........" << actual->numeross << endl;
        actual=actual->siguiente;

    }
    while(actual!= NULL);




}

void posicion(int valor)
{
    actual = inicio;
    int contador=0;
    do
    {
        contador++;
        if(contador == valor)
        {
            cout <<"\t\t"<< contador <<".- " << actual->numeross << " " << endl;
        }

        actual=actual->siguiente;
    }
    while(actual!= NULL);
}
void ordenar(int cantidad)
{
    NUMEROSESTRUCTURA *aux1;

    do
    {
        actual=inicio;
        while (actual->siguiente != NULL)
        {

            aux = actual->siguiente;

            while(aux != NULL)
            {

                if(actual->numeross > actual->siguiente->numeross)
                {

                    aux1->numeross = actual->numeross;
                    actual->numeross = actual->siguiente->numeross;
                    actual->siguiente->numeross = aux1->numeross;

                }
                aux = aux->siguiente;

            }

            actual = actual->siguiente;
        }

        cantidad--;
    }
    while(cantidad != 0);
}

