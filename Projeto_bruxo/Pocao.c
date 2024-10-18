#include "Pocao.h"
#include <string.h>
#include <stdlib.h>

Pocao* pocoes = NULL;
int MAX_POCAO = 5;
int qtdPocoes = 0;



int InicializarPocoes()
{
	
	pocoes=(Pocao *) malloc(MAX_POCAO*sizeof(Pocao));

	if(pocoes == NULL){
			return -1;
	}
	else
		return 5;
}

int EncerraPocoes(int MAX_POCAO){ 
	free(pocoes);
	qtdPocoes = 0;
}

int SalvarPocao(Pocao b){
	if(qtdPocoes == MAX_POCAO){
		MAX_POCAO = MAX_POCAO * 2;
		Pocao *M=(Pocao*) realloc(pocoes, MAX_POCAO*sizeof(Pocao));
		if(M == NULL){
			MAX_POCAO = MAX_POCAO / 2;
			return -1;
		}
		pocoes = M;
	}
	Pocao *cod2 = ObterPocaoPeloCodigo(b.codigo);
	if(cod2){
		free(cod2);
		return -2;
	}
	pocoes[qtdPocoes] = b;
	qtdPocoes++;
	return qtdPocoes;
}

int QuantidadePocoes(){
	return qtdPocoes;
 }

Pocao* ObterPocaoPeloIndice(int indice){
	if(indice >= qtdPocoes) return NULL;
	Pocao *M = (Pocao*)malloc(sizeof(Pocao));
	M->codigo = pocoes[indice].codigo;
	strcpy(M->tipo, pocoes[indice].tipo);
	strcpy(M->nome, pocoes[indice].nome);
	return M;
}

Pocao* ObterPocaoPeloCodigo(int codigo){
	int i;
	for(i=0; i<qtdPocoes; ++i){
		if(pocoes[i].codigo == codigo){
			Pocao *M = (Pocao*)malloc(sizeof(Pocao));
			M->codigo = pocoes[i].codigo;
			strcpy(M->tipo, pocoes[i].tipo);
			strcpy(M->nome, pocoes[i].nome);
			return M;
		}
	}
	return NULL;
}

int AtualizarPocao(Pocao p){
	int indM =-1;
	int i;
	for(i=0; i<qtdPocoes; i++){
		if(pocoes[i].codigo==p.codigo){
			indM=i;
			break;
		}
	}
	if (indM==1) return -1;
	strcpy(pocoes[indM].tipo, p.tipo);
	strcpy(pocoes[indM].nome, p.nome);
	return qtdPocoes;
}


int ApagarPocaoPeloCodigo(int codigo){
	int i;
	int indM = -1;
	for(i=0; i<qtdPocoes; ++i){
		if(pocoes[i].codigo==codigo){
			indM=i;
		}
	}
	if(indM==-1) return -1;
	//if(verificarTratamentoPocao(codigo) ==-1) return -2;
	for(i=indM + 1; i<qtdPocoes; ++i){
		pocoes[i-1].codigo=pocoes[i].codigo;
		strcpy(pocoes[i-1].tipo, pocoes[i].tipo);
		strcpy(pocoes[i-1].nome, pocoes[i].nome);
	}
	qtdPocoes--;
	if(5*qtdPocoes<2*MAX_POCAO){
		MAX_POCAO = MAX_POCAO / 2;
		Pocao *M= (Pocao*) realloc(pocoes, MAX_POCAO*sizeof(Pocao));
		if(M==NULL){
			MAX_POCAO = MAX_POCAO * 2;
			return -3;
		}
		pocoes=M;
	}
	return qtdPocoes;
}


int ApagarPocaoPeloNome(char* nome){
	int i;
	int indM = -1;
	for(i=0; i<qtdPocoes; ++i){ //++i é um pré_incremento. i é incremento primeiro e, em seguida, o valor atualizado de i é usado.
		if(strcmp(pocoes[i].nome, nome) == 0){ //strcmp compara duas strings
		indM = i;
		}
	}
	if(indM == -1) return -1;
	if(verificaTratamentoPocao(pocoes[indM].codigo) == -1) return -2;
	for(i=indM + 1; i<qtdPocoes; ++i){
		pocoes[i-1].codigo=pocoes[i].codigo;
		strcpy(pocoes[i-1].tipo, pocoes[i].tipo);
		strcpy(pocoes[i-1].nome, pocoes[i].nome);
	}
	qtdPocoes--;
	if(5*qtdPocoes < 2*MAX_POCAO){
		MAX_POCAO = MAX_POCAO / 2;
		Pocao *M= (Pocao*) realloc(pocoes, MAX_POCAO*sizeof(Pocao));
		if(M == NULL){
			MAX_POCAO = MAX_POCAO * 2;
			return -3;
		}
		pocoes=M;
	}
	return qtdPocoes;

}

