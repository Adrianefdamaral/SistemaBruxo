#include "Bruxo.h"
#include <string.h>
#include <stdlib.h>

Bruxo* bruxos = NULL;
int MAX_BRUXOS = 5;
int qtdBruxos = 0;


int InicializarBruxos()
{
	bruxos=(Bruxo *) malloc(MAX_BRUXOS*sizeof(Bruxo));

	if(bruxos == NULL){
			return -1;
	}
	else
		return 5;	
}
int EncerraBruxos()
{
	free(bruxos);
	qtdBruxos = 0;
		
}

int SalvarBruxo(Bruxo b)
{
	if (qtdBruxos == MAX_BRUXOS){
		MAX_BRUXOS = MAX_BRUXOS * 2;
		Bruxo *M = (Bruxo*) realloc(bruxos, MAX_BRUXOS*sizeof(Bruxo));
		if(M==NULL){
			MAX_BRUXOS = MAX_BRUXOS / 2;
			return -1;
		}
		bruxos = M;
	}
	Bruxo *cod2 = ObterBruxoPeloCodigo(b.codigo);
	if(cod2){
		free(cod2);
		return -2;
	}
	bruxos[qtdBruxos] = b;
	qtdBruxos++;
	return qtdBruxos;
}

int QuantidadeBruxos()
{
	return qtdBruxos;	
}

Bruxo* ObterBruxoPeloIndice(int indice){
	if(indice >= qtdBruxos) return NULL;
	Bruxo *M = (Bruxo*)malloc(sizeof(Bruxo));
	M->codigo = bruxos[indice].codigo;
	strcpy(M->especialidade, bruxos[indice].especialidade);
	strcpy(M->nome, bruxos[indice].nome);
	return M;
}

Bruxo* ObterBruxoPeloCodigo(int codigo){
	int i;
	for(i=0; i<qtdBruxos; ++i){
		if(bruxos[i].codigo == codigo){
			Bruxo *M = (Bruxo*)malloc(sizeof(Bruxo));
			M->codigo = bruxos[i].codigo;
			strcpy(M->especialidade, bruxos[i].especialidade);
			strcpy(M->nome, bruxos[i].nome);
			return M;
		}
	}
	return NULL;
}	



int AtualizarBruxo(Bruxo b){
	int indM = -1; //armazenar o indice bruxo para atualizar array
	int i;
	for(i=0; i<qtdBruxos; i++){
		if(bruxos[i].codigo==b.codigo){
			indM=i;
			break;
		}	
		
	}
	if(indM==-1) return -1;
	strcpy(bruxos[indM].especialidade, b.especialidade);
	strcpy(bruxos[indM].nome, b.nome);
	return qtdBruxos;
}



int ApagarBruxoPeloCodigo(int codigo){
	int i;
	int indM = -1;
	for(i=0;  i<qtdBruxos; i++){
		if(bruxos[i].codigo == codigo){
			indM = i;
		}
			
	}
	if(indM == -1) return -1;
	if(VerificarTratamentoBruxo(codigo) ==-1) return -2;
	for(i=indM + 1; i<qtdBruxos; ++i){
		bruxos[i-1].codigo=bruxos[i].codigo;
		strcpy(bruxos[i-1].especialidade, bruxos[i].especialidade);
		strcpy(bruxos[i-1].nome, bruxos[i].nome);
	}
	qtdBruxos--;
	if(5*qtdBruxos < 2*MAX_BRUXOS){
		MAX_BRUXOS = MAX_BRUXOS / 2;
		Bruxo *M = (Bruxo*) realloc(bruxos, MAX_BRUXOS*sizeof(Bruxo));
		if(M==NULL){
			MAX_BRUXOS *=2;
			return -3;
		}
		bruxos = M;
	}
	return qtdBruxos;
}


int ApagarBruxoPeloNome(char* nome){
	int i;
	int indM = -1;
	for(i=0;  i<qtdBruxos; ++i){
		if(strcmp(bruxos[i].nome, nome) == 0){
			indM = i;
		}
			
	}
	if(indM == -1) return -1;
	if(verificaTratamentoBruxo(bruxos[indM].codigo) == -1) return -2;
	for(i=indM + 1; i<qtdBruxos; ++i){
		bruxos[i-1].codigo=bruxos[i].codigo;
		strcpy(bruxos[i-1].especialidade, bruxos[i].especialidade);
		strcpy(bruxos[i-1].nome, bruxos[i].nome);
	}
	qtdBruxos--;
	if(5*qtdBruxos < 2*MAX_BRUXOS){
		MAX_BRUXOS = MAX_BRUXOS / 2;
		Bruxo *M = (Bruxo*) realloc(bruxos, MAX_BRUXOS*sizeof(Bruxo));
		if(M==NULL){
			MAX_BRUXOS *=2;
			return -3;
		}
		bruxos = M;
	}
	return qtdBruxos;
}


