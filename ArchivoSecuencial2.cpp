// Librerias
#include<iostream>
#include<fstream>
#include<stdlib.h>

// Define namespace
using namespace std;

// Metodo que crea el archivo
int CrearArchivo() {
    // Define objeto
    ofstream archivo;
    // Abre el archivo, si no esta creado procede
    archivo.open("Prueba.txt");
    // Imprime la primera línea
    archivo << "Primera línea del texto" <<endl;
    archivo << "Segunda línea del texto" <<endl;
    archivo << "Tercera línea del texto" <<endl;
    // Cierra el archivo
    archivo.close();
    // Mensaje de salida
    cout<<"Archivo creado..."<<endl;
    // Pausa en el sistema
    system("pause");
    // Retorna 0
    return 0;
}

int LeerArchivo() {
    // Mensaje de salida
    cout<<"Procedemos a leer el archivo..." <<endl;
    // Define objeto
    ifstream archivo;
    // Define variables
    char texto[200];
    // Abre el archivo (solo lectura)
    archivo.open("Prueba.txt");
    // Carga la primera línea, hasta retorno de carro, en la variable
    archivo.getline(texto,sizeof(texto));
    // Recorre el archivo mientras no este vacio
    while (!archivo.eof())
    {
        // Imprime el contenido
        cout<<texto<<endl;
        // Carga la primera línea, hasta retorno de carro, en la variable
        archivo.getline(texto,sizeof(texto));
    }
    // Cierra el archivo
    archivo.close();
    // Pausa en el sistema
    system("pause");
    // Retorna 0
    return 0;
}

int AgregarLineas(){
    // Define objeto
    ofstream archivo;
    // Abre el archivo para agregar datos
    archivo.open("Prueba.txt", ios::app);
    // Imprime línea
    archivo << "Cuarta línea del texto"<<endl;
    // Cierra el archivo
    archivo.close();
    // Mensaje de salida
    cout<<"Linea creada con exito"<<endl;
    // Pausa
    system("pause");
    // Retorna 0
    return 0;
}

// Metodo principal
int main() {

    CrearArchivo();

    LeerArchivo();

    AgregarLineas();

    LeerArchivo();

    // Pausa en el sistema
    system("pause");
    return 0;
}
