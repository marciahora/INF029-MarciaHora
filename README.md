# INF029-MarciaHora
Repositório da disciplina INF029 do curso de ADS IFBA. 

# Projeto Escola - INF029

Sistema desenvolvido em C para gerenciamento de uma escola.

## Funcionalidades

- Cadastro, listagem, atualização e exclusão de alunos
- Cadastro, listagem, atualização e exclusão de professores
- Cadastro e listagem de disciplinas
- Inserção de alunos em disciplinas
- Exclusão de alunos de disciplinas

## Estrutura do projeto

- `main.c` - menu principal
- `aluno.c` / `aluno.h` - módulo de alunos
- `professor.c` / `professor.h` - módulo de professores
- `disciplina.c` / `disciplina.h` - módulo de disciplinas

## Compilação

```bash
gcc main.c aluno.c professor.c disciplina.c -o escola

## Execução 
./escola.exe