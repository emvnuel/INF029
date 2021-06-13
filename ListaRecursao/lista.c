#include <stdio.h>
int q1(int num);
int q2(int num);
int q4(int vetor[], int tamanhoVetor);
int q5(int num);
int q6(int k, int n);
int q8(int x, int y);
void q12(int n);
void q13(int n);
int q22(int n);
int q23(int n);
int q24(int n);
int q18(int n);
int q40(int n);
int q44(int n);
int q30(int m, int n);

int main(){

	printf("Fatorioal de 5 = %d\n", q1(5));
	printf("Fib 12 = %d\n", q2(12));
    int arr[] = { 1, 2, 3, 4, 5 };
    printf("Soma arrays de 1 a 5: %d\n", q4(arr, 5));
    printf("Somatorio de 1 a 5: %d\n", q5(5));
    printf("2 elevado a 10: %d\n", q6(2, 10));
    printf("O Máximo Divisor Comum de 24 e 64: %d\n", q8(24, 64));
    printf("10 elemento da sequencia de tetranacci: %d\n", q22(10));
    printf("13 elemento da sequencia de padovan: %d\n", q23(13));
    printf("6 elemento da sequencia de Pell: %d\n", q24(6));
    printf("Superfatorial de 4: %d\n", q18(4));
    printf("10 elemento da sequencia: %d\n", q40(10));
    printf("3 elemento da sequencia: %d\n", q44(3));
    printf("Ackerman: %d\n", q30(2, 3));

    q12(10);
    printf("\n");
    q13(10);
    printf("\n");
	
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

int q8(int x, int y){
	if(y == 0)
		return x;

	return q8(y, x % y);

}

void q12(int n) {

    if(n >= 0){
    	q12(n - 1);
    	printf("%d ", n);
    }

}


void q13(int n){

    if(n >= 0){
    	printf("%d ", n);
    	q13(n - 1);
    }

}

int q22(int n) {
    if (n == 0 || n == 1 || n == 2)
        return 0;
    if (n == 3)
        return 1;
    
    return q22(n - 4) + q22(n - 3) + q22(n - 2) + q22(n - 1);

}

int q23(int n) {
    if (n == 0 || n == 1 || n == 2)
        return 1;
    
    return q23(n - 2) + q23(n - 3);
}

int q24(int n) {
    if (n <= 2)
        return n;
    return 2 * q24(n - 1) + q24(n - 2);
}

int q18(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    return q1(n) * q18(n - 1);
}

int q40(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    return 2 * q40(n - 1) + 3 * q40(n - 2);
}

int q44(int n) {
    if (n == 1)
        return 1;

    return (n*n*n) + q44(n - 1);
}

int q30(int m, int n)
{
    if (m == 0){
        return n+1;
    }
    else if((m > 0) && (n == 0)){
        return q30(m-1, 1);
    }
    else if((m > 0) && (n > 0)){
        return q30(m-1, q30(m, n-1));
    }
}