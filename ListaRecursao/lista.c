#include <stdio.h>
int q1(int num);
int q2(int num);
int q3(int num);
int q4(int vetor[], int tamanhoVetor);
int q5(int num);
int q6(int k, int n);

int inverso = 0;

int main(){

	printf("Fatorioal de 5 = %d\n", q1(5));
	printf("Fib 12 = %d\n", q2(12));
	printf("123 inverso = %d\n", q3(123));
    int arr[] = { 1, 2, 3, 4, 5 };
    printf("Soma arrays de 1 a 5: %d\n", q4(arr, 5));
    printf("Somatorio de 1 a 5: %d\n", q5(5));
    printf("2 elevado a 10: %d\n", q6(2, 10));
	
	return 0;
}

int q1(int num) {
    if (num == 0)
        return 1;
    if (num == 1)
        return 1;

    return num * q1(num - 1);
}

int q2(int num) {
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    return q2(num - 2) + q2(num - 1); 
}

int q3(int num) {

    if (num == 0)
        return inverso;
    if (num > 0) {
        int temp = num % 10;
        inverso = inverso * 10 + temp;
        q3(num / 10);
    }
    return inverso;
}

int q4(int vetor[], int tamanhoVetor) {
    if (tamanhoVetor <= 0)
        return 0;
    return (q4(vetor, tamanhoVetor - 1) + vetor[tamanhoVetor - 1]);
}

int q5(int num) {
	if(num > 0)
		return num + q5(num - 1);

    return 0;
}

int q6(int k, int n) {
    if (n == 0)
        return 1;

    return k * q6(k, n - 1);
}

