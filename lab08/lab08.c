	/*
Nome: Guilherme Dumas Peres
RA: 173711
Entrada: A entrada é composta de um número 'n' que indica a quantidade de espécies, e n linhas com o identificador de cada espécie e seus pca's e pcf's. Além disso também há consulta sobre esses dados na qual o usuário insere o identificador da espécie e seu pc's, terminando a consulta quando digita o número '0'
Saída: Pcf's com base nos dados de entrada, ordenados de acordo com cada entrada na consulta da base de dados
Objetivos: Calcular os pcf's dos monstros
*/
#include<stdio.h>
#include<math.h>

int main(void) {
	int n, i, matriz_ev[151][3], j, cnt, k, nao_executa, num1, num2, var; 
	float matriz_mult[151][2], mult_medio[151][2], soma, vetor_restricao[151], pcf;	

	scanf("%d", &n);
	for(i = 0; i < n; i++) { /*Nesse laço guardamos as espécies e seus pca's e pcf's*/
		for(j = 0; j < 3; j++) {
			scanf("%d", &matriz_ev[i][j]);
		}
	}
/*Agora calcula-se o multiplicador*/
	for(i = 0; i < n; i++) {
		j = 1;
		matriz_mult[i][0] = (float) matriz_ev[i][0];
		matriz_mult[i][1] = (float) matriz_ev[i][j + 1] / (float) matriz_mev[i][j];
	}
	var = -1;
/*Agora calcula-se o multiplicador médio*/
	for(i = 0; i < n; i++) {
		soma = 0;
		cnt = 0;
		nao_executa = 1;
		for(j = 0; j < i; j++) {
			if(vetor_restricao[j] == matriz_mult[i][0]) {	/*Criamos uma restricao para nao calcular a media de um indicador mais de uma vez*/
				nao_executa = 0;
			}
		}
		if(nao_executa) {
			for(k = 0; k < n; k++) {
				if(matriz_mult[i][0] == matriz_mult[k][0]) {
					soma = soma + matriz_mult[k][1];
					cnt++;
				}
			}
			var++;
			mult_medio[var][0] = matriz_mult[i][0];
			mult_medio[var][1] = soma / cnt;
			vetor_restricao[var] = matriz_mult[i][0];
		}
	}
/*Nesta parte faz-se a consulta ao banco de dados*/
	num1 = 1;
	num2 = 1;
	while (num1 != 0 && num2 != 0) {
		scanf("%d", &num1);
		scanf("%d", &num2);
		for(i = 0; i <= var; i++) {
			if(num1 == (int)mult_medio[i][0]) {
				pcf = (float)num2 * mult_medio[i][1];
				printf("%d\n", (int)ceil(pcf));
			}
		}
	}
	return 0;
}
