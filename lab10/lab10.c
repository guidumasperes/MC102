/*
Nome: Guilherme Dumas Peres
RA: 173711
Objetivos: Verificar o estado do planeta passados dias 'n' apos um apocalipse zumbi
Entrada: Dois numeros 'm' e  'n' que representam as dimensoes da matriz, o numero de dias, e a matriz a ser analisada pelo programa
Saida: Cada iteracao representa os dias passados e deve-se imprimir a iteracao e a matriz com base no dia anterior
*/
#include<stdio.h>

int main (void) {
	int m , n, num_dias, i, matriz_zumbi[50][50], j, k, matriz_buffer[50][50], lin, col, cnt1, cnt2, cnt3, cnt4, cnt_humanos, cnt_zumbi;

	scanf("%d %d", &m, &n);
	scanf("%d", &num_dias);
/*Inicializando toda matriz com 0*/
	for(i = 0; i <= m + 1; i++)
		for(j = 0; j <= n + 1; j++)
			matriz_zumbi[i][j] = 0;			
	for(i = 1; i <= m ; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &matriz_zumbi[i][j]);
	for(k = 0; k <= num_dias; k++) {
		printf("iteracao %d\n", k);
		for(cnt3 = 1; cnt3 <= m ; cnt3++) {
			for(cnt4 = 1; cnt4 <= n; cnt4++) {
				printf("%d", matriz_zumbi[cnt3][cnt4]);
			}
			printf("\n");
		}
		for(i = 1; i <= m ; i++) {
			for(j = 1; j <= n; j++) {
/*Agora vamos verificar a cada posicao (i, j) a vizinhanca, aplicar as condicoes e coloca-las num vetor de espera
  Nesse loop verificamos quantos humanos e zumbis existem na vizinhanca*/
				cnt_humanos = 0;
				cnt_zumbi = 0;
				for(lin = i - 1, cnt1 = 1; cnt1 <= 3; cnt1++, lin++) {
					for(col = j - 1, cnt2 = 1; cnt2 <= 3; cnt2++, col++) {
						if(lin == i && col == j) {

						} else if(matriz_zumbi[lin][col] == 1) {
							cnt_humanos++;
						} else if(matriz_zumbi[lin][col] == 2) {
							cnt_zumbi++;
						}
					}
				}
				if(matriz_zumbi[i][j] == 1) {
					if(cnt_zumbi >= 1)
						matriz_buffer[i][j] = 2;
					else
						matriz_buffer[i][j] = matriz_zumbi[i][j];				
				} else if(matriz_zumbi[i][j] == 2) {
					if(cnt_humanos >= 2 || cnt_humanos == 0)
						matriz_buffer[i][j] = 0;
					else
						matriz_buffer[i][j] = matriz_zumbi[i][j];
				} else if(matriz_zumbi[i][j] == 0) {
					if(cnt_humanos == 2)
						matriz_buffer[i][j] = 1;
					else if(cnt_humanos != 2)
						matriz_buffer[i][j] = matriz_zumbi[i][j];
				} 
			}	
		}
/*Agora sobrescrevemos a matriz*/
		for(cnt3 = 1; cnt3 <= m; cnt3++)
			for(cnt4 = 1; cnt4 <= n; cnt4++)
				matriz_zumbi[cnt3][cnt4] = matriz_buffer[cnt3][cnt4];
	}
	return 0;
}
