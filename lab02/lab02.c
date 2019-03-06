/* O programa tem por objetivo descobrir se um triangulo e magico ou nao para isso a entrada e composta de varios 6 numeros que sao somados e depois verificados, como saida e dito se o triangulo e magico ou nao
Nome: Guilherme Dumas Peres
RA: 173711
*/

#include<stdio.h>

int main (void) {
	int v1, v2, v3, v4, v5, v6, soma1, soma2, soma3;
	
	scanf("%d", &v1);
	scanf("%d", &v2);
	scanf("%d", &v3);
	scanf("%d", &v4);
	scanf("%d", &v5);
	scanf("%d", &v6);
	soma1 = v1 + v2 + v3;
	soma2 = v3 + v4 + v5;
	soma3 = v5 + v6 + v1;
	if(soma1 == soma2 && soma1 == soma3 && soma2 == soma3) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}
	return 0;
}
