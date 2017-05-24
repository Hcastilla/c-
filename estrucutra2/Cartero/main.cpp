#include<iostream>
#include<allegro.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int w = 1280;
int h = 620;

float stepX = w / 10;
float stepY = h / 10;
int can =  10;


struct buzon{
    int x;
    int y;
    buzon *sig;
}*ptr;

struct carta{
    int x;
    int y;
    carta *sig;
}*ptr2;

void insertar_por_cabeza(buzon *p){
    p->sig = ptr;
    ptr = p;
}

void insertar_por_cola(buzon *p){
    if(ptr != NULL){

        buzon *k = ptr;
        while(k->sig != NULL){
            k = k->sig;
        }

        k->sig = p;
        p->sig = NULL;
    }else{
        insertar_por_cabeza(p);
    }
}

void recorrer(buzon *c){
    buzon *k = c;
    while(k != NULL){
        cout<<"( "<<k->x<<","<<k->y<<" )"<<endl;
        k = k->sig;
    }
}

void insertar_por_cabeza2(carta *p){
    p->sig = ptr2;
    ptr2 = p;
}

void insertar_por_cola2(carta *p){
    if(ptr2 != NULL){

        carta *k = ptr2;
        while(k->sig != NULL){
            k = k->sig;
        }

        k->sig = p;
        p->sig = NULL;
    }else{
        insertar_por_cabeza2(p);
    }
}

void recorrer2(carta *c){
    carta *k = c;
    while(k != NULL){
        cout<<"( "<<k->x<<","<<k->y<<" )"<<endl;
        k = k->sig;
    }
}
void dibujarGrilla(){

    line(screen,0,0,w,0,makecol( 255, 255, 255));
    line(screen,0,0,0,w,makecol( 255, 255, 255));

    for(int i = stepX; i< stepX*can; i+=stepX){

        line(screen,i,0,i,h,makecol( 255, 255, 255));
    }

    for(int i = stepY; i< stepY*can; i+=stepY){
        line(screen,0,i,w,i,makecol( 255, 255, 255));
    }
}

void dibujarBuzones(){
    for(int i = stepY; i< stepY*can; i+=stepY){
        circlefill(screen,stepX, i, 15, makecol(255,255,255));
        for(int j = stepX; j< stepX*can; j+=stepX){
            buzon *b = new buzon;
            b->x = j;
            b->y = i;
            insertar_por_cola(b);
            circlefill(screen,j, i, 15, makecol(255,255,255));
        }
    }
}


void cargarCartas(){

    srand (time(NULL));
    int nn[81];
    int  tope = 0;
    cout<<"Ingrese numero de cartas, maximo 81: ";
    int n;
    cin>>n;

    if(n<=81){
        int i = 0;

        while(i< n){
            int r = rand() % 81 + 1;
            cout<<r<<endl;
            bool valido = true;

            for(int x = 0; x<tope;x++){
                if(nn[x] == r){
                    valido = false;
                    break;
                }
            }

            if(valido){

                buzon *p = ptr;
                for(int l = 0 ; l<=r; l++){
                    p = p->sig;
                }

                carta *k = new carta;
                k->x = p->x;
                k->y = p->y;

                circlefill(screen,k->x, k->y, 20, makecol(251,255,0));
                insertar_por_cola2(k);
                i += 1;
                tope += 1;

            }
        }
        recorrer2(ptr2);



    }else{
        cout<<"Enserio ?"<<endl;
        exit(-1);
    }
}


int main(){

    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, w, h, 0, 0);
    dibujarGrilla();
    dibujarBuzones();
    recorrer(ptr);
    cargarCartas();
    readkey();

}
END_OF_MAIN();
