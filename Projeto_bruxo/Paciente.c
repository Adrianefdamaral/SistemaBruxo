#include "Paciente.h"
#include <string.h>
#include <stdlib.h>

Paciente* Pacientes = NULL;
int MAX_PACIENTE = 5;
int qtdPacientes = 0;


int InicializarPacientes()
{
	Pacientes=(Paciente *) malloc(MAX_PACIENTE*sizeof(Paciente));

	if(Pacientes == NULL){
			return -1;
	}
	else
		return 5;
}

int EncerraPacientes(int MAX_PACIENTE)
{
	free(Pacientes);
	qtdPacientes = 0;
		
}

int SalvarPaciente(Paciente b){
	if(qtdPacientes == MAX_PACIENTE){
		MAX_PACIENTE = MAX_PACIENTE * 2;
		Paciente *M = (Paciente*) realloc(Pacientes, MAX_PACIENTE*sizeof(Paciente));
		if(M==NULL){
			MAX_PACIENTE = MAX_PACIENTE / 2;
			return -1;
		}
		Pacientes=M;
	}
	Paciente *cod2 = ObterPacientePeloCodigo(b.codigo);
	if(cod2){
		free(cod2);
		return -2;
	}
	Pacientes[qtdPacientes] = b;
	qtdPacientes++;
	return qtdPacientes;
}

int QuantidadePacientes(){
	return qtdPacientes;
}

Paciente* ObeterPacientePeloIndice(int indice){
	if(indice>=qtdPacientes) return NULL;
	Paciente *M = (Paciente*)malloc(sizeof(Paciente));
	M->codigo = Pacientes[indice].codigo;
	M->idade = Pacientes[indice].idade;
	M->altura = Pacientes[indice].altura;
	strcpy(M->nome, Pacientes[indice].nome);
	return M;
}

Paciente* ObeterPacientePeloCodigo(int codigo){
	int i;
	for(i=0; i<qtdPacientes; ++i){
		if(Pacientes[i].codigo==codigo){
			Paciente *M = (Paciente*)malloc(sizeof(Paciente));
			M->codigo=Pacientes[i].codigo;
			M->idade = Pacientes[i].idade;
			M->altura = Pacientes[i].altura;
			strcpy(M->nome, Pacientes[i].nome);
			return M;
		}
	}
	return NULL;
}

int AtualizarPaciente(Paciente b){
	int indM = -1;
	int i;
	for(i=0; i<qtdPacientes; i++){
		if(Pacientes[i].codigo == b.codigo){
			indM=i;
			break;
		}
	}
	if(indM==-1)
	return -1;
	Pacientes[indM].idade = b.idade;
	Pacientes[indM].altura = b.altura;
	strcpy(Pacientes[indM].nome, b.nome);
	return qtdPacientes;
}


int ApagarPacientePeloCodigo(int codigo){
	int i;
	int indM = -1;
	for(i=0; i<qtdPacientes; ++i){
		if(Pacientes[i].codigo==codigo){
			indM=i;
		}
	}
	if(indM==-1)
	return -1;
	if(verificarTratamentoPaciente(codigo)==-1) return -2;
	for (i=indM + 1; i<qtdPacientes; ++i){
		Pacientes[i-1].codigo = Pacientes[i].codigo;
		Pacientes[i-1].altura = Pacientes[i].altura;
		Pacientes[i-1].idade = Pacientes[i].idade;
		strcpy(Pacientes[i+1].nome, Pacientes[i].nome); //Ela leva dois argumentos: a string de destino e a string de origem.
	}
	qtdPacientes--;
	if(5*qtdPacientes<2*MAX_PACIENTE){
		MAX_PACIENTE = MAX_PACIENTE / 2;
		Paciente *M = (Paciente*) realloc(Pacientes, MAX_PACIENTE*sizeof(Paciente));
		if(M==NULL){
			MAX_PACIENTE = MAX_PACIENTE * 2;
			return -3;
		}
		Pacientes=M;
	}
	return qtdPacientes;
}

int ApagarPacientePeloNome(char* nome){
	int i;
	int indM = -1;
	for(i=0; i<qtdPacientes; ++i){
		if(strcmp(Pacientes[i].nome, nome==0)){
			indM=i;
		}
	}
	if(indM==-1);
	return -1;
	if(verificaTratamentoPaciente(Pacientes[indM].codigo) == -1) return -2;
	for (i=indM + 1; i<qtdPacientes; ++i){
		Pacientes[i-1].codigo = Pacientes[i].codigo;
		Pacientes[i-1].altura = Pacientes[i].altura;
		Pacientes[i-1].idade = Pacientes[i].idade;
		strcpy(Pacientes[i+1].nome, Pacientes[i].nome); //Ela leva dois argumentos: a string de destino e a string de origem.
	}
	qtdPacientes--;
	if(5*qtdPacientes<2*MAX_PACIENTE){
		MAX_PACIENTE = MAX_PACIENTE / 2;
		Paciente *M = (Paciente*) realloc(Pacientes, MAX_PACIENTE*sizeof(Paciente));
		if(M==NULL){
			MAX_PACIENTE = MAX_PACIENTE * 2;
			return -3;
		}
		Pacientes=M;
	}
	return qtdPacientes;
}

