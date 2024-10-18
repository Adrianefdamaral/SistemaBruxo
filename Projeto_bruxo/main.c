#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Bruxo.h"
#include "Pocao.h"
#include "Paciente.h"
#include "tratamento.h"

#define MAX_BRUXOS 6
#define MAX_TEXTO 15
#define MAX_POCAO 5
#define MAX_PACIENTE 5
#define MAX_TRATAMENTO 5

int menu =0, i = 0;
char bruxoNome[MAX_BRUXOS][MAX_TEXTO], bruxoEspecialidade[MAX_BRUXOS][MAX_TEXTO];
char pocaoNome[MAX_POCAO][MAX_TEXTO], pocaoTipo[MAX_POCAO][MAX_TEXTO];
char pacienteNome[MAX_PACIENTE][MAX_TEXTO]; 
char tratamentoNome[MAX_TRATAMENTO][MAX_TEXTO];
int pacienteIdade[MAX_PACIENTE];
float pacienteAltura[MAX_PACIENTE];
int tratamento[MAX_TRATAMENTO][5];



void listaBruxo(){
	int i=0;
	printf("\nSegue listagem de Bruxos Cadastrados:");
	for(i=0;i<MAX_BRUXOS;i++){
		if(bruxoNome[i][0] != '\0')
			printf("\n%d - %s - %s", i, bruxoNome[i], bruxoEspecialidade[i]);
	}
	printf("\n");
}

void listaPocao(){
	printf("\nSegue listagem de Poções Cadastradas:");
	printf("\nCódigo - Nome - Tipo");
	for(i=0;i<MAX_POCAO;i++){
		if(pocaoNome[i][0] != '\0')
			printf("\n%d - %s - %s", i, pocaoNome[i], pocaoTipo[i]);
	}
	printf("\n");	
}
void listaPaciente(){
	int i=0;
	printf("\nSegue listagem de Pacientes Cadastrados(as):");
	printf("\nCódigo - Nome - Idade - Altura");
	for(i=0;i<MAX_PACIENTE;i++){
		if(pacienteNome[i][0] != '\0')
			printf("\n%d - %s - %d - %.2f", i, pacienteNome[i], pacienteIdade[i], pacienteAltura[i]);
	}
	printf("\n");	
}

void excluiBruxo(){
	int n = 0;
	int i = 0;
	printf("\nInforme o indice do bruxo a ser excluído:\n");
	scanf("%d", &n);
	if(VerificarTratamentoBruxo(n) == -1) 
	{
		printf("Esse bruxo, não pode ser apagado");
	}
	if(ApagarBruxoPeloCodigo(n))
	{
		printf("Bruxo apagado com sucesso");
	}
		
}

void excluiPocao(){
	int n = 0;
	int i = 0;
	printf("\nInforme o indice da Poção a ser excluída:\n");
	scanf("%d", &n);
	if(verificarTratamentoPocao(n) == -1){
		printf("Essa pocao, não pode ser apagado");
	}
	if(ApagarPocaoPeloCodigo(n)){
		printf("Pocão apagada com sucesso");
	}
}

void excluiPaciente(){
	int n = 0;
	int i = 0;
	printf("\nInforme o indice do(a) Paciente a ser excluído(a):\n");
	scanf("%d", &n);
	if(verificarTratamentoPaciente(n) == -1){
		printf("Esse paciente, não pode ser apagado");
	}
	if(ApagarPacientePeloCodigo(n) == -1){
		printf("Paciente foi excluido com sucesso!");
	}
}

void cadastraTratamento(){
	int i=0, j=0, k = 0, ver;
	for(i=0;i<MAX_TRATAMENTO;i++){
		if(tratamento[i][0] == -1){
			listaBruxo();
			printf("\nInforme o código do bruxo responsável pelo tratamento:\n");
			scanf("%d", &tratamento[i][0]);
			if(strcmp(bruxoNome[tratamento[i][0]],"")==0){
				printf("\nCadastro inválido.");
				for(j=0;j<5;j++){
					tratamento[i][j] = -1;
				}
				break;
			}
			listaPaciente();
			printf("\nInforme o código do paciente tratado:\n");
			scanf("%d", &ver);
			if(strcmp(pacienteNome[ver],"")==0){
				printf("\nCadastro inválido.");
				for(j=0;j<5;j++){
					tratamento[i][j] = -1; 
				}	
				break;		
			}
			for(k=0;k<MAX_TRATAMENTO;k++){
				if(tratamento[k][1] == ver){
					for(j=0;j<5;j++){
					tratamento[i][j] = -1;
					printf("\nPaciente já tem um tratamento ativo."); 
					return;
					}
				}
			}
			tratamento[i][1] = ver;
			listaPocao();
			printf("\nInforme o código do medicamento a ser utilizado:\n");
			scanf("%d", &tratamento[i][2]);
			if(strcmp(pocaoNome[tratamento[i][2]],"")==0){
				printf("\nCadastro inválido.");
				for(j=0;j<5;j++){
					if(j == 0)
						tratamento[i][j] = -1; 
					else
						tratamento[i][j] = 0; 	
				}
				break;
		 	}
			printf("\nInforme a duração prevista para o tratamento:\n");
		 	scanf("%d", &tratamento[i][3]);
		 	printf("\nInforme a dosagem a ser administrada:\n");
			scanf("%d", &tratamento[i][4]);
			printf("\nTratamento cadastrado com sucesso.\n");
		break;
		}
	}
}

