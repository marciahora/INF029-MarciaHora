#include <stdio.h>
#include "disciplina.h"

int cadastrarDisciplina(
    Disciplina listaDisciplina[],
    int qtdDisciplina,
    Professor listaProfessor[],
    int qtdProfessor)
{
    printf("Cadastrar Disciplina\n");

    if (qtdDisciplina >= TAM_DISCIPLINA)
        return LISTA_CHEIA;

    printf("Digite o codigo da Disciplina\n");
    scanf("%d", &listaDisciplina[qtdDisciplina].codigo);

    getchar();

    printf("Digite o nome da Disciplina\n");
    fgets(listaDisciplina[qtdDisciplina].nome, 50, stdin);

    printf("Digite o semestre\n");
    scanf("%d", &listaDisciplina[qtdDisciplina].semestre);

    printf("Digite a matricula do Professor\n");

    int matriculaProfessor;
    scanf("%d", &matriculaProfessor);

    int professorExiste = 0;

    for (int i = 0; i < qtdProfessor; i++)
    {
        if (listaProfessor[i].matricula == matriculaProfessor &&
            listaProfessor[i].ativo)
        {
            professorExiste = 1;
            break;
        }
    }

    if (!professorExiste)
    {
        printf("Professor nao cadastrado.\n");
        return 0;
    }

    listaDisciplina[qtdDisciplina].matriculaProfessor = matriculaProfessor;

    listaDisciplina[qtdDisciplina].qtdAlunos = 0;
    listaDisciplina[qtdDisciplina].ativo = 1;

    return CAD_DISCIPLINA_SUCESSO;
}

void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina)
{
    int ativas = 0;

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].ativo)
        {
            printf("\nCodigo: %d\n", listaDisciplina[i].codigo);
            printf("Nome: %s", listaDisciplina[i].nome);
            printf("Semestre: %d\n", listaDisciplina[i].semestre);
            printf("Matricula do Professor: %d\n",
                   listaDisciplina[i].matriculaProfessor);

            printf("Alunos matriculados:\n");

            if (listaDisciplina[i].qtdAlunos == 0)
            {
                printf("Nenhum aluno matriculado.\n");
            }
            else
            {
                for (int j = 0; j < listaDisciplina[i].qtdAlunos; j++)
                {
                    printf("Matricula: %d\n",
                           listaDisciplina[i].matriculasAlunos[j]);
                }
            }

            ativas++;
        }
    }

    if (ativas == 0)
    {
        printf("Nao ha disciplinas cadastradas.\n");
    }
}

int inserirAlunoDisciplina(
    Disciplina listaDisciplina[],
    int qtdDisciplina,
    Aluno listaAluno[],
    int qtdAluno)
{
    int codigo;
    int matriculaAluno;

    printf("Digite o codigo da Disciplina\n");
    scanf("%d", &codigo);

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].codigo == codigo &&
            listaDisciplina[i].ativo)
        {
            if (listaDisciplina[i].qtdAlunos >= TAM_ALUNOS_DISCIPLINA)
            {
                printf("A disciplina esta cheia.\n");
                return LISTA_CHEIA;
            }

            printf("Digite a matricula do Aluno\n");
            scanf("%d", &matriculaAluno);

            // Procura o aluno no cadastro geral
            int alunoExiste = 0;

            for (int j = 0; j < qtdAluno; j++)
            {
                if (listaAluno[j].matricula == matriculaAluno &&
                    listaAluno[j].ativo)
                {
                    alunoExiste = 1;
                    break;
                }
            }

            if (!alunoExiste)
            {
                printf("Aluno nao cadastrado.\n");
                return 0;
            }

            listaDisciplina[i]
                .matriculasAlunos[listaDisciplina[i].qtdAlunos] = matriculaAluno;

            listaDisciplina[i].qtdAlunos++;

            printf("Aluno inserido na disciplina com sucesso.\n");

            return 1;
        }
    }

    printf("Disciplina nao encontrada.\n");
    return 0;
}

int excluirAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina)
{
    int codigo;
    int matriculaAluno;

    printf("Digite o codigo da Disciplina\n");
    scanf("%d", &codigo);

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].codigo == codigo &&
            listaDisciplina[i].ativo)
        {
            printf("Digite a matricula do Aluno\n");
            scanf("%d", &matriculaAluno);

            for (int j = 0; j < listaDisciplina[i].qtdAlunos; j++)
            {
                if (listaDisciplina[i].matriculasAlunos[j] == matriculaAluno)
                {
                    // Desloca os alunos seguintes para tras
                    for (int k = j;
                         k < listaDisciplina[i].qtdAlunos - 1;
                         k++)
                    {
                        listaDisciplina[i].matriculasAlunos[k] =
                            listaDisciplina[i].matriculasAlunos[k + 1];
                    }

                    listaDisciplina[i].qtdAlunos--;

                    printf("Aluno excluido da disciplina com sucesso.\n");

                    return 1;
                }
            }

            printf("Aluno nao encontrado nesta disciplina.\n");
            return 0;
        }
    }

    printf("Disciplina nao encontrada.\n");
    return 0;
}

int atualizarDisciplina(
    Disciplina listaDisciplina[],
    int qtdDisciplina,
    Professor listaProfessor[],
    int qtdProfessor)
{
    int codigo;

    printf("Atualizar Disciplina\n");
    printf("Digite o codigo da Disciplina\n");
    scanf("%d", &codigo);

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].codigo == codigo &&
            listaDisciplina[i].ativo)
        {
            int opcao;

            printf("O que deseja atualizar?\n");
            printf("1 - Codigo\n");
            printf("2 - Nome\n");
            printf("3 - Semestre\n");
            printf("4 - Professor\n");

            scanf("%d", &opcao);

            switch (opcao)
            {
                case 1:
                {
                    int novoCodigo;

                    printf("Digite o novo codigo\n");
                    scanf("%d", &novoCodigo);

                    listaDisciplina[i].codigo = novoCodigo;
                    break;
                }

                case 2:
                {
                    printf("Digite o novo nome\n");

                    getchar();
                    fgets(listaDisciplina[i].nome, 50, stdin);

                    break;
                }

                case 3:
                {
                    printf("Digite o novo semestre\n");
                    scanf("%d", &listaDisciplina[i].semestre);

                    break;
                }

                case 4:
                {
                    int novaMatriculaProfessor;
                    int professorExiste = 0;

                    printf("Digite a matricula do novo Professor\n");
                    scanf("%d", &novaMatriculaProfessor);

                    for (int j = 0; j < qtdProfessor; j++)
                    {
                        if (listaProfessor[j].matricula == novaMatriculaProfessor &&
                            listaProfessor[j].ativo)
                        {
                            professorExiste = 1;
                            break;
                        }
                    }

                    if (!professorExiste)
                    {
                        printf("Professor nao cadastrado.\n");
                        return 0;
                    }

                    listaDisciplina[i].matriculaProfessor =
                        novaMatriculaProfessor;

                    break;
                }

                default:
                {
                    printf("Opcao invalida.\n");
                    return 0;
                }
            }

            return ATUALIZACAO_DISCIPLINA_SUCESSO;
        }
    }

    printf("Disciplina nao encontrada.\n");
    return 0;
}