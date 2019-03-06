/*
nao esquecer de liberar a memoria, verificar comentarios e codigo e dar fclose()
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int **m_red;
	int **m_green;
	int **m_blue;
	
}imagem;

int **aloca_matriz(int lin, int col);
int **desaloca_matriz(int lin, int col, int **p);
float achar_cor_max(int **m, int lin, int col);
float achar_cor_min(int **m, int lin, int col);
void define_imagem(imagem *imagem_a_def, int i, int j);
void ler_matriz(imagem *imagem_a_ler, FILE *arq);

int main(int argc, char **argv) {  
	char str = 'P', c;	
	char efeito[20];
	char *arqEntrada = argv[1];
	char *arqSaida = argv[2];
	int i, j, lin, col;
	int num1 = 3, num2 = 255;
	float r_min, r_max, g_min, g_max, b_min, b_max;
	FILE *arq_in, *arq_out;
	imagem imagem_atual, imagem_nova;
    
    	if (argc != 3) {
        fprintf(stderr, "Argumentos invalidos. Use:\n");
        fprintf(stderr, "./lab16 <arqEntrada> <arqSaida>\n");
        fprintf(stderr, "Usado:");
        for (i=0; i<argc; i++) {
            fprintf(stderr, " %s", argv[i]);
        }
        fprintf(stderr, "\n");
        return 1;
	}
	arq_in = fopen(arqEntrada, "r");
	fseek(arq_in, 3, SEEK_CUR); /*Movemos para ler o numero de linhas e colunas*/
	while(fscanf(arq_in,"%d %d\n", &col, &lin) != 2); /*Lemos o tamanho da matriz*/
	printf("lin = %d, col = %d\n", lin, col);
	define_imagem(&imagem_atual, lin, col); /*Chamamos a funcao para definir parametros para matriz atual*/
	define_imagem(&imagem_nova, lin, col); /*Chamamos a funcao para definir parametros para matriz nova que representara a nova imagem*/
	fseek(arq_in, 4, SEEK_CUR); /*Movemos para comecar a ler todos os pixels*/
	ler_matriz(&imagem_atual, arq_in);
	printf("ler efeito\n");
	scanf("%s", efeito);
	printf("passou ler efeito\n");
	if(strcmp(efeito, "cinza") == 0) { /*Se isso ocorre entao vamos aplicar o efeito cinza do contrario esticaremos o contraste*/
		printf("entrou no efeito cinza\n");
		for(i = 0; i < lin; i++) {
			for(j = 0; j < col; j++) {
				imagem_nova.m_red[i][j] = (int)floor(((float)imagem_atual.m_red[i][j] + (float)imagem_atual.m_green[i][j] + (float)imagem_atual.m_blue[i][j]) / 3.0);
				printf("imagem_nova.m_red[%d][%d] = %d\n", i, j, imagem_nova.m_red[i][j]);
				imagem_nova.m_green[i][j] = imagem_nova.m_red[i][j];
				printf("imagem_nova.m_green[%d][%d] = %d\n", i, j, imagem_nova.m_green[i][j]);
				imagem_nova.m_blue[i][j] = imagem_nova.m_red[i][j];
				printf("imagem_nova.m_blue[%d][%d] = %d\n", i, j, imagem_nova.m_blue[i][j]);
			}
		}
	} else {
		printf("entrou no efeito esticar matriz\n");
		r_min = achar_cor_min(imagem_atual.m_red, lin, col); /*Achamos as cores minimas e maximas para cada componemte RGB*/
		r_max = achar_cor_max(imagem_atual.m_red, lin, col);
		g_min = achar_cor_min(imagem_atual.m_green, lin, col);
		g_max = achar_cor_max(imagem_atual.m_green, lin, col);
		b_min = achar_cor_min(imagem_nova.m_blue, lin, col);
		b_max = achar_cor_max(imagem_nova.m_blue, lin, col);
		printf("r_min = %f, r_max = %f, g_min = %f, g_max = %f, b_min = %f, b_max = %f\n", r_min, r_max, g_min, g_max, b_min, b_max);
		for(i = 0; i < lin; i++) {
			for(j = 0; j < col; j++) {
				imagem_nova.m_red[i][j] = (int)floor((((float)imagem_atual.m_red[i][j] - r_min) * 255.0) / (r_max - r_min));
				printf(" %d ", imagem_nova.m_red[i][j]);
				imagem_nova.m_green[i][j] = (int)floor((((float)imagem_atual.m_green[i][j] - g_min) * 255.0) / (g_max - g_min));
				imagem_nova.m_blue[i][j] = (int)floor((((float)imagem_atual.m_blue[i][j] - b_min) * 255.0) / (b_max - b_min));
				break;
			}
		}
	}
	fclose(arq_in);
	printf("abrir saida\n");
	arq_out = fopen(arqSaida, "w+");
	printf("colocar string\n");
	fprintf(arq_out, "%c%d\n", str, num1); /*Vamos formatar as primeiras 3 linhas*/
	printf("colocar lin, col\n");
	fprintf(arq_out, "%d %d\n", col, lin);
	printf("colocar num2\n");
	fprintf(arq_out, "%d\n", num2);
	i = 0;
	j = 0;
	do {
		printf("col = %d\n", col);
		if(j == col-1) {
			c = '\n';
			fprintf(arq_out, "%d %d %d%c", imagem_nova.m_red[i][j], imagem_nova.m_green[i][j], imagem_nova.m_blue[i][j], c);
			i++;
			j = -1;
		} else {
			c = ' ';
			fprintf(arq_out, "%d %d %d%c", imagem_nova.m_red[i][j], imagem_nova.m_green[i][j], imagem_nova.m_blue[i][j], c);
		}
		j++;
		printf("i = %d, j = %d\n", i, j);
		break;
	}while(i < lin);
	return 0;
}

