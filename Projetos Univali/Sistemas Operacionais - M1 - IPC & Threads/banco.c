#include <stdio.h>
#include <string.h>
#include "banco.h"

Registro registros[MAX_REGISTROS];

void inicializar_banco() {
    for (int i = 0; i < MAX_REGISTROS; i++) {
        registros[i].id = -1;
        registros[i].nome[0] = '\0';
    }
}

int inserir_registro(int id, const char* nome) {
    for (int i = 0; i < MAX_REGISTROS; i++) {
        if (registros[i].id == id) {
            return -1;
        }
    }

    for (int i = 0; i < MAX_REGISTROS; i++) {
        if (registros[i].id == -1) {
            registros[i].id = id;
            strncpy(registros[i].nome, nome, TAM_NOME);
            return 1;
        }
    }
    return 0;
}

int deletar_registro(int id) {
    for (int i = 0; i < MAX_REGISTROS; i++) {
        if (registros[i].id == id) {
            registros[i].id = -1;
            registros[i].nome[0] = '\0';
            return 1;
        }
    }
    return 0;
}

int update_registro(int id, const char* nome) {
    for (int i = 0; i < MAX_REGISTROS; i++) {
        if (registros[i].id == id) {
            strncpy(registros[i].nome, nome, TAM_NOME);
            return 1;
        }
    }
    return 0;
}

int selecionar_registro(int id) {
    for(int i = 0; i < MAX_REGISTROS;i++) {
        if(registros[i].id == id) {
            printf("Usuário de ID %d encontrado com nome: %s\n",id,registros[i].nome);
            return 1;
        }
    }
    printf("Usuário nao encontrado no banco de dados\n");
    return 0;
}


void salvar_banco() {
    FILE *arquivo = fopen("banco_dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar o banco.\n");
        return;
    }

    for (int i = 0; i < MAX_REGISTROS; i++) {
        if (registros[i].id != -1) {
            fprintf(arquivo, "id=%d nome='%s'\n", registros[i].id, registros[i].nome);
        }
    }

    fclose(arquivo);
    printf("Banco salvo com sucesso em 'banco_dados.txt'.\n");
}

void imprimir_banco() {
    printf("Estado atual do banco:\n");
    for (int i = 0; i < MAX_REGISTROS; i++) {
        if (registros[i].id != -1) {
            printf("ID: %d | Nome: %s\n", registros[i].id, registros[i].nome);
        }
    }
    printf("------------------------\n");
}