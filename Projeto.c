#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_LENGTH 39

void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int registro() {
    char arquivo[MAX_LENGTH + 5];
    char cpf[MAX_LENGTH];
    char nome[MAX_LENGTH];
    char sobrenome[MAX_LENGTH];
    char cargo[MAX_LENGTH];

    printf("Digite o CPF a ser cadastrado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s\n", cpf);

    printf("Digite o nome a ser cadastrado: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    fprintf(file, "%s\n", nome);

    printf("Digite o sobrenome a ser cadastrado: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';
    fprintf(file, "%s\n", sobrenome);

    printf("Digite o cargo a ser cadastrado: ");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = '\0';
    fprintf(file, "%s\n", cargo);

    fclose(file);

    printf("Registro realizado com sucesso!\n");
    system("pause");
    return 0;
}

int consulta() {
    char cpf[MAX_LENGTH];
    char arquivo[MAX_LENGTH + 5];
    char linha[255];

    printf("Digite o CPF a ser consultado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");

    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Cadastro não encontrado!\n");
        system("pause");
        return 1;
    }

    printf("Informações do usuário:\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }

    fclose(file);
    system("pause");
    return 0;
}

int deletar() {
    char cpf[MAX_LENGTH];
    char arquivo[MAX_LENGTH + 5];

    printf("Digite o CPF a ser deletado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");

    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("CPF não cadastrado!\n");
        system("pause");
        return 1;
    }
    fclose(file);

    if (remove(arquivo) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o usuário com CPF %s.\n", cpf);
    }

    system("pause");
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    int laco = 1;

    while (laco) {
        system("cls");

        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar usuário\n");
        printf("\t2 - Consultar usuário\n");
        printf("\t3 - Deletar usuário\n");
        printf("\t0 - Sair\n\n");
        printf("Opção: ");

        scanf("%d", &opcao);
        limparBuffer();

        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;

            case 0:
                laco = 0;
                break;

            default:
                printf("Opção inválida!\n");
                system("pause");
                break;
        }
    }

    return 0;
}

