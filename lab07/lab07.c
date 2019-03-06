/*
Nome: Guilherme Dumas Peres
RA: 173711
Entrada: A entrada é composta de números positivos e números negativos
Saída: Quem venceu a batalha
Objetivos: Fazer calculos através do programa para descobrir quem ganhou a luta
*/
#include<stdio.h>

int main(void) {
	int soma_ryu = 0, soma_ken = 0, num, i, j = 0, cnt = 0, vetor_luta[500], rounds_ryu = 0, rounds_ken = 0, vetor_triangular[100], soma_perf, achou;

/*Calcular 50 primeiros numeros triangulares*/
	for(i = 1; i <= 100; i++) {
		vetor_triangular[i] = i * (i + 1) / 2;
	}
/*Ler números e guardar no vetor até apertar '0'. Conforme for lendo vai aplicar as condições para o número se for triangular, perfeito ou nenhum dos dois*/
	do {
		scanf("%d", &num);
		if(num < 0) {
			achou = 0;
			for(i = 1; i <= 100; i++) {
				if(-num == vetor_triangular[i])	/*Esse if determina se o numero é triangular*/
					achou = 1;
			}
			soma_perf = 0;
			for(i = 1; i < -num; i++) { /*isso é para conferir se é perfeito*/
				if(-num % i == 0)
					soma_perf = soma_perf + i;
			}
			if(-num == soma_perf) {
				vetor_luta[j] = 3 * num;
			} else if(achou) {
				vetor_luta[j] = 2 * num;
			} else {
				vetor_luta[j] = num;
			}
		} else if(num > 0) {
			achou = 0;
			for(i = 1; i <= 100; i++) {
				if(num == vetor_triangular[i])
					achou = 1;
			}
			soma_perf = 0;
			for(i = 1; i < num; i++) {
				if(num % i == 0)
					soma_perf = soma_perf + i;
			}
			if(num == soma_perf) {
				vetor_luta[j] = 3 * num;
			} else if(achou) {
				vetor_luta[j] = 2 * num;
			} else {
				vetor_luta[j] = num;
			}
		} else {
			vetor_luta[j] = num;
		}
		j++;
		cnt++;
	} while(num != 0);
	if(vetor_luta[0] > 0) {
		soma_ryu = vetor_luta[0];
	} else {
		soma_ken = vetor_luta[0];
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
			soma_ryu = vetor_luta[i];
/*Fazer as condições para quando o Ken ganha ponto e quando o Ryu ganha ponto*/
		} else if(vetor_luta[i] > 0 && vetor_luta[i - 1] > 0) {
			soma_ryu = soma_ryu + vetor_luta[i];
		} else if((vetor_luta[i] < 0 && vetor_luta[i - 1] < 0) || (vetor_luta[i] < 0 && vetor_luta[i - 1] > 0)){
			soma_ken = soma_ken + (-vetor_luta[i]);
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
