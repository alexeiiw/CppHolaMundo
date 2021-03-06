// alea.cpp: Ejemplo de ficheros de acceso aleatorio.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

// Funciones auxiliares:
int Menu();
long LeeNumero();

// Clase registro.
class Registro {
  public:
   Registro(char *n=NULL, int d1=0, int d2=0, int d3=0, int d4=0) : valido('S') {
     if(n) strcpy(nombre, n); else strcpy(nombre, "");
     dato[0] = d1;
     dato[1] = d2;
     dato[2] = d3;
     dato[3] = d4;
   }
   void Leer();
   void Mostrar();
   void Listar(long n);

   const bool Valido() { return valido == 'S'; }
   const char *Nombre() { return nombre; }
  private:
   char valido;  // Campo que indica si el registro es v�lido
                 // S->V�lido, N->Inv�lido
   char nombre[34];
   int dato[4];
};

// Implementaciones de clase Registro:
// Permite que el usuario introduzca un registro por pantalla
void Registro::Leer() {
   system("cls");
   cout << "Leer registro:" << endl << endl;
   valido = 'S';
   cout << "Nombre: ";
   cin.getline(nombre, 34);
   for(int i = 0; i < 4; i++) {
      cout << "Dato[" << i << "]: ";
      dato[i] = LeeNumero();
   }
}

// Muestra un registro en pantalla, si no est� marcado como borrado
void Registro::Mostrar()
{
   system("cls");
   if(Valido()) {
      cout << "Nombre: " << nombre << endl;
      for(int i = 0; i < 4; i++)
         cout << "Dato[" << i << "]: " << dato[i] << endl;
   }
   cout << "Pulsa una tecla";
   cin.get();
}

// Muestra un registro por pantalla en forma de listado,
// si no est� marcado como borrado
void Registro::Listar(long n) {
   int i;

   if(Valido()) {
      cout << "[" << setw(6) << n << "] ";
      cout << setw(34) << nombre;
      for(i = 0; i < 4; i++)
         cout << ", " << setw(4) << dato[i];
      cout << endl;
   }
}

// Clase Datos, almacena y trata los datos.
class Datos :public fstream {
  public:
   Datos() : fstream("alea.dat", ios::in | ios::out | ios::binary) {
      if(!good()) {
         open("alea.dat", ios::in | ios::out | ios::trunc | ios::binary);
         cout << "fichero creado" << endl;
         cin.get();
      }
   }
  ~Datos() {
     Empaquetar();
   }
   void Guardar(Registro &reg);
   bool Recupera(long n, Registro &reg);
   void Borrar(long n);

  private:
   void Empaquetar();
};

// Implementaci�n de la clase Datos.
void Datos::Guardar(Registro &reg) {
   // Insertar al final:
   clear();
   seekg(0, ios::end);
   write(reinterpret_cast<char *> (&reg), sizeof(Registro));
   cout << reg.Nombre() << endl;
}

bool Datos::Recupera(long n, Registro &reg) {
   clear();
   seekg(n*sizeof(Registro), ios::beg);
   read(reinterpret_cast<char *> (&reg), sizeof(Registro));
   return gcount() > 0;
}

// Marca el registro como borrado:
void Datos::Borrar(long n) {
   char marca;

   clear();
   marca = 'N';
   seekg(n*sizeof(Registro), ios::beg);
   write(&marca, 1);
}

// Elimina los registros marcados como borrados
void Datos::Empaquetar() {
   ofstream ftemp("alea.tmp", ios::out);
   Registro reg;

   clear();
   seekg(0, ios::beg);
   do {
      read(reinterpret_cast<char *> (&reg), sizeof(Registro));
      cout << reg.Nombre() << endl;
      if(gcount() > 0 && reg.Valido())
         ftemp.write(reinterpret_cast<char *> (&reg), sizeof(Registro));
   } while (gcount() > 0);
   ftemp.close();
   close();
   remove("alea.bak");
   rename("alea.dat", "alea.bak");
   rename("alea.tmp", "alea.dat");
   open("alea.dat", ios::in | ios::out | ios::binary);
}

int main()
{
   Registro reg;
   Datos datos;
   int opcion;
   long numero;

   do {
      opcion = Menu();
      switch(opcion) {
         case '1': // A�adir registro
            reg.Leer();
            datos.Guardar(reg);
            break;
         case '2': // Mostrar registro
            system("cls");
            cout << "Mostrar registro: ";
            numero = LeeNumero();
            if(datos.Recupera(numero, reg))
               reg.Mostrar();
            break;
         case '3': // Eliminar registro
            system("cls");
            cout <<  "Eliminar registro: ";
            numero = LeeNumero();
            datos.Borrar(numero);
            break;
         case '4': // Mostrar todo
            numero = 0;
            system("cls");
            cout << "Nombre                             Datos" << endl;
            while(datos.Recupera(numero, reg)) reg.Listar(numero++);
            cout << "pulsa return";
            cin.get();
            break;
      }
   } while(opcion != '0');
   return 0;
}

// Muestra un men� con las opciones disponibles y captura una opci�n del usuario
int Menu()
{
   char resp[20];

   do {
      system("cls");
      cout << "MENU PRINCIPAL" << endl;
      cout << "--------------" << endl << endl;
      cout << "1- Insertar registro" << endl;
      cout << "2- Mostrar registro" << endl;
      cout << "3- Eliminar registro" << endl;
      cout << "4- Mostrar todo" << endl;
      cout << "0- Salir" << endl;
      cin.getline(resp, 20);
   } while(resp[0] < '0' && resp[0] > '4');
   return resp[0];
}

// Lee un n�mero suministrado por el usuario
long LeeNumero()
{
   char numero[6];

   fgets(numero, 6, stdin);
   return atoi(numero);
}
