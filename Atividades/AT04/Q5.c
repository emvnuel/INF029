/*
5. Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do
usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize
struct para fazer o retorno.
*/

#include <stdio.h>
typedef struct Numeros {
    int num1;
    int num2;
    int num3;
    int num4;
} Numeros;

Numeros ler4Numeros();

int main(){
	
    Numeros numeros = ler4Numeros();
    printf("NUMERO 1: %d\n", numeros.num1);
    printf("NUMERO 2: %d\n", numeros.num2);
    printf("NUMERO 3: %d\n", numeros.num3);
    printf("NUMERO 4: %d\n", numeros.num4);

    return 0;
}

Numeros ler4Numeros() {
	
    Numeros numeros;

    printf("NUMERO 1:\n");
    scanf("%d", &numeros.num1);

    printf("NUMERO 2:\n");
    scanf("%d", &numeros.num2);

    printf("NUMERO 3:\n");
    scanf("%d", &numeros.num3);

    printf("NUMERO 4:\n");
    scanf("%d", &numeros.num4);

    return numeros;
}