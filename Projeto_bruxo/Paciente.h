#define TAM_STRING 20

typedef struct {
	int codigo;
	char nome[TAM_STRING];
	int idade;
	float altura;
} Paciente;

int InicializarPacientes();
int EncerraPacientes();
int SalvarPaciente(Paciente b);
int QuantidadePacientes();
Paciente* ObterPacientePeloIndice(int indice);
Paciente* ObterPacientePeloCodigo(int codigo);
int AtualizarPaciente(Paciente b);
int ApagarPacientePeloCodigo(int codigo);
int ApagarPacientePeloNome(char* nome);
