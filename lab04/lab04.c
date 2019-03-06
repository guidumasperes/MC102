/*
Nome: Guilherme Dumas Peres
RA: 173711
Entrada: 9 caracteres
Saída: Quem venceu o jogo ou se foi empate
Objetivo: Descobrir a situação de um jogo da velha
*/

#include<stdio.h>

int main (void) {
	char v1, v2, v3, v4, v5, v6, v7, v8, v9;
	
	scanf("%c %c %c %c %c %c %c %c %c", &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8, &v9);
	if(v1 == 'X' && v2 == 'X' && v3 == 'X') {
		printf("X venceu\n");
	}  else if(v4 == 'X' && v5 == 'X' && v6 == 'X') {
		printf("X venceu\n");
	} else if(v7 == 'X' && v8 == 'X' && v9 == 'X') {
		printf("X venceu\n");
	} else if(v1 == 'X' && v4 == 'X' && v7 == 'X') {
		printf("X venceu\n");
	} else if(v2 == 'X' && v5 == 'X' && v8 == 'X') {
		printf("X venceu\n");
	} else if(v3 == 'X' && v6 == 'X' && v9 == 'X') {
		printf("X venceu\n");
	} else if(v1 == 'X' && v5 == 'X' && v9 == 'X') {
		printf("X venceu\n");
	} else if(v3 == 'X' && v5 == 'X' && v7 == 'X') {
		printf("X venceu\n");
	} else if(v1 == 'O' && v2 == 'O' && v3 == 'O') {
		printf("O venceu\n");
	} else if(v4 == 'O' && v5 == 'O' && v6 == 'O') {
		printf("O venceu\n");
	} else if(v7 == 'O' && v8 == 'O' && v9 == 'O') {
		printf("O venceu\n");
	} else if(v1 == 'O' && v4 == 'O' && v7 == 'O') {
		printf("O venceu\n");
	} else if(v2 == 'O' && v5 == 'O' && v8 == 'O') {
		printf("O venceu\n");
	} else if(v3 == 'O' && v6 == 'O' && v9 == 'O') {
		printf("O venceu\n");
	} else if(v1 == 'O' && v5 == 'O' && v9 == 'O') {
		printf("O venceu\n");
	} else if(v3 == 'O' && v5 == 'O' && v7 == 'O') {
		printf("O venceu\n");
	} else {
		printf("empatou\n");
	}
	return 0;
}
