#include <iostream>
using namespace std;
void contarhastaNrecursivo(int n)
{
    // caso base
    if (n == 0)
        return;
    contarhastaNrecursivo(n - 1); // caso recursivo
}

int calcular_factorial(int n)
{
    // caso base
    if (n == 0)
        return 1;
    // caso recursivo
    return n * calcular_factorial(n - 1);
}
int contar_digitos(int n)
{
    // caso base
    if (n < 10)
        return 1;
    // caso recursivo
    return 1 + contar_digitos(n / 10); //c++ es un lenguaje tipado por lo tanto al dividir el numero n entre 10 
    //no le importaran los decimales
}

int fibonacci(int n){
    //caso base: si es cero retornar 
if (n <= 1)return n;
return fibonacci(n -1 ) + fibonacci(n - 2);
}
int main()
{
    int n = 5;
    contarhastaNrecursivo(n);
    calcular_factorial(n);
    cout << fibonacci(n) << endl;
    return 0;
}
