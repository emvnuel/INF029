#include <stdio.h>
float somar(float x, float y);
float subtrair(float x, float y);
float multiplicar(float x, float y);
float dividir(float x, float y);
int main(){

	int opcao;
	float numero1, numero2;
	float resultado;	

	do {
		printf("\nDigite uma opcao:\n");
		printf("0 - Sair, 1 - Somar, 2 - Subtrair, 3 - Multiplicar, 4 - Dividir:\n");
		scanf("%d", &opcao);

		if (opcao == 0)
			break;

		printf("Digite o numero 1 da operacao:\n");
		scanf("%f", &numero1);
		
		printf("Digite o numero 2 da operacao:\n");
		scanf("%f", &numero2);

		switch(opcao) {
			case 1:
				resultado = somar(numero1, numero2);		
				break;

			case 2:
				resultado = subtrair(numero1, numero2);		
				break;

			case 3:
				resultado = multiplicar(numero1, numero2);		
				break;

			case 4:
				resultado = dividir(numero1, numero2);	
				break;

			default:
				printf("Opcao invalida\n");
				break;
		}

		
		printf("Resultado: %.2f\n", resultado);	
	}
	while(opcao != 0);
	
	return 0;
}

float somar(float num1, float num2) {
	return num1 + num2;
}

float subtrair(float num1, float num2) {
	return num1 - num2;
}

float multiplicar(float num1, float num2) {
	return num1 * num2;
}

float dividir(float num1, float num2) {
	return num1 / num2;
}