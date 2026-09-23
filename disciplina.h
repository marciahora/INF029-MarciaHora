#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h"
#include "professor.h"

#define TAM_DISCIPLINA 3
#define TAM_ALUNOS_DISCIPLINA 3

#define CAD_DISCIPLINA_SUCESSO -10
#define ATUALIZACAO_DISCIPLINA_SUCESSO -11
#define EXCLUSAO_DISCIPLINA_SUCESSO -12

typedef struct {
    int codigo;
    char nome[50];
    int semestre;

    int matriculaProfessor;

    int matriculasAlunos[TAM_ALUNOS_DISCIPLINA];
    int qtdAlunos;

    int ativo;

} Disciplina;

int cadastrarDisciplina(
    Disciplina listaDisciplina[],
    int qtdDisciplina,
    Professor listaProfessor[],
    int qtdProfessor
);
int excluirAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);

int inserirAlunoDisciplina(
    Disciplina listaDisciplina[],
    int qtdDisciplina,
    Aluno listaAluno[],
    int qtdAluno
);

void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);

int atualizarDisciplina(
    Disciplina listaDisciplina[],
    int qtdDisciplina,
    Professor listaProfessor[],
    int qtdProfessor
);


#endif