int **aloca_matriz(int lin, int col) {
	int i;
	int **p;
	printf("Entrou no aloca_matriz\n");
	p = malloc(lin*sizeof(long int));
	for(i = 0; i < lin; i++)
		p[i] = malloc(col*sizeof(long int));
	printf("i = %d\n", i);
	return p;
}

int **desaloca_matriz(int lin, int col, int **p) {
	int i;

	for(i = 0; i < lin; i++)
		free(p[i]);
	free(p);
	return NULL;
}

void define_imagem(imagem *imagem_a_def, int i, int j) {
	printf("Entrou no define_imagem\n");
	printf("i = %d, j = %d\n", i, j);
	(*imagem_a_def).m_red = aloca_matriz(i, j); /*Alocamos uma matriz para red, green e blue*/
	(*imagem_a_def).m_green = aloca_matriz(i, j);
	(*imagem_a_def).m_blue = aloca_matriz(i, j);
}

void ler_matriz(imagem *imagem_a_ler, FILE *arq) {
	int i = 0, j = 0, r, g, b;
	char c;	

	while(fscanf(arq,"%d %d %d%c", &r, &g, &b, &c) != EOF) {
		printf("r = %d, g = %d, b = %d\n", r, g, b);
		(*imagem_a_ler).m_red[i][j] = r;
		printf("(*imagem_a_ler).m_red[%d][%d] = %d\n", i, j, (*imagem_a_ler).m_red[i][j]);
		(*imagem_a_ler).m_green[i][j] = g;
		printf("(*imagem_a_ler).m_green[%d][%d] = %d\n", i, j, (*imagem_a_ler).m_green[i][j]);
		(*imagem_a_ler).m_blue[i][j] = b;
		printf("(*imagem_a_ler).m_blue[%d][%d] = %d\n", i, j, (*imagem_a_ler).m_blue[i][j]);
		j++;
		if(c == '\n') {
			i++;
			j = 0;
		}
	}
	printf("i = %d, j = %d\n", i, j);
}

float achar_cor_max(int **m, int lin, int col) {
	int i, j;
	float max;

	printf("lin = %d, col = %d\n", lin, col);
	max = m[0][0];
	for(i = 0; i < lin; i++) {
		for(j = 0; j < col; j++) {
			if(m[i][j] > max)
				max = m[i][j];
		}
	}
	printf("saiu do achar_cor_max\n");
	return max;	
}

float achar_cor_min(int **m, int lin, int col) {
	int i, j;
	float min;

	printf("lin = %d, col = %d\n", lin, col);
	min = m[0][0];
	for(i = 0; i < lin; i++) {
		for(j = 0; j < col; j++) {
			if(m[i][j] < min)
				min = m[i][j];
		}
	}
	printf("saiu do achar_cor_min\n");
	return min;
}
