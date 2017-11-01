#include <iostream>
#include "aritmetica.h"
#include "potencias.h"

#define NUM1	5
#define NUM2	2

using namespace std;

int main (){
  cout << "Dados los números "    << NUM1 << " y " << NUM2 << endl;
  cout << "-----------------------------------------" << endl;
  cout << "La suma es "           << suma (NUM1, NUM2) << endl;
  cout << "La resta es "          << resta (NUM1, NUM2) << endl;
  cout << "La multiplicación es " << multiplicacion (NUM1, NUM2) << endl;
  cout << "La división es "       << division (NUM1, NUM2) << endl;
  cout << "-----------------------------------------" << endl;
  cout << "El cuadrado de "       << NUM1 << " es " << cuadrado(NUM1) << endl;
  cout << "El cubo de "           << NUM1 << " es " << cubo(NUM1) << endl << endl;
  return 0;
}
