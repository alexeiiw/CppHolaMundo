#include <iostream>

// Incluimos librerias
using namespace std;

// Define clase Calculadora
class Calculadora {
    // Define metodo publico
    public:
    int Calcular (int, char, int) ;
};

// Metodo principal
int main() {

    // Define variables
    char chrNombre[10];
    int intNumero1, intNumero2, intResultado;
    Calculadora objCalc;
    char chrOperador;

    // Solicita datos
    cout << "Ingrese su nombre: " << endl;
    cin >> chrNombre;    

    cout << "Operación Suma " << endl;

    //cout << "Ingrese el primer valor: " << endl; 
    //cin >> intNumero1;

    //cout << "Ingrese el segundo valor: " << endl;
    //cin >> intNumero2;

    cout << "Ingrese la operación a realizar, por ejemplo 1+1 " << endl;
    cin >> intNumero1 >> chrOperador >> intNumero2;

    // Realiza las operaciones
    //intResultado = intNumero1 + intNumero2 ;
    intResultado = objCalc.Calcular(intNumero1, chrOperador, intNumero2);

    // Despliega datos
    cout << "Su nombre es: " << chrNombre << endl;

    cout << "El resultado es: " << intResultado << endl;

    // Retorna resultado
    return 0;
}

// Define metodo publico
int Calculadora::Calcular(int intNumber1, char chrOperator, int intNumber2){
    switch(chrOperator) {
        case '+':
            return intNumber1 + intNumber2 ;
        case '-':
            return intNumber1 - intNumber2 ;
        case '*':
            return intNumber1 * intNumber2 ;
        case '/':
            // Valida operación difernte a 0
            if (intNumber2 != 0)
                return intNumber1 / intNumber2 ;
        default:
            return 0; 
    }
}