/*
Entrada: Depende de cada funcao
Saida: Depende de cada funcao
Objetivos: Elaborar funcoes que realizam acoes bem definidas auxiliando o programa na main
Nome: Guilherme Dumas Peres
RA: 173711
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *numeros;
  int elementos;
  int capacidade;
} conjunto;

conjunto *novo(int capacidade) {
	conjunto *p;

	p = malloc(sizeof(conjunto));                     /*Alocar espaco para 'p' do tamanho do registro que e 'conjunto'*/
	(*p).capacidade = capacidade;
	(*p).elementos = 0;
	(*p).numeros = malloc(capacidade * sizeof(int)); /*Alocar espaco para o vetor numeros do conjunto p*/
	if((*p).numeros != NULL) {
		return p;                                /*Retornar todas as informacoes para o o conjunto da main atraves de um ponteiro*/
	} else {
		return NULL;
	}

}

void aumenta_capacidade(conjunto *conj, int capacidade) {
	int *p_aux, i;
	
	p_aux = malloc(capacidade * sizeof(int)); /*Alocar espaco para o vetor auxiliar e guardamos os valores do vetor original nele*/
	for(i = 0; i < (*conj).elementos; i++)
		p_aux[i] = (*conj).numeros[i];
	free((*conj).numeros); /*Liberamos a memoria do vetor original e fazemos outro malloc nele para o tamanho certo*/
	(*conj).numeros = malloc(capacidade * sizeof(int));
	for(i = 0; i < (*conj).elementos; i++) /*Copiamos agora do auxiliar para o original*/
		(*conj).numeros[i] = p_aux[i];
	free(p_aux); /*Liberamos a memoria no auxiliar e atualizamos a capacidade do original*/
	(*conj).capacidade = capacidade;
}

void deleta(conjunto *conj) {

	free((*conj).numeros);	/*Liberar memoria do vetor numeros*/

	free(conj); /*Liberar a memoria do conjunto numerico*/
}

int pertence(conjunto *conj, int num) {
	int i;

	for(i = 0; i < (*conj).elementos; i++) {
		if((*conj).numeros[i] == num)
			return 1;
	}
	return 0;
}

int contido(conjunto *conj1, conjunto *conj2) {
	int i, j, cnt = 0;
/*Primeiro, para que o conj1 esteja contido no conj2 o numero de elementos do conj2 deve ser maior ou igual ao de 1*/
	if((*conj2).elementos >= (*conj1).elementos) {
/*Agora acionamos um contador toda vez que encontrarmos um numero de conj1 que pertenca a conj2, se no final o tamanho do contador for igual ao tam1, entao o conj1 esta contido em conj2*/
		for(i = 0; i < (*conj2).elementos; i++) {
			for(j = 0; j < (*conj1).elementos; j++) {
				if((*conj2).numeros[i] == (*conj1).numeros[j])
					cnt++;
			}
		}
		if(cnt == (*conj1).elementos)
			return 1;
		else
			return 0;
	} else {
		return 0;
	}	
}

void adicao(conjunto *conj, int num) {

	if(pertence(conj, num)) { /*Verificar se num pertence a conj, se for o caso nao adicionamos nada*/
		
	} else {
		if((*conj).elementos + 1 > (*conj).capacidade) { /*Antes de adicionar o elemento precisamos ver se vai extrapolar o tamanho do vetor se isso ocorrer duplicamos sua capacidade e adicionamos depois*/
			aumenta_capacidade(conj, (*conj).capacidade*2);
			(*conj).numeros[(*conj).elementos] = num;
		} else {
		(*conj).numeros[(*conj).elementos] = num; /*Adicionamos o elemento na primeira posicao disponivel e atualizamos o numero de elementos no vetor*/
		}
		(*conj).elementos++;			
	}
}

void subtracao(conjunto *conj, int num) {
	int i, j;

	if(pertence(conj, num)) {				/*Verificar se num pertence a conj, se for o caso o removemos*/
		for(i = 0; i < (*conj).elementos; i++) {	/*Nesse for sobrescrevemos os valores e no final diminuimos o numero de elementos do vetor*/
			if((*conj).numeros[i] == num) {
				for(j = i; j < (*conj).elementos - 1; j++)
					(*conj).numeros[j] = (*conj).numeros[j + 1];
			}
		}
		(*conj).elementos--;
	}
}

conjunto *uniao(conjunto *conj1, conjunto *conj2) {
	int i, j = (*conj1).elementos, k;
	conjunto *conjRes;

	conjRes = novo((*conj1).elementos + (*conj2).elementos);
/*Copiar todos os elementos do conj1 para o conjRes*/
	for(i = 0; i < (*conj1).elementos; i++)
		(*conjRes).numeros[i] = (*conj1).numeros[i];
/*Agora copiamos os elementos do conj2 para o conjRes sem repetir*/
	for(k = 0; k < (*conj2).elementos; k++) {
		if(pertence(conj1, (*conj2).numeros[k])) {
				
		} else {
			(*conjRes).numeros[j] = (*conj2).numeros[k];
			j++;
		}
	}
	(*conjRes).elementos = j;
	return conjRes;	
}

conjunto *intersecao(conjunto *conj1, conjunto *conj2) {
	int i, j;
	conjunto *conjRes;

	conjRes = novo((*conj1).elementos + (*conj2).elementos);
	for(i = 0, j = 0; i < (*conj1).elementos; i++) {
		if(pertence(conj2, (*conj1).numeros[i])) {	/*Esse if garante que so os elementos que estao nos dois conjuntos serao copiados*/
			(*conjRes).numeros[j] = (*conj1).numeros[i];
			j++;
		}
	}
	(*conjRes).elementos = j;
	return conjRes;
}

conjunto *diferenca(conjunto *conj1, conjunto *conj2) {
	int i, j;
	conjunto *conjRes;

	conjRes = novo((*conj1).elementos + (*conj2).elementos);
	for(i = 0, j = 0; i < (*conj1).elementos; i++) {
		if(!pertence(conj2, (*conj1).numeros[i])) {	/*Esse if garante que so os elementos que estao no conj1 e nao estao no conj2 serao copiados para o conjRes*/
			(*conjRes).numeros[j] = (*conj1).numeros[i];
			j++;
		}
	}
	(*conjRes).elementos = j;
	return conjRes;
}
