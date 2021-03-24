/*
2. Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração
*/

#include <stdio.h>
int subtrai(int num1, int num2, int num3);

int main(){
	
    int num1, num2, num3, resultado;

    printf("NUMERO 1:\n");
    scanf("%d", &num1);

    printf("NUMERO 2:\n");
    scanf("%d", &num2);

    printf("NUMERO 3:\n");
    scanf("%d", &num3);

    resultado = subtrai(num1, num2, num3);

    printf("RESULTADO: %d\n", resultado);

    return 0;
}

int subtrai(int num1, int num2, int num3) {
    return num1 - num2 - num3;
}