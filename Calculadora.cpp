#include <iostream>
using namespace std;

class Calculadora
{
  public:
    int Calcular(int, int, char);
};

int main()
{
    int x, y, resultado;
    char oper; 
    cout << "Calculadora" << endl;
    cout << "Ingrese la operacion, ejemplo: 1+1" << endl;
    cin >>x>>oper>>y; 

    Calculadora c; 
    resultado = c.Calcular(x,y,oper);
    cout << "El resultado es: " <<resultado<<endl;

    cin.ignore();
    cin.get();
    return 0;
}

int Calculadora::Calcular(int x, int y, char oper)
{
    switch (oper)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y!=0)
            return x / y;
    default:
        return 0;
    }
}
