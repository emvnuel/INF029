/*
4. Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do
usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno.
*/

#include <stdio.h>
int* ler3Numeros();

int main(){
	
    int *arr;
    int i;

    arr = ler3Numeros();

    for(i = 0; i < 3; i++)
        printf("%d ", arr[i]);

    printf("\n");

	return 0;
}

int* ler3Numeros() {
	
    static int arr[3];

    printf("NUMERO 1:\n");
    scanf("%d", &arr[0]);

    printf("NUMERO 2:\n");
    scanf("%d", &arr[1]);

    printf("NUMERO 3:\n");
    scanf("%d", &arr[2]);

    return arr;
}