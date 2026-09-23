#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"


int menuGeral();
int menuAluno();
int menuProfessor();
int menuDisciplina();


int main(void) {

	Aluno listaAluno[TAM_ALUNO];
	int opcao;
	int qtdAluno = 0;  //contador

	Professor listaProfessor[TAM_PROFESSOR];
	int qtdProfessor = 0;

	Disciplina listaDisciplina[TAM_DISCIPLINA];
	int qtdDisciplina = 0;
	
	int sair = 0;

	while (!sair) {

		opcao = menuGeral();

		switch (opcao) {
		case 0: {
			sair = 1;
			break;
			}
		case 1: {
			printf("Modulo Aluno\n");
			int sairAluno = 0;
			int opcaoAluno;
			while(!sairAluno) {
				opcaoAluno = menuAluno();
				switch (opcaoAluno) {
				case 0: {
					sairAluno = 1;
					break;
				}
				case 1: {

					int retorno = cadastrarAluno(listaAluno, qtdAluno);
					if (retorno == LISTA_CHEIA)
						printf("Lista de Alunos Cheia\n");
					else if (retorno == MATRICULA_INVALIDA)
						printf("Matricula Invalida\n");
					else if (retorno == CPF_INVALIDO)
   						 printf("CPF invalido\n");
					else if (retorno == SEXO_INVALIDO)
   						 printf("Sexo invalido\n");
					else {
						printf("Cadastrado com sucesso\n");
						qtdAluno++;
					}
					break;
				}
				case 2: {

					listarAluno(listaAluno, qtdAluno);
					break;
				}
				case 3: {
					int retorno = atualizarAluno(listaAluno, qtdAluno);
					switch (retorno) {
					case MATRICULA_INVALIDA:{
						printf("Matricula invalida\n");
						break;
					}
					case MATRICULA_INEXISTENTE:{
							printf("Matricula inexistente\n");
							break;
					}
					case ATUALIZACAO_ALUNO_SUCESSO:{
						printf("Aluno atualizado com sucesso\n");
						break;
					}
			    	}

					break;
				}
				case 4: {
					    
				    int retorno = excluirAluno(listaAluno, qtdAluno);
				    switch (retorno) {
				        case MATRICULA_INVALIDA: {
						     printf("Matricula invalida\n");
						     break;
					    }
					    case MATRICULA_INEXISTENTE: {
							printf("Matricula inexistente\n");
							break;
						}
					    case EXCLUSAO_ALUNO_SUCESSO: {
							printf("Aluno excluido com sucesso\n");
							qtdAluno--;
							break;
						}
					}
					break;
				}
				default: {
					printf("Opção Invalida\n");
					break;
				}

				}

			}
     		break;
			}
		case 2: {
			printf("Modulo Professor\n");

			int sairProfessor = 0;
			int opcaoProfessor;

			while (!sairProfessor) {

				opcaoProfessor = menuProfessor();

				switch (opcaoProfessor) {

					case 0: {
						sairProfessor = 1;
						break;
					}

					case 1: {
						int retorno = cadastrarProfessor(listaProfessor, qtdProfessor);

						if (retorno == LISTA_CHEIA)
							printf("Lista de Professores Cheia\n");
						else if (retorno == MATRICULA_INVALIDA)
							printf("Matricula Invalida\n");
						else if (retorno == CPF_INVALIDO)
   							 printf("CPF invalido\n");
						else {
							printf("Professor cadastrado com sucesso\n");
							qtdProfessor++;
						}

						break;
					}

					case 2: {
						listarProfessor(listaProfessor, qtdProfessor);
						break;
					}

					case 3: {
						int retorno = atualizarProfessor(listaProfessor, qtdProfessor);

						switch (retorno) {

							case MATRICULA_INVALIDA:
								printf("Matricula invalida\n");
								break;

							case MATRICULA_INEXISTENTE:
								printf("Matricula inexistente\n");
								break;

							case ATUALIZACAO_PROFESSOR_SUCESSO:
								printf("Professor atualizado com sucesso\n");
								break;
						}

						break;
					}

					case 4: {
						int retorno = excluirProfessor(listaProfessor, qtdProfessor);

						switch (retorno) {

							case MATRICULA_INVALIDA:
								printf("Matricula invalida\n");
								break;

							case MATRICULA_INEXISTENTE:
								printf("Matricula inexistente\n");
								break;

							case EXCLUSAO_PROFESSOR_SUCESSO:
								printf("Professor excluido com sucesso\n");
								qtdProfessor--;
								break;
						}

						break;
					}

					default: {
						printf("Opcao Invalida\n");
						break;
					}
				}
			}

			break;
		}
		case 3: {
			printf("Modulo Disciplina\n");

			int sairDisciplina = 0;
			int opcaoDisciplina;

			while (!sairDisciplina) {

				opcaoDisciplina = menuDisciplina();

				switch (opcaoDisciplina) {

					case 0: {
						sairDisciplina = 1;
						break;
					}

					case 1: {
						int retorno = cadastrarDisciplina(
										listaDisciplina,
										qtdDisciplina,
										listaProfessor,
										qtdProfessor
									);

						if (retorno == CAD_DISCIPLINA_SUCESSO)
							{
							printf("Disciplina cadastrada com sucesso\n");
							qtdDisciplina++;
							}
							else if (retorno == LISTA_CHEIA)
							{
							printf("Lista de disciplinas cheia\n");
							}
						break;
					}

					case 2: {
						listarDisciplina(listaDisciplina, qtdDisciplina);
						break;
					}

					case 3: {
						inserirAlunoDisciplina(
							listaDisciplina,
							qtdDisciplina,
							listaAluno,
							qtdAluno
						);
						break;
					}

					case 4: {
						excluirAlunoDisciplina(
							listaDisciplina,
							qtdDisciplina
						);
						break;
					}

					default: {
						printf("Opcao Invalida\n");
						break;
					}
				}
			}

			break;
		}
		default: 
			{
			printf("Opção Invalida\n");
			break;
			}

	


		}
	}
	return 0;
}
	

// funcoes

int menuGeral() {
	int opcao;
	printf("Projeto Escola\n");
	printf("0 - Sair\n");
	printf("1 - Aluno\n");
	printf("2 - Professor\n");
	printf("3 - Disciplina\n");

	scanf("%d", &opcao);

	return opcao;
}

int menuAluno() {
	int opcao;
	printf("0 - Voltar\n");
	printf("1 - Cadastrar Aluno\n");
	printf("2 - listar Aluno\n");
	printf("3 - Atualizar Aluno\n");
	printf("4 - Excluir Aluno\n");

	scanf("%d", &opcao);

	return opcao;
}

int menuProfessor() {
    int opcao;

    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");

    scanf("%d", &opcao);

    return opcao;
}

int menuDisciplina() {
    int opcao;

    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Inserir Aluno na Disciplina\n");
    printf("4 - Excluir Aluno da Disciplina\n");

    scanf("%d", &opcao);

    return opcao;
}
// acessar um campo de uma struct : aluno1.nome // aluno1.matricula 


