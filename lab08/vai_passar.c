#include<stdio.h>

int main(void) {
	int num1, num2, cnt, i, j, matriz_faz[151][2];

	num1 = 1;
	num2 = 1;
	cnt = -1;
	for(i = 0; (num1 != 0) && (num2 != 0); i++) {
		for(j = 0; j < 2; j++) {
			scanf("%d", &matriz_faz[i][j]);
		}
		num1 = matriz_faz[i][j-2];
		num2 = matriz_faz[i][j]; 
		cnt++;
	}
	printf("cnt = %d\n", cnt);
	for(i = 0; i < cnt; i++)
		for(j = 0; j < 2; j++)
			printf("matriz_faz[%d][%d] = %d\n",i, j, matriz_faz[i][j]);

	return 0;
}
