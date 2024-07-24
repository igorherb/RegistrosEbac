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
        printf("Cadastro n�o encontrado!\n");
        system("pause");
        return 1;
    }

    printf("Informa��es do usu�rio:\n");
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
        printf("CPF n�o cadastrado!\n");
        system("pause");
        return 1;
    }
    fclose(file);

    if (remove(arquivo) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o usu�rio com CPF %s.\n", cpf);
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

        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar usu�rio\n");
        printf("\t2 - Consultar usu�rio\n");
        printf("\t3 - Deletar usu�rio\n");
        printf("\t0 - Sair\n\n");
        printf("Op��o: ");

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
                printf("Op��o inv�lida!\n");
                system("pause");
                break;
        }
    }

    return 0;
}

