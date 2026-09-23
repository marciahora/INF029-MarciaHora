#ifndef PROFESSOR_H  // include guard
#define PROFESSOR_H

#include "aluno.h"


#define TAM_PROFESSOR 3
#define CAD_PROFESSOR_SUCESSO -20
#define ATUALIZACAO_PROFESSOR_SUCESSO -21
#define EXCLUSAO_PROFESSOR_SUCESSO -22

typedef struct {
    int matricula;
    char sexo;
    int ativo;
    char nome[50];
    char cpf[12];
    Data dataNascimento;
} Professor;

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);

void listarProfessor(Professor listaProfessor[], int qtdProfessor);

int atualizarProfessor(Professor listaProfessor[], int qtdProfessor);

int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

#endif