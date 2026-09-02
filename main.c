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
    char cpf[12];
    Data dataNascimento;

} Aluno;

int main() {
    Aluno alunos[10];
    

    int sair = 0;

    while(!sair) { // sair == 0;
        printf("Digite a opcao desejada:\n");

        printf("0 - Sair\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Excluir Aluno\n");
        printf("3 - Atualizar Aluno\n");

        int opcao;
        scanf("%d", &opcao);        
        
        switch(opcao) {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                printf("Cadastrar Aluno\n");
                break;
            }
            case 2: {
                printf("Excluir Aluno\n");
                break;
            }           
            case 3:{
                printf("Atualizar Aluno\n");
                break;
            }
            default:
                printf("Opcao invalida!\n");
        }
        
    }


    return 0;
}


// acessar um campo de uma struct : aluno1.nome // aluno1.matricula 


