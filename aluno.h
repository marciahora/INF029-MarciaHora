#ifndef ALUNO_H // impedir q conteudo do header seja processado mais de uma
#define ALUNO_H


#define TAM_ALUNO 3
#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6
#define CPF_INVALIDO -7
#define SEXO_INVALIDO -8
#define DATA_INVALIDA -9



// Definição de data 
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

//Definição de Aluno
typedef struct {
    int matricula;
    char sexo;
    int ativo;
    char nome[50];
    char cpf[12];
    Data dataNascimento;
} Aluno;

// Declaração das funções 

int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);
int validarCPF(char cpf[]);
int validarSexo(char sexo);
int validarData(Data data);


#endif