void listaTratamento(){
	int i = 0;
	for(i=0;i<MAX_TRATAMENTO;i++){
		if(tratamento[i][0] != -1){
		 	printf("\nÍndice - Bruxo - Paciente - Medicamento - Duração - Dosagem");
			printf("\n%d - %s - %s - %s - %d Dias - %d vezes ao dia\n", i, bruxoNome[tratamento[i][0]], pacienteNome[tratamento[i][1]], pocaoNome[tratamento[i][2]], tratamento[i][3], tratamento[i][4]); 
			
		}
	}
}

int main() {
int Resultado = InicializarBruxos();
if(Resultado<0){
	printf("Erro na inicialização de Bruxos\n");
	exit(1);
}

Resultado = InicializarPacientes();
if(Resultado<0){
	printf("Erro na inicialização de Pacientes\n");
	exit(1);
}
Resultado = InicializarPocoes();
if(Resultado<0){
	printf("Erro na inicialização de Pocoes\n");
	exit(1);
}
Resultado = InicializarTratamentos();
if(Resultado<0){
	printf("Erro na inicialização de Tratamentos\n");
	exit(1);
}

EncerraBruxos();
EncerraPacientes();
EncerraPocoes();
EncerraTratamentos();

    
	setlocale(LC_ALL, "portuguese");
	int t = 0, tr = 0;
	int cod = 0, menuAmp = 0;
	strcpy(bruxoNome[0],"Gerald"), strcpy(bruxoNome[1],"Cirila"), strcpy(bruxoNome[2],"Tess"),
	strcpy(bruxoNome[3],"Yennefer");
	strcpy(bruxoEspecialidade[0],"Tônicos"), strcpy(bruxoEspecialidade[1],"Cosméticos"), 
	strcpy(bruxoEspecialidade[2],"Poções");
	strcpy(bruxoEspecialidade[3],"Fisioterapia");
	strcpy(pocaoNome[0], "Rubarbo"), strcpy(pocaoNome[1], "Bezetacil");
	strcpy(pocaoTipo[0], "Comprimido"), strcpy(pocaoTipo[1], "Líquido");
	strcpy(pacienteNome[0],"Jubileu"), strcpy(pacienteNome[1],"Maria");
	pacienteIdade[0] = 55, pacienteIdade[1] = 25;
	pacienteAltura[0] = 1.78, pacienteAltura[1] = 1.64;
	for(t=1;t<MAX_TRATAMENTO;t++){
		for(tr=0;tr<5;tr++){
			tratamento[t][tr] = -1;
		}
	}

	
	tratamento[0][0] = 2;	
	tratamento[0][1] = 0;	
	tratamento[0][2] = 1;	
	tratamento[0][3] = 5;	
	tratamento[0][4] = 3;
	
	do{
		fflush(stdin);
		printf("\n0 - Sair");
		printf("\n1 - Listar Bruxos\n2 - Cadastrar Bruxo por Código\n3 - Excluir Bruxo por Código");
		printf("\n4 - Listar Poções\n5 - Cadastrar Poção por Código\n6 - Excluir Poção, por Código");
		printf("\n7 - Listar Pacientes\n8 - Cadastrar Paciente por Código\n9 - Excluir Paciente por Código");
		printf("\n10 - Listar Tratamentos do Paciente");
		printf("\n11 - Listar Pacientes do Bruxo");
		printf("\n12 - Iniciar Tratamento\n13 - Ampliar Tratamento\n14 - Apagar Tratamento\n");
		printf("\nInforme a opção desejada: ");
		scanf("%d", &menu);
		switch(menu){
			case 0:
				printf("\nObrigado por utilizar os serviços da nossa clinica.\nTenha um bom dia e não se esqueça:\nDê um trocado pro seu bruxo.");
				break;
			case 1:
				listaBruxo();
				break;	
			case 2:
				listaBruxo();
				printf("\nEscolha o índice no qual o bruxo deve ser cadastrado:\n");
				scanf("%d", &cod);
				if(cod>=0 && cod<MAX_BRUXOS){
					if(strcmp(bruxoNome[cod],"")==0){
						printf("\nInforme o nome do bruxo a ser cadastrado:\n");
						scanf("%s", bruxoNome[cod]);
						printf("\nInforme a especialidade do bruxo a ser cadastrado:\n");
						scanf("%s", bruxoEspecialidade[cod]);
						printf("\nBruxo cadastrado com sucesso.");
					}
					else{
						printf("\nIndice já utilizado.");
					}
				}	
				else{
					printf("\nCódigo Inválido.");	
				}
				printf("\n");			
				break;	
			case 3:
				listaBruxo();
				excluiBruxo();
				printf("\n");
				break;
			
			case 4:
				listaPocao();
				break;		
			case 5:
				listaPocao();
				printf("\nEscolha o índice no qual a poção deve ser cadastrada:\n");
				scanf("%d", &cod);
				if(cod>=0 && cod<MAX_POCAO){
					if(strcmp(pocaoNome[cod],"")==0){
						printf("\nInforme o nome da poção a ser cadastrada:\n");
						scanf("%s", pocaoNome[cod]);
						printf("\nInforme o tipo da poção a ser cadastrada:\n");
						scanf("%s", pocaoTipo[cod]);
						printf("\nPoção cadastrada com sucesso.");
					}
					else{
						printf("\nIndice já utilizado.");
					}
				}	
				else{
					printf("\nCódigo Inválido.");	
				}
				printf("\n");				
				break;
			case 6:
				listaPocao();
				excluiPocao();
				printf("\n");
				break;
			case 7:
				listaPaciente();
				break;	
			case 8:
				listaPaciente();
				printf("\nEscolha o índice no qual o(a) paciente deve ser cadastrado(a):\n");
				scanf("%d", &cod);
				if(cod>=0 && cod<MAX_PACIENTE){
					if(strcmp(pacienteNome[cod],"")==0){
						printf("\nInforme o nome do paciente a ser cadastrado(a):\n");
						scanf("%s", pacienteNome[cod]);
						printf("\nInforme a idade do paciente a ser cadastrado(a):\n");
						scanf("%i", &pacienteIdade[cod]);
						printf("\nInforme a altura do paciente a ser cadastrado(a):\n");
						scanf("%f", &pacienteAltura[cod]);
						printf("\nPaciente cadastrado(a) com sucesso.");
					}
					else{
						printf("\nIndice já utilizado.");
					}
				}	
				else{
					printf("\nCódigo Inválido.");	
				}
				printf("\n");				
				break;			
			case 9:
				listaPaciente();
				excluiPaciente();
				printf("\n");
				break;	
			case 10:
				listaPaciente();
				printf("\nInforme o código do paciente que deseja consultar:");
				scanf("%d", &cod);
				for(i=0;i<MAX_TRATAMENTO;i++){
					if(tratamento[i][1] == cod){
						printf("\nBruxo - Medicamento - Duração - Dosagem");
						printf("\n%s - %s - %d Dias - %d vezes ao dia\n", 
						bruxoNome[tratamento[i][0]], pocaoNome[tratamento[i][2]], tratamento[i][3], tratamento[i][4]); 
						break;
					}
				}
				break;	
			case 11:
				listaBruxo();
				printf("\nInforme o código do bruxo que deseja consultar:");
				scanf("%d", &cod);
				for(i=0;i<MAX_TRATAMENTO;i++){
					if(tratamento[i][0] == cod){
						printf("\nPaciente - Medicamento - Duração - Dosagem");
						printf("\n%s - %s - %d Dias - %d vezes ao dia\n", 
						pacienteNome[tratamento[i][1]], pocaoNome[tratamento[i][2]], tratamento[i][3], tratamento[i][4]); 
						break;
					}
				}
				break;	
			case 12:
				cadastraTratamento();
				break;
			case 13:
				listaTratamento();
				printf("\nInforme qual tratamento deseja ampliar:");
				scanf("%d", &cod);
				if(cod>=0 && cod<MAX_TRATAMENTO && tratamento[cod][0] != -1){
					printf("\nInforme qual fator deve ser ampliado:");
					printf("\n1 - Duração\n2 - Dosagem\n3 - Duração e Dosagem\n");
					scanf("%d", &menuAmp);
					switch(menuAmp){
						case 1:
							printf("\nInforme a nova duração do tratamento:");
							scanf("%d", &tratamento[cod][3]);
							break;
						case 2:
							printf("\nInforme a nova dosagem do tratamento:");
							scanf("%d", &tratamento[cod][4]);
							break;	
						case 3:
							printf("\nInforme a nova duração do tratamento:");
							scanf("%d", &tratamento[cod][3]);
							printf("\nInforme a nova dosagem do tratamento:");
							scanf("%d", &tratamento[cod][4]);
							break;	
						default:
							printf("\nTratamento não encontrado.");	
					}
				}
				printf("\nCódigo inválido.");	
				break;		
			case 14:
				listaTratamento();
				printf("\nInforme o tratamento que deseja excluir:");
				scanf("%d", &cod);
				if(tratamento[cod][0] != -1){
					for(i=0;i<5;i++){
						tratamento[cod][i] = -1;
					}
					printf("\nTratamento excluído com sucesso.");
				}
				else{
					printf("\nCódigo Inválido");
				}
				
				break;	
			default:
				printf("\nCódigo Inválido");
				printf("\n");
				break;
		}
				
	}while(menu!=0);
	return 0;
}
