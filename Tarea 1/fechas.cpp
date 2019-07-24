#include <iostream>
#include <string>
using namespace std;

int main()
{
	//este es el programa para las fechas  ♠
	//formato es dd-mm-yyyy

	string entrada, aux;
	entrada = "";
	int d, m, y, e;

	cin >> entrada;
	//spliteamos
	e = 0;
	aux = "";
	for (int i = 0; i < entrada.size(); i++)
	{
		switch (e)
		{
		case 0:

			if (entrada[i] == '-')
			{
				d = stoi(aux);
				aux = "";
				e = 1;
			}
			else
			{
				if (isdigit(entrada[i]))
				{
					aux += entrada[i];
				}
				else
				{
					cout << "El siguiente caracter no pertenece al formato de fecha: " << entrada[i] << endl;
					e = 10;
				}

			}
			break;
		case 1:
			if (entrada[i] == '-')
			{
				m = stoi(aux);
				aux = "";
				e = 2;
			}
			else
			{
				if (isdigit(entrada[i]))
				{
					aux += entrada[i];
				}
				else
				{
					cout << "El siguiente caracter no pertenece al formato de fecha: " << entrada[i] << endl;
					e = 10;
				}

			}
			break;
		case 2:
			if (i == entrada.size() - 1)
			{
				aux += entrada[i];
				y = stoi(aux);
				aux = "";
				e = 10;
			}
			else
			{
				if (isdigit(entrada[i]))
				{
					aux += entrada[i];
				}
				else
				{
					cout << "El siguiente caracter no pertenece al formato de fecha: " << entrada[i] << endl;
					e = 10;
				}

			}
			break;
		default:
			i = entrada.size();
			break;
		}
	}
	string aux2="";
	string aux3 = "";
	int yy = 0;
	//lo chido
	if (y >= 1700)
	{
		//siglo
		if (y >= 1700 && y <= 1799)
		{
			e = 5;
		}
		if (y >= 1800 && y <= 1899)
		{
			e = 3;
		}
		if (y >= 1900 && y <= 1999)
		{
			e = 1;
		}
		if (y >= 2000 && y <= 2099)
		{
			e = 0;
		}
		if (y >= 2100 && y <= 2199)
		{
			e = -2;
		}
		if (y >= 2200 && y <= 2299)
		{
			e = -4;
		}
		//añooo
		if (m >= 1 && m <= 12)
		{
			aux2 = to_string(y);
			aux3 = aux2[2];
			aux3 += aux2[3];
			
			yy = stoi(aux3);
			
			e = e + (yy / 4)+yy;

			//bisiesto
			if (y % 400 == 0)
			{
				//si es bisiesto
				e = e - 1;
			}//si no es bisiesto no se modifica e   :)

			// el de los meses
			switch (m)
			{
			case 1://enero
				e = e + 6;
				break;
			case 2:
				e = e + 2;
				break;
			case 3:
				e = e + 2;
				break;
			case 4:
				e = e + 5;
				break;
			case 5:
				e = e + 0;
				break;
			case 6:
				e = e + 3;
				break;
			case 7:
				e = e + 5;
				break;
			case 8:
				e = e + 1;
				break;
			case 9:
				e = e + 4;
				break;
			case 10:
				e = e + 6;
				break;
			case 11:
				e = e + 2;
				break;
			case 12://diciembre
				e = e + 4;
				break;
			}
			//dias
			if (d >= 1 && d <= 31)
			{
				e = e + d;
				e = e % 7;
				switch (e)
				{
				case 0:
					cout << "Domingo" << endl;
					break;
				case 1:
					cout << "Lunes" << endl;
					break;
				case 2:
					cout << "Martes" << endl;
					break;
				case 3:
					cout << "Miercoles" << endl;
					break;
				case 4:
					cout << "Jueves" << endl;
					break;
				case 5:
					cout << "Viernes" << endl;
					break;
				case 6:
					cout << "Sabado" << endl;
					break;




				default:
					break;
				}
			}


		}
		else
		{
			cout << "Mes invalido";
		}



	}
	else
	{
		cout << "Año invalido" << y;
	}


}
