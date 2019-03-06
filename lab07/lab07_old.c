/*
Nome: Guilherme Dumas Peres
RA: 173711
Entrada: A entrada é composta de números positivos e números negativos
Saída: Quem venceu a batalha
Objetivos: Fazer calculos através do programa para descobrir quem ganhou a luta
*/
#include<stdio.h>

int main(void) {
	int soma_ryu = 0, soma_ken = 0, num, i = 0, cnt = 0, vetor_luta[100], rounds_ryu = 0, rounds_ken = 0, j, soma_perf = 0, achou, vetor_triangular[100];
/*Calcular 100 primeiros numeros triangulares*/
	for(j = 1; j <= 100; j++) {
		vetor_triangular[j] = j * (j + 1) / 2;
	}
/*Ler números e guardar no vetor até apertar '0'*/
	do {
		scanf("%d", &num);
		vetor_luta[i] = num;
		i++;
		cnt++;
	} while(num != 0);
	for(j = 1; j < vetor_luta[0]; j++) { /*isso é para conferir se é perfeito*/
		if(vetor_luta[0] % j == 0) {
			soma_perf = soma_perf + j;
		}
	}
	achou = 0;
	for(j = 1; j <= 100; j++) { /*isso é para conferir se é triangular*/
		if(vetor_luta[0] == vetor_triangular[j]) {
			achou = 1;
		}
	}
	if(soma_perf == vetor_luta[0]) { /*Se isso ocorre o número é perfeito então o golpe será multiplicado por 3*/
		soma_ryu = 3 * vetor_luta[0];
	} else if(achou) {				/*Se isso ocorre o número é triangular então o golpe será multiplicado por 2*/
		soma_ryu = 2 * vetor_luta[0]; 
	} else {
		soma_ryu = vetor_luta[0];
	}
	for(i = 1; i < cnt; i++) {
/*Esse if determina quando acaba e quando termina um round*/
		if((vetor_luta[i] > 0 && vetor_luta[i - 1] < 0) || vetor_luta[i] == 0) {
			if(soma_ryu > soma_ken) {
				rounds_ryu++;
			} else if(soma_ryu < soma_ken) {
				rounds_ken++;
			} else if(soma_ryu == soma_ken){
				rounds_ryu++;
				rounds_ken++;
			}
			soma_ken = 0;
			soma_ryu = 0;
			soma_perf = 0;
			for(j = 1; j < vetor_luta[i]; j++) {
				if(vetor_luta[i] % j == 0) {
					soma_perf = soma_perf + j;
				}
			}
			achou = 0;
			for(j = 1; j <= 100; j++) {
				if(vetor_luta[i] == vetor_triangular[j]) {
					achou = 1;
				}
			}
			if(soma_perf == vetor_luta[i]) {
				soma_ryu = 3 * vetor_luta[i];
			} else if(achou) {
				soma_ryu = 2 * vetor_luta[i];
			} else {
				soma_ryu = vetor_luta[i];
			}
/*Fazer as condições para quando o Ken ganha ponto e quando o Ryu ganha ponto*/
		} else if(vetor_luta[i] > 0 && vetor_luta[i - 1] > 0) {
			soma_perf = 0;
			for(j = 1; j < vetor_luta[i]; j++) {
				if(vetor_luta[i] % j == 0) {
					soma_perf = soma_perf + j;
				}
			}
			achou = 0;
			for(j = 1; j <= 100; j++) {
				if(vetor_luta[i] == vetor_triangular[j]) {
					achou = 1;
				}
			}
			if(soma_perf == vetor_luta[i]) {
				soma_ryu = soma_ryu + (3 * vetor_luta[i]);
			} else if(achou) {
				soma_ryu = soma_ryu + (2 * vetor_luta[i]);
			} else {
				soma_ryu = vetor_luta[i];
			}
		} else if((vetor_luta[i] < 0 && vetor_luta[i - 1] < 0) || (vetor_luta[i] < 0 && vetor_luta[i - 1] > 0)){
			soma_perf = 0;
			for(j = 1; j < -vetor_luta[i]; j++) {
				if(-vetor_luta[i] % j == 0) {
					soma_perf = soma_perf + j;
				}
			}
			achou = 0;
			for(j = 1; j <= 100; j++) {
				if(-vetor_luta[i] == vetor_triangular[j]) {
					achou = 1;
				}
			}
			if(soma_perf == -vetor_luta[i]) {
				soma_ken = soma_ken + (3 * -vetor_luta[i]);
			} else if (achou) {
				soma_ken = soma_ken + (2 * -vetor_luta[i]);
			} else {
				soma_ken = soma_ken + (-vetor_luta[i]);
			}
		}
	}
	if(rounds_ryu == rounds_ken) {
		printf("empatou\n");
	} else if(rounds_ryu > rounds_ken) {
		printf("Ryu venceu\n");
	} else {
		printf("Ken venceu\n");
	} 
	return 0;	
}
