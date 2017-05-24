#include<iostream>
#include<stdlib.h>

using namespace std;


/* Declaramos el vector y el tope*/
int vector[1000];
int tope = 0;


/* Rueda todos los elementos partiendo desde el elemento encontrado, al finalizar inserta el elemento
    tambien inserta un elemento en cualquier posicion
*/
void rodar_pos(int dato, int inicio, int fin){
    if(fin == inicio){
        vector[fin] = dato;
        tope++;

    }else{
        vector[fin] = vector[fin-1];
        rodar_pos(dato, inicio, fin-1);
    }
}


/* Validamos si esta en la primera o ultima posicion, si no esta, vamos comparando hasta llegar a la posicion deseada y
    llamamos a rodar_pos para que ruede todos los elementos
*/
void insertar(int dato, int n){
    if(tope == 0){
        vector[tope] = dato;
        tope++;
    }else{
        if(n <= tope-1){
            if(dato < vector[n]){

                rodar_pos(dato, n, tope);
            }else{
                insertar(dato, n+1);
            }
        }else{
            vector[tope] = dato;
            tope++;
        }

    }
}


/* Recorre  y muestra los elementos de un vector */

void mostrar_elementos(int n){
    if(n < tope){
        cout<<"[ "<<vector[n]<<" ]";
        mostrar_elementos(n+1);
    }
}


/* Buscar un elemento y retornar -99 si no lo encuentra */

int buscar_elemento(int dato, int n){

    if(n < tope){
        if(dato == vector[n]){
            return n;
        }else{
            buscar_elemento(dato, n+1);
        }
    }else{
        return -99;
    }
}


/* Llamamos a buscar elemento este retorna la posicion y eso se la pasamos a retraer_pos */


void retraer_pos(int inicio){
    if(inicio != tope-1){
        vector[inicio] = vector[inicio+1];
        retraer_pos(inicio+1);
    }else{
        tope--;
    }
}

void eliminar(int dato){

    int pos = buscar_elemento(dato, 0);

    if(pos != -99){
        retraer_pos(pos);
    }else{
        cout<< "Elemento no encontrado"<<endl;
    }
}


/* Recorre el vector y mira cuales datos son pares */

int pares(int n){

    int par = 0;

    if(n < tope){

        if(vector[n]%2 == 0){
           par =1;
        }
        return par + pares(n+1);
    }

    return 0;
}


/* calcula si un numero es primo, n siempre debe ser 1 */

int primo(int dato, int n){

    if(dato >= n){
        int c = 0;

        if(dato%n == 0){

            c = 1;
        }

        return c + primo(dato, n+1);
    }

    return 0;
}

int c_primos(int inicio){

    if(inicio < tope){

        int c = 0;

        if(primo(vector[inicio], 1) == 2){
            c = 1;
        }

        return c + c_primos(inicio+1);
    }

    return 0;
}


bool loop(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------- 1) Insertar de forma ordenada ----------------"<<endl;
    cout<<"----------------- 2) Mostrar Elementos          ----------------"<<endl;
    cout<<"----------------- 3) Buscar Elementos           ----------------"<<endl;
    cout<<"----------------- 4) Eliminar Elemento          ----------------"<<endl;
    cout<<"----------------- 5) Hallar total de pares      ----------------"<<endl;
    cout<<"----------------- 6) Hallar  primos             ----------------"<<endl;
    cout<<"----------------- 7) Insertar elementos en pos  ----------------"<<endl;
    cout<<"----------------- x) Salir                      ----------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;

    bool x = false;

    string opcion;
    cout<<" > ";
    getline(cin, opcion);



    if(opcion == "1"){
        cin.clear();
        int dato;
        cout<<"Ingrese dato > ";
        cin>>dato;
        insertar(dato,0);

    }


    if(opcion == "2"){
        cin.clear();
        mostrar_elementos(0);
        cin.ignore();
    }

    if(opcion == "3"){


        int dato;
        cout<<"Ingrese dato > ";
        cin>>dato;
        cout<<buscar_elemento(dato, 0);
        cin.ignore().get();

    }

    if(opcion == "4"){
        int dato;
        cout<<"Ingrese dato > ";
        cin>>dato;
        eliminar(dato);
        cin.ignore().get();
    }

    if(opcion == "5"){

        cout<<pares(0);
        cin.ignore().get();
    }

    if(opcion == "6"){

        cout<<c_primos(0);
        cin.ignore().get();
    }

    if(opcion == "7"){
        int dato;
        cout<<"Ingrese dato > ";
        cin>>dato;

        int pos;
        cout<<"Ingrese pos > ";
        rodar_pos(dato,pos, tope);
        cin.ignore().get();
    }

    if(opcion == "x"){
        x = true;
    }

    system("clear");
    return x;

}
int main(){

    while(!loop()){}

}
