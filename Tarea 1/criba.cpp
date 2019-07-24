#include <iostream>
#include <string>
using namespace std;

struct numero {
	int id;
	int marca;
	numero* siguiente;

}*primero,*ultimo;

void agregar(int n) {
	numero* actual = new numero();
	actual->id = n;
	actual->marca = 0;

	if (ultimo==NULL)
	{
		ultimo = actual;
		primero = actual;
	}
	else
	{
		ultimo->siguiente = actual;
		ultimo = actual;
	}
}

void mostrar() {
	numero* actual = new numero();
	actual = primero;

		do
		{
			if (actual->marca==0)
			{
				cout << actual->id << endl;
			}
			actual = actual->siguiente;
		} while (actual!=NULL);

}
void marcar(int max) {
	//primero los pares
	numero* actual = new numero();
	actual = primero;


	for (int i = 2; i < sqrt(max); i++)
	{
		actual = primero;
		do
		{
			if (actual->id % i == 0 && actual->id != i)
			{
				actual->marca = 1;
			}
			actual = actual->siguiente;
		} while (actual != NULL);
		if (i!=2)
		{
			i++;
		}
	}
}


int main()
{
	
	int lim = 0;
	
	cin >> lim;

	for (int i = 2; i <= lim; i++)
	{
		agregar(i);		
	}

	marcar(lim);
	mostrar();
	
	return 0;
}