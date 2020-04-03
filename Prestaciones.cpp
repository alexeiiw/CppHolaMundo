// Define librerias
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

// Declara namespace
using namespace std;

// Declara metodos y funciones
double CalcularPrestaciones(double SalarioBase, int DiasTrabajados, int DiasAguinaldo, int DiasBono14, int DiasVacaciones);

int DevolverFecha(string Fecha, string Tipo);

int ObtenerDias(int DiaInicial, int MesInicial, int AnioInicial,
                int DiaFinal, int MesFinal, int AnioFinal);

// Metodo principal
int main() {
    // Define variables
    double DblSalarioBase;
    string StrFechaInicio, StrFechaFinal;
    int IntDiasAguinaldo, IntDiasBono14, IntDiasVacaciones, IntDiasTrabajados;

    // Ingresos
    cout << "Ingrese su salario base: ";
    cin >> DblSalarioBase;
    cout << endl;

    cout << "Ingrese la fecha de inicio: ";
    cin >> StrFechaInicio;
    cout << endl;

    cout << "Ingrese la fecha de baja: ";
    cin >> StrFechaFinal;
    cout << endl;

    cout << "Ingrese dias aguinaldo: ";
    cin >> IntDiasAguinaldo;
    cout << endl;

    cout << "Ingrese dias bono 14: ";
    cin >> IntDiasBono14;
    cout << endl;

    cout << "Ingrese dias vacaciones: ";
    cin >> IntDiasVacaciones;
    cout << endl;

    // Calcula los dias trabajados
    IntDiasTrabajados = ObtenerDias(DevolverFecha(StrFechaInicio,"dia"),DevolverFecha(StrFechaInicio,"mes"),DevolverFecha(StrFechaInicio,"anio"),
                                    DevolverFecha(StrFechaFinal,"dia"),DevolverFecha(StrFechaFinal,"mes"),DevolverFecha(StrFechaFinal,"anio"));

    cout << "Su indemnización es: ";
    cout << CalcularPrestaciones(DblSalarioBase,IntDiasTrabajados,IntDiasAguinaldo,IntDiasBono14,IntDiasVacaciones);
    cout << endl;

    return 0;
}

// Metodos y Funciones

// Metodo que calcula las prestaciones
double CalcularPrestaciones(double SalarioBase, int DiasTrabajados, int DiasAguinaldo, int DiasBono14, int DiasVacaciones) {
    // Define variables y constantes
    int IntAnio = 365;
    int IntMes = 12;
    int IntDiasMes = 30;
    double DblIndemnizacion, DblAguinaldo, DblBono14, DblVacaciones;

    // Calculos
    DblIndemnizacion = ((SalarioBase * (DiasTrabajados/IntDiasMes))/IntMes);
    DblAguinaldo = ((SalarioBase * DiasAguinaldo)/IntAnio);
    DblBono14 = ((SalarioBase * DiasBono14)/IntAnio);
    DblVacaciones = ((SalarioBase * DiasVacaciones)/IntDiasMes);

    // Retorna indeminizacion
    return DblIndemnizacion + DblAguinaldo + DblBono14 + DblVacaciones;
}

// Calcula los dias entre una fecha inicial y una final
int ObtenerDias(int DiaInicial, int MesInicial, int AnioInicial,
                int DiaFinal, int MesFinal, int AnioFinal) {
    // Define variables
    double DblFechaDiferencia;

    // Traslada todo a una estructura
    struct tm a = {0,0,0,DiaInicial,MesInicial,100 + AnioInicial}; // Fecha inicial 01/03/2019
    struct tm b = {0,0,0,DiaFinal,MesFinal,100 + AnioFinal}; // Fecha final 30/04/2019

    // Convierte todo a tiempo
    time_t x = mktime(&a);
    time_t y = mktime(&b);

    // Opera la diferencia de fechas
    if ( x != (time_t)(-1) && y != (time_t)(-1))
    {
        DblFechaDiferencia = difftime(y,x) / (60 * 60 * 24);
    }

    // Retorna los dias de diferencia
    return DblFechaDiferencia;
}

// Convierte en numero el parametro de fecha
int DevolverFecha(string Fecha, string Tipo) {
    // Define variables
    string StrFecha;
    int IntNumero;

    // Evalua el retorno
    if (Tipo == "dia") {StrFecha = Fecha.substr(0,2);}
    if (Tipo == "mes") {StrFecha = Fecha.substr(3,2);}
    if (Tipo == "anio") {StrFecha = Fecha.substr(8,2);}

    // Realiza conversion
    istringstream Texto (StrFecha);
    Texto >> IntNumero;

    // Retorna el parametro de fecha solicitado
    return IntNumero;
}
