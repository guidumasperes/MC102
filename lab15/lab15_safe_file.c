/* Laboratorio 15 - Banco de Dados Geografico
 * Nome: Guilherme Dumas Peres
 * RA: 173711
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
    Ponto coordenadas;
    int inicioCEP;
    int fimCEP;
    int numHabitantes;
} Cidade;

float distancia(Ponto a, Ponto b) {
	printf("a.x = %f, a.y = %f, b.x = %f, b.y = %f\n", a.x, a.y, b.x, b.y);
	return trunc(100 * sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))) / 100.0; 
}

int consulta_cidade_por_cep(Cidade* cidades, int cep, int n) {
	int i;

	for(i = 0; i < n; i++) { /*Façamos um loop para percorrer o vetor*/
		if(cep > cidades[i].inicioCEP && cep < cidades[i].fimCEP) /*e em cada indice verifica-se no registro se o cep desejado esta entre os cep's daquele determinado indice se estiver retornamos o indice ao final se nao encontrar nada retorna -1*/
			return i;
	}
	return -1;
}

int* consulta_cidades_por_raio(Cidade* cidades, int cidadeReferencia, float raio, int n, int* nRetorno) {
	int *vetor_resposta;
	int tam_vet_resp, i , j, aux;

	*nRetorno = 0;
	tam_vet_resp = 5;
	vetor_resposta = malloc(5 * sizeof(int)); /*Alocamos dinamicamente o vetor resposta*/
	for(i = 0; i < n; i++) {
		if(distancia(cidades[i].coordenadas, cidades[cidadeReferencia].coordenadas) <= raio) { /*Percorremos o vetor de struct cidades e em cada indice calculamos a distancia entre as cidades, se esse if ocorre entao a cidade esta dentro do raio de procura*/
			if(tam_vet_resp <= *nRetorno) { /*Mas antes de colocarmos o indice no vetor verificamos se ha espaco*/
				tam_vet_resp += 5;
				vetor_resposta = realloc(vetor_resposta, tam_vet_resp * sizeof(int));
			}
			vetor_resposta[*nRetorno] = i;
			*nRetorno = *nRetorno + 1;
		}
	}
	for(i = *nRetorno - 1; i > 0; i--) { /*Implementamos um algoritmo de ordenacao para ordenar o vetor_resposta*/
    		for(j = 0; j < i; j++) {
      			if (vetor_resposta[j] > vetor_resposta[j + 1]) {
        			aux = vetor_resposta[j];
        			vetor_resposta[j] = vetor_resposta[j + 1];
        			vetor_resposta[j + 1] = aux;
      			}
    		}
  	}
	return vetor_resposta; /*No final retornamos o ponteiro para a main*/
}

int populacao_total(Cidade* cidades, int cidadeReferencia, float raio, int n) {
	int i, soma = 0;
	double distancia_cidades;

	for(i = 0; i < n; i++) {
		printf("distancia entre cidades: %f, cidadeReferencia: %d, raio: %f, i: %d, soma: %d\n", distancia(cidades[i].coordenadas, cidades[cidadeReferencia].coordenadas), cidadeReferencia, raio, i, soma);
		distancia_cidades = distancia(cidades[i].coordenadas, cidades[cidadeReferencia].coordenadas);
		if(distancia_cidades <= raio && i != cidadeReferencia) { /*Se esse if ocorre entao a cidade esta dentro do raio de procura*/
			soma = soma + cidades[i].numHabitantes; /*Somamos o numero de habitantes*/
		}
	}
	return soma; /*No final retornamos a soma para a main*/
}

float mediana_da_populacao(Cidade* cidades, int cidadeReferencia, float raio, int n) {
	int *vetor_resposta;
	int tam_vet_resp, i, j, aux;
	float mediana;

	vetor_resposta = consulta_cidades_por_raio(cidades, cidadeReferencia, raio, n, &tam_vet_resp);
	for(i = tam_vet_resp - 1; i > 0; i--) { /*Implementamos um algoritmo de ordenacao para ordenar o vetor_resposta*/
    		for(j = 0; j < i; j++) {
      			if (cidades[vetor_resposta[j]].numHabitantes > cidades[vetor_resposta[j + 1]].numHabitantes) {
        			aux = cidades[vetor_resposta[j]].numHabitantes;
        			cidades[vetor_resposta[j]].numHabitantes = cidades[vetor_resposta[j + 1]].numHabitantes;
        			cidades[vetor_resposta[j + 1]].numHabitantes = aux;
      			}
    		}
  	}
	if(tam_vet_resp % 2 == 0) {
		mediana = cidades[(tam_vet_resp / 2)].numHabitantes - cidades[(tam_vet_resp / 2) - 1].numHabitantes;
	} else {
		mediana = cidades[(tam_vet_resp / 2) - 1].numHabitantes; 
	}
	return mediana;
}
