/*
1. Crie um programa que tenha uma função soma e a função main. A função main deve ler dois
valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A
Função main deve imprimir o resultado da soma
*/

#include <stdio.h>
int soma(int num1, int num2);

int main(){
	
    int num1, num2, resultado;

    printf("NUMERO 1:\n");
    scanf("%d", &num1);

    printf("NUMERO 2:\n");
    scanf("%d", &num2);

    resultado = soma(num1, num2);

    printf("RESULTADO: %d\n", resultado);

	return 0;
}

int soma(int num1, int num2) {
    return num1 + num2;
}