/*
3. Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial
deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve
de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do
usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.
*/

#include <stdio.h>
int fatorial(int num);

int main(){
	
    int num, resultado;

    printf("NUMERO:\n");
    scanf("%d", &num);

    resultado = fatorial(num);

    if (resultado == -1) 
        printf("NAO E POSSIVEL CALCULAR FATORIAL\n");
    else
        printf("FATORIAL: %d\n", resultado);

	return 0;
}

int fatorial(int num) {
    if (num < 0)
        return -1;
    else if (num == 0)
        return 1;
    else {
        int i;
        int fatorial = 1;

        for (i = num; i > 0; i--)
            fatorial *= i;

        return fatorial;
    } 
}