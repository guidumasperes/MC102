#include<stdio.h>

int main(void) {
	int num, triang, soma = 0, i;

	scanf("%d", &num);
	triang = num * (num + 1) / 2;
	for(i = 1; i <= num; i++) {
		soma = soma + i;
	}
	if(triang == soma) {
		printf("e triangular");
	} else {
		printf("nao e triangular");
	}
	return 0;
}
