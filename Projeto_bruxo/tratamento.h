#define TAM_STRING 20

typedef struct {
	int codigo;
	char nome[TAM_STRING];
	char especialidade[TAM_STRING];
} Tratamento;

int InicializarTratamentos();
int EncerraTratamentos();
int InicializarTratamento(Tratamento t);
int QuantidadeTratamentos();
Tratamento* ObterTratamentoPeloIndice(int indice);
Tratamento* ObterTratamentoPeloCodigo(int codigo);
int AmpliarTratamento(Tratamento t);
int ApagarTratamentoPeloCodigo(int codigo);

