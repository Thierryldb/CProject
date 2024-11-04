#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1000

typedef struct {
    char matricula[20];
    char nome[100];
    char cpf[15];
    char sexo[10];
    char email[100];
    char codigoTipoCurso[10];
} Aluno;

Aluno alunos[SIZE];
int totalAlunos = 0;

// Função para verificar se um CPF já está cadastrado
int cpfJaCadastrado(char *cpf) {
    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(alunos[i].cpf, cpf) == 0) {
            return 1;  // CPF encontrado, já está cadastrado
        }
    }
    return 0;  // CPF não está em uso
}

// Função para validar se a entrada contém apenas dígitos
int entradaSomenteNumeros(char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i])) {
            return 0;  // Encontrou um caractere não numérico
        }
    }
    return 1;  // Entrada válida (apenas números)
}

// Função para inserir um novo aluno
void inserirAluno() {
    if (totalAlunos < SIZE) {
        printf("Digite a matrícula: ");
        scanf("%19s", alunos[totalAlunos].matricula);
        getchar();
        
        // Valida se a matrícula contém apenas números
        if (!entradaSomenteNumeros(alunos[totalAlunos].matricula)) {
            printf("Erro: Matrícula deve conter apenas números.\n");
            return;
        }

        printf("Digite o CPF: ");
        scanf("%14s", alunos[totalAlunos].cpf);
        getchar();

        // Valida se o CPF contém apenas números
        if (!entradaSomenteNumeros(alunos[totalAlunos].cpf)) {
            printf("Erro: CPF deve conter apenas números.\n");
            return;
        }

        // Verifica se o CPF já está cadastrado
        if (cpfJaCadastrado(alunos[totalAlunos].cpf)) {
            printf("Erro: CPF já está em uso.\n");
            return;
        }

        printf("Digite o nome: ");
        fgets(alunos[totalAlunos].nome, 100, stdin);
        alunos[totalAlunos].nome[strcspn(alunos[totalAlunos].nome, "\n")] = 0;

        printf("Digite o sexo: ");
        scanf("%9s", alunos[totalAlunos].sexo);
        getchar();

        printf("Digite o e-mail: ");
        fgets(alunos[totalAlunos].email, 100, stdin);
        alunos[totalAlunos].email[strcspn(alunos[totalAlunos].email, "\n")] = 0;

        printf("Digite o código do tipo de curso: ");
        scanf("%9s", alunos[totalAlunos].codigoTipoCurso);
        getchar();

        // Valida se o código do tipo de curso contém apenas números
        if (!entradaSomenteNumeros(alunos[totalAlunos].codigoTipoCurso)) {
            printf("Erro: Código do tipo de curso deve conter apenas números.\n");
            return;
        }

        totalAlunos++;
        printf("Aluno cadastrado com sucesso!\n");
    } else {
        printf("Limite de alunos atingido!\n");
    }
}

void listarAlunos() {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("Matrícula: %s\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("CPF: %s\n", alunos[i].cpf);
        printf("Sexo: %s\n", alunos[i].sexo);
        printf("Email: %s\n", alunos[i].email);
        printf("Código Tipo de Curso: %s\n", alunos[i].codigoTipoCurso);
        printf("\n");
    }
}

void atualizarAluno() {
    char matricula[20];
    printf("Digite a matrícula do aluno a ser atualizado: ");
    scanf("%19s", matricula);
    getchar();

    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(alunos[i].matricula, matricula) == 0) {
            printf("Digite o novo e-mail: ");
            fgets(alunos[i].email, 100, stdin);
            alunos[i].email[strcspn(alunos[i].email, "\n")] = 0;
            printf("Email do aluno atualizado com sucesso!\n");
            return;
        }
    }
    printf("Aluno não encontrado!\n");
}

void excluirAluno() {
    char matricula[20];
    printf("Digite a matrícula do aluno a ser excluído: ");
    scanf("%19s", matricula);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(alunos[i].matricula, matricula) == 0) {
            encontrado = 1;
            for (int j = i; j < totalAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            totalAlunos--;
            printf("Aluno excluído com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado!\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Atualizar E-mail do Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                atualizarAluno();
                break;
            case 4:
                excluirAluno();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}
