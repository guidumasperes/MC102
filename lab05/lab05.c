/*
Nome: Guilherme Dumas Peres
RA: 173711
Entrada: Números inteiros que representam o valor do PIB
Saída: O triênio com maior crescimento
Objetivo: Calcular o maior crescimento do PIB num determinado triênio
*/
#include<stdio.h>

int main (void) {
	int n, i, indice, j, cnt = 0; 
	float v_pib[50], v_per[50], v_media[50], maior;	

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%f", &v_pib[i]);
	}
/*É preciso calcular o crescimento percentual em n anos*/
	v_per[0] = 0.00;
	for(i = 1; i <= n; i++) {
		v_per[i] = ((v_pib[i] - v_pib[i - 1]) / v_pib[i - 1])*100;
	}
/*Agora calcula-se a média dos triênios*/
	for(i = 0; i < n - 2; i++) {
		v_media[i] = (v_per[i] + v_per[i + 1] + v_per[i + 2]) / 3;
		cnt++;
	}
	maior = v_media[0];
	indice = 0;
/*Agora achamos a maior média*/
	for(i = 0; i < cnt; i++) {
		for(j = i + 1; j < cnt; j++) {
			if(maior < v_media[j]) {
				maior = v_media[j];
				indice = j;
			}
		}
	}
	printf("a maior media de crescimento foi entre os anos %d e %d: %.1f\n", indice, indice + 2, maior);
	return 0;
}
