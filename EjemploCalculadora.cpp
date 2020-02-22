#include <iostream>

// Incluimos librerias
using namespace std;

// Definición de clases
class Calculadora {
    // Definir un método público
    public:
    int Calcular (int,char,int) ;
};

// Metodo principal
int main() {

    // Definir variables
    char chrNombre[10];
    int intNumero1, intNumero2, intResultado;
    Calculadora objCalculadora;
    char chrOperador;

    // Solicitar el nombre
    cout << "Ingrese su nombre: " << endl;
    cin >> chrNombre;

    // Solicitar datos de la suma
    //cout << "Ingrese el primer valor: " << endl;
    //cin >> intNumero1;

    //cout << "Ingrese el segundo valor: " << endl;
    //cin >> intNumero2;

    cout << "Ingrese la operación a realizar, por ejemplo: 1+1 " << endl;
    cin >> intNumero1 >> chrOperador >> intNumero2 ; 

    // Realiza las operaciones
    //intResultado = intNumero1 + intNumero2;
    intResultado = objCalculadora.Calcular(intNumero1, chrOperador, intNumero2);

    // Imprime el nombre
    cout << "Su nombre es: " << chrNombre << endl;

    cout << "El resultado: " << intResultado << endl;

    // Retonar valor
    return 0;
}

// Define método público
int Calculadora::Calcular(int intNumber1, char chrOperator, int intNumber2) {
    switch(chrOperator){
        case '+':
            return intNumber1 + intNumber2;
        case '-':
            return intNumber1 - intNumber2;
        case '*':
            return intNumber1 * intNumber2;
        case '/':
            // Validamos diferente a 0
            if (intNumber2 != 0)
                return intNumber1 / intNumber2; 
        default:
            return 0;
    }
}