#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"

// Implementações das funções 

void listarAluno(Aluno listaAluno[], int qtdAlunos){
    int ativos = 0;
    for(int i = 0; i < qtdAlunos; i++)
    {
        if(listaAluno[i].ativo)
        {
            printf("Matricula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("CPF:%s\n", listaAluno[i].cpf);
            printf("Nascimento: %d/%d/%d\n",
                listaAluno[i].dataNascimento.dia,
                listaAluno[i].dataNascimento.mes,
                listaAluno[i].dataNascimento.ano);
            ativos++;
        }
    }
    if(ativos <= 0) {
        printf("Não há alunos cadastrados.\n");
    }

    } 

    
int cadastrarAluno(Aluno listaAluno[], int qtdAluno) {
	printf("Cadastrar Aluno\n");
	if (qtdAluno == TAM_ALUNO)
		return LISTA_CHEIA;
	else {
		printf("Digite a matricula do Aluno\n");
		int matricula;
		scanf("%d", &matricula);
		if (matricula < 0)
			return MATRICULA_INVALIDA;
		listaAluno[qtdAluno].matricula = matricula;

        getchar(); // pega o enter que ficou 
        printf("Digite o nome do Aluno\n");
        fgets(listaAluno[qtdAluno].nome, 50, stdin);

        printf("Digite o sexo do Aluno\n");
        scanf(" %c", &listaAluno[qtdAluno].sexo);
        while (getchar() != '\n'); // impedir o loop
        if (!validarSexo(listaAluno[qtdAluno].sexo))
        {
            printf("Sexo invalido. Digite M ou F.\n");
            return SEXO_INVALIDO;
        }

               
        printf("Digite o data de nascimento (dia mes ano):\n");
        scanf("%d %d %d",
             &listaAluno[qtdAluno].dataNascimento.dia,
             &listaAluno[qtdAluno].dataNascimento.mes,
             &listaAluno[qtdAluno].dataNascimento.ano);

        if (!validarData(listaAluno[qtdAluno].dataNascimento))
        {
            printf("Data invalida.\n");
            return DATA_INVALIDA;
        }

        printf("Digite o CPF do aluno: ");
        scanf("%11s", listaAluno[qtdAluno].cpf);

        if (!validarCPF(listaAluno[qtdAluno].cpf))
        {
        printf("CPF invalido. O CPF deve possuir 11 numeros.\n");
        return CPF_INVALIDO;
        }

		listaAluno[qtdAluno].ativo = 1;
		return CAD_ALUNO_SUCESSO;
	}
}


int atualizarAluno(Aluno listaAluno[], int qtdAluno) {
	printf("Atualizar Aluno\n");
	printf("Digite a matricula do Aluno\n");
	int matricula;
	scanf("%d", &matricula);
	int achou = 0;
	if (matricula < 0)
		return MATRICULA_INVALIDA;
	else {
		for(int iCont = 0; iCont < qtdAluno; iCont++) {
			if(matricula == listaAluno[iCont].matricula && listaAluno[iCont].ativo)
            {

                printf("O que deseja atualizar?\n");
                printf("1 - Matricula\n");
                printf("2 - Nome\n");
                printf("3 - Sexo\n");
                printf("4 - Data de nascimento\n");
                printf("5 - CPF\n");

                int opcao;
                scanf("%d", &opcao);

                switch(opcao) {
                    case 1:
                    {   //atualizar matrícula 
                        printf("Digite a nova matricula do Aluno\n");
                        int novaMatricula;
                        scanf("%d", &novaMatricula);
                        if(novaMatricula < 0) 
                            return MATRICULA_INVALIDA;
                        listaAluno[iCont].matricula = novaMatricula; 
                        break;
                    }
                    case 2:
                    {   //atualizar nome
                        printf("Digite o nome do Aluno\n");
                        getchar();
                        fgets(listaAluno[iCont].nome, 50, stdin);
                        
                        break;    
                    }
                    case 3:
                    {
                        printf("Digite o sexo do Aluno (M/F)\n");
                        char novoSexo;

                        scanf(" %c", &novoSexo);
                        while (getchar() != '\n');

                        if (!validarSexo(novoSexo))
                        {
                            printf("Sexo invalido. Digite M ou F.\n");
                            return SEXO_INVALIDO;
                        }

                        listaAluno[iCont].sexo = novoSexo;
                        break;
                    }
                    case 4:
                    {
                        Data novaData;

                        printf("Digite a nova data de nascimento (dia mes ano)\n");

                        scanf("%d %d %d",
                            &novaData.dia,
                            &novaData.mes,
                            &novaData.ano);

                        if (!validarData(novaData))
                        {
                            printf("Data invalida.\n");
                            return DATA_INVALIDA;
                        }

                        listaAluno[iCont].dataNascimento = novaData;
                        break;
                    }
                    case 5:
                    {
                        char novoCPF[12];

                        printf("Digite o CPF do aluno: ");
                        scanf("%11s", novoCPF);

                        if (!validarCPF(novoCPF))
                        {
                            printf("CPF invalido. O CPF deve possuir 11 numeros.\n");
                            return CPF_INVALIDO;
                        }

                        strcpy(listaAluno[iCont].cpf, novoCPF);
                        break;
                    }
                    default:
                    {
                        printf("Opcao invalida.\n");
                        return 0;
                    }
                }
                achou = 1;
                break;
            }           
        }
        if (achou)
            return ATUALIZACAO_ALUNO_SUCESSO;
         else 
            return MATRICULA_INEXISTENTE;
    }	
    }


int excluirAluno(Aluno listaAluno[], int qtdAluno) {
    printf("Excluir Aluno\n");
    printf("Digite a matricula do Aluno\n");

    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }

    for (int iCont = 0; iCont < qtdAluno; iCont++) {

        if (matricula == listaAluno[iCont].matricula &&
            listaAluno[iCont].ativo) {

            // Desloca os alunos seguintes uma posição para trás
            for (int jCont = iCont; jCont < qtdAluno - 1; jCont++) {
                listaAluno[jCont] = listaAluno[jCont + 1];
            }

            return EXCLUSAO_ALUNO_SUCESSO;
        }
    }

    return MATRICULA_INEXISTENTE;
}

int validarCPF(char cpf[])
{
    if (strlen(cpf) != 11) 
    {
        return 0;
    }

    for (int i = 0; i < 11; i++)
    {
        if (!isdigit((unsigned char)cpf[i]))
        {
            return 0;
        }
    }

    return 1;
}

int validarSexo(char sexo)
{
    if (sexo == 'M' || sexo == 'm' ||
        sexo == 'F' || sexo == 'f')
    {
        return 1;
    }

    return 0;
}

int validarData(Data data)
{
    if (data.ano < 1900 || data.ano > 2100)
        return 0;

    if (data.mes < 1 || data.mes > 12)
        return 0;

    if (data.dia < 1 || data.dia > 31)
        return 0;

    return 1;
}