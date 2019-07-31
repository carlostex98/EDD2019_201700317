#include <iostream>
#include <string>
using namespace std;

struct bolsa {
	int id;
	bolsa* siguiente;

}*primero,*ultimo;

bool es_vacia() {
	bool x = false;

	if (primero==NULL)
	{
		x = true;
	}
	return x;
}

void insertar(bolsa* nuevo,int n) {

	nuevo->id = n;
	if (primero==NULL)
	{
		primero = nuevo;
		ultimo = nuevo;
		ultimo->siguiente = ultimo;
	}
	else
	{
		ultimo->siguiente = nuevo;
		ultimo = nuevo;
		ultimo->siguiente = ultimo;
	}


}

int cuantos(bolsa* actual) {
	int val = 0;
	do
	{
		actual = actual->siguiente;
		val++;
	} while (actual=NULL);

	return val;
}

int main()
{
	
	return 0;
}
