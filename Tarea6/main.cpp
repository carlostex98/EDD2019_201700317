#include <string>
#include <iostream>
using namespace std;

class produtos{
int codigo;
int stock;
int min_stock;
string proveedor;
productos* siguiente;
}*primero, *ultimo;

class pro_min{
int codigo;
int stock;
int min_stock;
string proveedor;
pro_min* siguiente;
}*pri_m, *ult_m;

void mas_min(pro_min *nuevo){
   pro_min* actual=pri_m;
   pro_min* ss=nuevo;
    while(true){
        if(pri_m==nullptr){
            pri_m=ss;
            break;
        }else{
            ult_m->siguiente=ss;
            ult_m=ss;
            break;
        }
    }

}

void mover_min(){
productos* actual=primero;
while(true){
    if(actual==nullptr){

        break;
    }
    else{
        if(actual->stock<actual->min_stock){
            mas_min(actual);
            break;
        }
        actual=actual->siguiente;
    }
}

}
void drop_100(){
    productos* actual=primero;
    while(true){
            if actual==nullptr break;

        if(actual->stock>100){
            delete(actual);
        }
        actual=actual->siguiente;

    }
}

int main()
{
    cout << "Hola"<<endl;
	return 0;
}
