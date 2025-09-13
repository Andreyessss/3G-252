#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int variable = 7;
    cout << "Direcion : " << &variable << endl;
    cout << "Valor: " << variable << endl;
    cout << "Indireccion: " << *(&variable) << endl;
    cout << "int : " << sizeof(int) << endl;
    cout << "bool : " << sizeof(bool) << endl;
    cout << "char : " << sizeof(char) << endl;
    cout << "double : " << sizeof(double) << endl;
    cout << "byte : " << sizeof(byte) << endl;
    cout << "float : " << sizeof(float) << endl;

    void *direccion = malloc(4);
    cout << "Direccion valor :" << direccion << endl;
    cout << "Tamaño : " << sizeof(direccion) << endl;
    cout << "Direccion puntero : " << &direccion << endl;


    //casteo
    int prueba = 64;
    char casteo = (char)prueba;
    cout << "Resultado: " << casteo << endl;

    return 0;
}
    