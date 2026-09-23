#include <stdio.h>
#include <string.h>
#include "professor.h"

void listarProfessor(Professor listaProfessor[], int qtdProfessor)
{
    int ativos = 0;

    for (int i = 0; i < qtdProfessor; i++)
    {
        if (listaProfessor[i].ativo)
        {
            printf("Matricula: %d\n", listaProfessor[i].matricula);
            printf("Nome: %s", listaProfessor[i].nome);
            printf("Sexo: %c\n", listaProfessor[i].sexo);
            printf("CPF: %s\n", listaProfessor[i].cpf);

            printf("Nascimento: %d/%d/%d\n",
                   listaProfessor[i].dataNascimento.dia,
                   listaProfessor[i].dataNascimento.mes,
                   listaProfessor[i].dataNascimento.ano);

            ativos++;
        }
    }

    if (ativos <= 0)
    {
        printf("Nao ha professores cadastrados.\n");
    }
}


int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor)
{
    printf("Cadastrar Professor\n");

    if (qtdProfessor == TAM_PROFESSOR)
        return LISTA_CHEIA;

    printf("Digite a matricula do Professor\n");
    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0)
        return MATRICULA_INVALIDA;

    listaProfessor[qtdProfessor].matricula = matricula;

    getchar();
    printf("Digite o nome do Professor\n");
    fgets(listaProfessor[qtdProfessor].nome, 50, stdin);

    
    printf("Digite o sexo do Professor\n");
    scanf(" %c", &listaProfessor[qtdProfessor].sexo);
    while (getchar() != '\n');
    
    if (!validarSexo(listaProfessor[qtdProfessor].sexo))
    {
        printf("Sexo invalido. Digite M ou F.\n");
        return SEXO_INVALIDO;
    }

    

    printf("Digite a data de nascimento (dia mes ano):\n");
    scanf("%d %d %d",
          &listaProfessor[qtdProfessor].dataNascimento.dia,
          &listaProfessor[qtdProfessor].dataNascimento.mes,
          &listaProfessor[qtdProfessor].dataNascimento.ano);

    if (!validarData(listaProfessor[qtdProfessor].dataNascimento))
    {
        printf("Data invalida.\n");
        return DATA_INVALIDA;
    }

    printf("Digite o CPF do Professor: ");
    scanf("%11s", listaProfessor[qtdProfessor].cpf);

    if (!validarCPF(listaProfessor[qtdProfessor].cpf))
    {
        printf("CPF invalido. O CPF deve possuir 11 numeros.\n");
        return CPF_INVALIDO;
    }

    listaProfessor[qtdProfessor].ativo = 1;

    return CAD_PROFESSOR_SUCESSO;
}

int atualizarProfessor(Professor listaProfessor[], int qtdProfessor)
{
    printf("Atualizar Professor\n");
    printf("Digite a matricula do Professor\n");

    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0)
        return MATRICULA_INVALIDA;

    for (int iCont = 0; iCont < qtdProfessor; iCont++)
    {
        if (matricula == listaProfessor[iCont].matricula &&
            listaProfessor[iCont].ativo)
        {
            printf("O que deseja atualizar?\n");
            printf("1 - Matricula\n");
            printf("2 - Nome\n");
            printf("3 - Sexo\n");
            printf("4 - Data de nascimento\n");
            printf("5 - CPF\n");

            int opcao;
            scanf("%d", &opcao);

            switch (opcao)
            {
                case 1:
                {
                    printf("Digite a nova matricula do Professor\n");

                    int novaMatricula;
                    scanf("%d", &novaMatricula);

                    if (novaMatricula < 0)
                        return MATRICULA_INVALIDA;

                    listaProfessor[iCont].matricula = novaMatricula;
                    break;
                }

                case 2:
                {
                    printf("Digite o novo nome do Professor\n");

                    getchar();
                    fgets(listaProfessor[iCont].nome, 50, stdin);
                    break;
                }

                case 3:
                {
                    char novoSexo;

                    printf("Digite o novo sexo do Professor (M/F)\n");
                    scanf(" %c", &novoSexo);

                    while (getchar() != '\n');

                    if (!validarSexo(novoSexo))
                    {
                        printf("Sexo invalido. Digite M ou F.\n");
                        return SEXO_INVALIDO;
                    }

                    listaProfessor[iCont].sexo = novoSexo;
                    break;
                }

                case 4:
                {
                    Data novaData;
                    printf("Digite a nova data de nascimento (dia mes ano):\n");

                    scanf("%d %d %d",
                          &novaData.dia,
                          &novaData.mes,
                          &novaData.ano);

                    if (!validarData(novaData))
                        {
                            printf("Data invalida.\n");
                            return DATA_INVALIDA;
                        }

                    listaProfessor[iCont].dataNascimento = novaData;
                    break;
                }

                case 5:
                {
                    char novoCPF[12];

                    printf("Digite o novo CPF do Professor: ");
                    scanf("%11s", novoCPF);

                    if (!validarCPF(novoCPF))
                    {
                        printf("CPF invalido. O CPF deve possuir 11 numeros.\n");
                        return CPF_INVALIDO;
                    }

                    strcpy(listaProfessor[iCont].cpf, novoCPF);
                    break;
                }

                default:
                {
                    printf("Opcao invalida\n");
                    return 0;
                }
            }

            return ATUALIZACAO_PROFESSOR_SUCESSO;
        }
    }

    return MATRICULA_INEXISTENTE;
}


int excluirProfessor(Professor listaProfessor[], int qtdProfessor)
{
    printf("Excluir Professor\n");
    printf("Digite a matricula do Professor\n");

    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }

    for (int iCont = 0; iCont < qtdProfessor; iCont++)
    {
        if (matricula == listaProfessor[iCont].matricula &&
            listaProfessor[iCont].ativo)
        {
            // Move os professores seguintes uma posição para trás
            for (int jCont = iCont; jCont < qtdProfessor - 1; jCont++)
            {
                listaProfessor[jCont] = listaProfessor[jCont + 1];
            }

            return EXCLUSAO_PROFESSOR_SUCESSO;
        }
    }

    return MATRICULA_INEXISTENTE;
}