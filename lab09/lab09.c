/*
Nome: Guilherme Dumas Peres
RA: 173711
Objetivos: Verificar se uma senha atende as condicoes demandadas pelo programa
Entrada: Um numero 'n' que representa o numero de entradas no dicionario seguido com as palavras e depois a senha
Saida: Todos os possiveis erros detectados pelo programa se a senha nao atende as condicoes ou 'ok' representando que o usuario atendeu as condicoes exigidas
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main (void) {
	char dicionario[50][21], senha[51];
	int i, n, cnt_palavra, flag, numero, maiuscula, minuscula, simbolo, j, conta_palindromo, nao_achar, cnt, var, conta_caractere, tam_string, controla_andamento;

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", dicionario[i]);
	}
	scanf("%s", senha);
/*Contar caracteres da senha*/
	cnt_palavra = 0;
	numero = 0;
	maiuscula = 0;
	minuscula = 0;
	simbolo = 0;
/*Nesse loop iremos descobrir se a senha tem letras maiusculas, minusculas, simbolo ou numeros*/
	for(i = 0; senha[i] != '\0'; i++) {
		flag = isalnum(senha[i]);
		if(senha[i] == '!' || senha[i] == '?' || senha[i] == '#' || senha[i] == '@' || senha[i] == '$') {
			simbolo++;
			cnt_palavra++;
		} else if(flag) {
			if(senha[i] >= 'a' && senha[i] <= 'z') {
				minuscula++;
			} else if(senha[i] >= 'A' && senha[i] <= 'Z') {
				maiuscula++;
			} else if(senha[i] >= '0' && senha[i] <= '9') {
				numero++;
			}
			cnt_palavra++;
		}
	}
/*Verificar se as primeiras 5 condicoes para a senha estao de acordo*/
	if(cnt_palavra < 8)
		printf("A senha deve conter pelo menos 8 caracteres\n");
	if(maiuscula == 0)
		printf("A senha deve conter pelo menos uma letra maiuscula\n");
	if(minuscula == 0)
		printf("A senha deve conter pelo menos uma letra minuscula\n");
	if(numero == 0)
		printf("A senha deve conter pelo menos um numero\n");
	if(simbolo == 0)
		printf("A senha deve conter pelo menos um simbolo\n");
/*Verificar se e palindromo*/
	conta_palindromo = 0;
	i = 0;
	j = cnt_palavra - 1;
	if(cnt_palavra % 2 == 0) {
		while(senha[i] == senha[j] && conta_palindromo < cnt_palavra / 2) {
			conta_palindromo++;
			i++;
			j--;
		}
		if(conta_palindromo == cnt_palavra / 2)
			printf("A senha e um palindromo\n");
	} else {
		while(senha[i] == senha[j] && conta_palindromo < (cnt_palavra - 1) / 2) {
			conta_palindromo++;
			i++;
			j--;
		}
		if(conta_palindromo == (cnt_palavra - 1) / 2)
			printf("A senha e um palindromo\n");
	}
/*Agora vamos conferir se a palavra esta no dicionario*/
	cnt = 0;
	nao_achar = 1;
	for(i = 0; nao_achar && cnt < n; i++) {
		tam_string = strlen(dicionario[i]);
		conta_caractere = 0;
		var = 0;
		controla_andamento = 0;
		for(j = 0; senha[j] != '\0' && dicionario[i][var] != '\0'; j++) {
			if((senha[j] >= '0' && senha[j] <= '9') && (dicionario[i][var] >= '0' && dicionario[i][var] <= '9')) { /*Entao quer dizer que eu vou comparar numeros*/
				if(senha[j] == dicionario[i][var]) {
					controla_andamento++; 
					conta_caractere++;
					var++;
				} else {
					controla_andamento = 0;
					var = 0;
					conta_caractere = 0;
				}
			} else if(isalpha(senha[j]) && isalpha(dicionario[i][var])) { /*Entao quer dizer que eu vou comparar letras*/
				if(senha[j] == tolower(dicionario[i][var]) || senha[j] == toupper(dicionario[i][var])) {
					controla_andamento++; 
					conta_caractere++;
					var++;
				} else {
					controla_andamento = 0;
					var = 0;
					conta_caractere = 0;
				}
			} else if((senha[j] == '!' || senha[j] == '?' || senha[j] == '#' || senha[j] == '@' || senha[j] == '$') && (dicionario[i][var] == '!' || dicionario[i][var] == '?' || dicionario[i][var] == '#' || dicionario[i][var] == '@' || dicionario[i][var] == '$')) { /*Entao quer dizer que eu vou comparar simbolos*/
				if(senha[j] == dicionario[i][var]) {
					conta_caractere++;
					var++;
					controla_andamento++;
				} else {
					controla_andamento = 0;
					var = 0;
					conta_caractere = 0;
				}
			}		
		}
		if(conta_caractere == tam_string && controla_andamento == tam_string) {
			printf("A senha nao pode conter palavras reservadas\n");
			nao_achar = 0;
		}
		cnt++;
	}
	if(maiuscula != 0 && minuscula != 0 && numero != 0 && simbolo != 0 && cnt_palavra >= 8 && (conta_palindromo != cnt_palavra / 2 ||conta_palindromo != (cnt_palavra - 1) / 2) && nao_achar) {
		printf("ok\n");
	}	
	return 0;
}
