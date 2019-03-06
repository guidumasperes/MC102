/* O objetivo do programa e calcular a circunferencia de um determinado planeta sendo a entrada a distancia entre dois pontos na superficie desse planeta e o angulo formado entre esses dois pontos e a saida e o comprimento dessa circunferencia em estadios e em km
Nome: Guilherme Dumas Peres
RA: 173711
*/

#include<stdio.h>

int main (void) {
	float d, a, ce, cm, ckm;

	scanf("%f", &d);
	scanf("%f", &a);
	ce = (360.0 * d) / a;
	cm = ce * 176.4;
	ckm = cm / 1000.0;
	printf("%.1f\n", ce);
	printf("%.1f\n", ckm);
	return 0;
}
