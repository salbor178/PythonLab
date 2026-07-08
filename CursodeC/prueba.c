#include <stdio.h>
//#define MACRO(v) v*v*v // macro es como una mini funcion que devuelve el cubo de un numero
int main()
{
    char C = 'y'; // tamaño de 1 byte desde 0 ... hasta 255
    int a = 20; //2 bytes -32768 ... 32767
    short e = -1; // 2 bytes -128 ... 127
    unsigned int u = 25;// 2 bytes  0 ... 65535
    long l = 5932; // 4bytes desde -2147483648 ... hasta 2146483647
    float f = 72.534; // 4 bytes
    double d = 12323.877658; // 8 bytes

    printf("%C\n", C);
    


    system("pause");
    return 0;
}
