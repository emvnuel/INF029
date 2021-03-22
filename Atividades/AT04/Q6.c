/*
6. Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras.
*/

#include <stdio.h>
char* ler3Letras();

int main(){
	
    char *arr;
    int i;

    arr = ler3Letras();

    for(i = 0; i < 3; i++)
        printf("%c ", arr[i]);

    printf("\n");

	return 0;
}

char* ler3Letras() {
	
    static char arr[3];

    printf("DIGITE AS LETRAS:\n");
    scanf("%c %c %c", &arr[0], &arr[1], &arr[2]);

    return arr;
}