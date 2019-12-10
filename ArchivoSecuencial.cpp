// HolaMundo.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	ofstream archivo;
	archivo.open("Prueba.txt");
	archivo << "Primera linea de texto" << endl;
	archivo << "Segunda linea de texto" << endl;
	archivo << "Ultima linea de texto" << endl;
	archivo.close();
	system("pause");

	ifstream archivo1;
	char texto[200];
	archivo1.open("Prueba.txt");
	archivo1.getline(texto, sizeof(texto));
	while (!archivo1.eof())
	{
		cout << texto << endl;
		archivo1.getline(texto, sizeof(texto));
	}
	archivo1.close();
	system("pause");

	ofstream archivo2;
	archivo2.open("Prueba.txt", ios::app);
	archivo2 << "Tercera linea de texto" << endl;
	archivo2.close();
	system("pause");

	return 0;
}
