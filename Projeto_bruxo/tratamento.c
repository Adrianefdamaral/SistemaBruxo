#include "Tratamento.h"
#include "Bruxo.h"
#include "Paciente.h"
#include "Pocao.h"
#include <stdlib.h>
#include <stdio.h>

Tratamento* Tratamentos = NULL;
int MAX_TRATAMENTO = 5;
int qtdTratamentos = 0;


int VerificarCodigos(Tratamento t){
	Bruxo* b = ObterBruxoPeloCodigo(t.codigo);
	Paciente* pa = ObterPacientePeloCodigo(t.codigo);
	Pocao* po = ObterPocaoPeloCodigo(t.codigo);
	
	free(b);
	free(pa);
	free(po);

	if(b==NULL) return -2;
	if(pa==NULL) return -3;
	if(po ==NULL) return -4;
	
	return 5;
}

int InicializarTratamentos()
{
	
	Tratamentos=(Tratamento *) malloc(MAX_TRATAMENTO*sizeof(Tratamento));

	if(Tratamentos == NULL){
			return -1;
	}
		
	else
		return 5;	
	
}
int EncerraTratamentos(int MAX_TRATAMENTO)
{
	free(Tratamentos);
	qtdTratamentos = 0;
		
}

int InicializarTratamento(Tratamento t){
	fflush(stdout);
	if(qtdTratamentos == MAX_TRATAMENTO){
		MAX_TRATAMENTO = MAX_TRATAMENTO * 2;
		Tratamento *M = (Tratamento*) realloc(Tratamentos, MAX_TRATAMENTO*sizeof(Tratamento));
		if(M==NULL){
			MAX_TRATAMENTO = MAX_TRATAMENTO / 2;
			return -1;
		}
		Tratamentos=M;
	}
	Tratamento *cod2 = ObterTratamentoPeloCodigo(t.codigo);
	if(cod2){
		free(cod2);
		return -5;
	}
	int VerificarCodigos=VerificarCodigos(t);
	if(VerificarCodigos == 5){
		Tratamentos[qtdTratamentos] = t;
		qtdTratamentos++;
	}
	return VerificarCodigos;
}

int QuantidadeTratamentos()
{
    return qtdTratamentos;	
}

Tratamento* ObterTratamentoPeloIndice(int indice){
	if(indice >= qtdTratamentos) return NULL;
	Tratamento *M = (Tratamento*) malloc(sizeof(Tratamento));
	M->codigo = Tratamentos[indice].codigo;
	M->codigo = Tratamentos[indice].codigo;
	M->codigo = Tratamentos[indice].codigo;
	M->codigo = Tratamentos[indice].codigo;
	M->codigo = Tratamentos[indice].codigo;
	return M;
}

Tratamento* ObterTratamentoPeloCodigo(int codigo){
	int i;
	for(i=0; i<qtdTratamentos; ++i){
		if(Tratamentos[i].codigo==codigo){
			Tratamento *M = (Tratamento*) malloc(sizeof(Tratamento));
			M->codigo = Tratamentos[i].codigo;
			M->codigo = Tratamentos[i].codigo;
			M->codigo = Tratamentos[i].codigo;
			M->codigo = Tratamentos[i].codigo;
			return M;
		}
	}
	return NULL;
}

int AmpliarTratamento(Tratamento t){
	int indM = -1;
	int i;
	for(i=0; i<qtdTratamentos; ++i){
		if(t.codigo == Tratamentos[i].codigo){
			indM=i;
			break;
		}
	}
	if(indM==-1)
	return -1;
	Tratamentos[indM].codigo += t.codigo;
	return qtdTratamentos;
}


int ApagarTratamentoPeloCodigo(int codigo){
	int i;
	int indM = -1;
	for(i=0; i<qtdTratamentos; ++i){
		if(Tratamentos[i].codigo==codigo){
			indM = i;
		}
	}
	if(indM == -1) return -1;
	for(i=indM + 1; i <qtdTratamentos; ++i){
		Tratamentos[i-1].codigo=Tratamentos[i].codigo;
		strcpy(Tratamentos[i-1].especialidade, Tratamentos[i].especialidade);
		strcpy(Tratamentos[i-1].nome, Tratamentos[i].nome);
	}
	qtdTratamentos--;
	if(5*qtdTratamentos < 2*MAX_TRATAMENTO){
		MAX_TRATAMENTO = MAX_TRATAMENTO / 2;
		Tratamento* M = (Tratamentos*) realloc(Tratamentos, MAX_TRATAMENTO*sizeof(Tratamento));
		if(M==NULL){
			MAX_TRATAMENTO = MAX_TRATAMENTO * 2;
			return -2;
		}
		Tratamentos=M;
	}
	return qtdTratamentos;
}




int verificarTratamentoBruxo(int codigo){
	int i;
	for(i=0; i<QuantidadeTratamentos(); i++){
		Tratamento* t_M = ObterTratamentoPeloIndice(i);
		int cod_M = cod_M->codigo;
		free(t_M->bruxo_codi);
		if(cod_M == codigo)return-1;
	}
	return 5;
}



int verificarTratamentoPocao(int codigo){
	int i;
	for(i=0; i<QuantidadeTratamentos(); i++){
		Tratamentos* t_M = ObterTratamentoPeloIndice(i)
		int cod_M = cod_M->codigo;
		free(t_M->pocao_codi);
		if(cod_M == codigo)return-1;
	}
}

int verificarTratamentoPaciente(int codigo){
	int i;
	for(i=0; i<QuantidadeTratamentos(); i++){
		Tratamentos* t_M = ObterTratamentoPeloIndice(i)
		int cod_M = cod_M->codigo;
		free(t_M->paciente_codi);
		if(cod_M == codigo) return -1;
	}
}
