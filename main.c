#include <stdio.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    char cpf[15];
    Data dataNascimento;

} Aluno;

int main(void) {
    Aluno alunos[10];
    int qtd_alunos = 0;
    
    int opcao;
    int sair = 0;

    while(!sair) { // sair == 0;
        printf("Digite a opcao desejada:\n");

        printf("0 - Sair\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Alunos\n");

        scanf("%d", &opcao); 
        
               
        
        switch(opcao) {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                printf("Cadastrar Aluno\n");
                printf("Digite a matrícula: ");

                scanf("%d", &alunos[qtd_alunos].matricula);
                printf("Digite o nome: ");

                scanf("%s", alunos[qtd_alunos].nome);
                printf("Digite o sexo (M/F): ");

                scanf(" %c", &alunos[qtd_alunos].sexo);
                printf("Digite o CPF: ");

                scanf("%s", alunos[qtd_alunos].cpf);
                printf("Digite a data de nascimento (dia mes ano): ");

                scanf("%d %d %d", &alunos[qtd_alunos].dataNascimento.dia, &alunos[qtd_alunos].dataNascimento.mes, &alunos[qtd_alunos].dataNascimento.ano);
                
                qtd_alunos++;
                break;
            }
            case 2: {
                printf("Listar Alunos\n");
                for(int i = 0; i < qtd_alunos; i++) {
                    printf("Matrícula: %d\n", alunos[i].matricula);
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Sexo: %c\n", alunos[i].sexo);
                    printf("CPF: %s\n", alunos[i].cpf);
                    printf("Data de Nascimento: %d/%d/%d\n", alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano);
                    printf("--------------------\n");
                }
                break;
            }           
            case 3:{
                printf("Atualizar Aluno\n");
                

                break;
            }
            default:
                printf("Opção inválida!\n");
        }
        
    }


    return 0;
}


// acessar um campo de uma struct : aluno1.nome // aluno1.matricula 


