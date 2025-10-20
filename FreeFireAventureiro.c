/*
====================================================================
    DESAFIO: Código da Ilha – Edição Free Fire - NÍVEL AVENTUREIRO
    Aluno: Aderlon Barbosa Pessoa
    Matéria: Estrutura de Dados
    Descrição:
        Este programa é a continuação do desafio do Nível Novato.
        Agora, além de adicionar, remover e listar itens, também é
        possível buscar um item específico pelo nome dentro da mochila.
        O objetivo é treinar o uso de busca sequencial em vetores e o
        uso da função strcmp() para comparar strings.
====================================================================
*/

#include <stdio.h>
#include <string.h>

// -------------------------------------------------------------------
// Estrutura que representa um item da mochila
// Cada item tem um nome, tipo e quantidade
// -------------------------------------------------------------------
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

int main() {

    struct Item mochila[10];   // Vetor estático que guarda até 10 itens
    int totalItens = 0;        // Conta quantos itens estão na mochila
    int opcao;                 // Guarda a escolha do usuário
    char nomeAux[30];          // Usada para remoção e busca

    // -------------------------------------------------------------------
    // Loop principal do programa - o menu será exibido até o jogador sair
    // -------------------------------------------------------------------
    do {
        printf("\n==============================\n");
        printf(" DESAFIO CÓDIGO DA ILHA - NIVEL AVENTUREIRO\n");
        printf("==============================\n");
        printf("1. Adicionar item à mochila\n");
        printf("2. Remover item da mochila\n");
        printf("3. Listar itens cadastrados\n");
        printf("4. Buscar item por nome\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch(opcao) {

            // ---------------------------------------------------------------
            // OPÇÃO 1: Adicionar item à mochila
            // ---------------------------------------------------------------
            case 1:
                if (totalItens < 10) {
                    printf("\n--- Adicionar novo item ---\n");

                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, 30, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0';

                    printf("Tipo do item: ");
                    fgets(mochila[totalItens].tipo, 20, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    getchar();

                    totalItens++;
                    printf("\nItem adicionado com sucesso!\n");
                } else {
                    printf("\nA mochila está cheia! (Limite de 10 itens)\n");
                }
                break;

            // ---------------------------------------------------------------
            // OPÇÃO 2: Remover item pelo nome
            // ---------------------------------------------------------------
            case 2:
                if (totalItens > 0) {
                    printf("\n--- Remover item ---\n");
                    printf("Digite o nome do item a ser removido: ");
                    fgets(nomeAux, 30, stdin);
                    nomeAux[strcspn(nomeAux, "\n")] = '\0';

                    int encontrado = 0;

                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeAux) == 0) {
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            totalItens--;
                            encontrado = 1;
                            printf("\nItem removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\nItem não encontrado!\n");
                    }

                } else {
                    printf("\nA mochila está vazia, nada para remover.\n");
                }
                break;

            // ---------------------------------------------------------------
            // OPÇÃO 3: Listar todos os itens cadastrados
            // ---------------------------------------------------------------
            case 3:
                if (totalItens > 0) {
                    printf("\n--- Itens na Mochila ---\n");
                    printf("%-20s %-15s %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                    printf("-----------------------------------------------\n");

                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                } else {
                    printf("\nA mochila está vazia!\n");
                }
                break;

            // ---------------------------------------------------------------
            // OPÇÃO 4: Buscar item pelo nome (NOVIDADE DO NÍVEL AVENTUREIRO)
            // ---------------------------------------------------------------
            case 4:
                if (totalItens > 0) {
                    printf("\n--- Buscar item ---\n");
                    printf("Digite o nome do item que deseja procurar: ");
                    fgets(nomeAux, 30, stdin);
                    nomeAux[strcspn(nomeAux, "\n")] = '\0';

                    int encontrado = 0; // flag que vai dizer se o item foi encontrado

                    // Busca sequencial: percorre todos os itens comparando os nomes
                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeAux) == 0) {
                            printf("\nItem encontrado!\n");
                            printf("--------------------------\n");
                            printf("Nome: %s\n", mochila[i].nome);
                            printf("Tipo: %s\n", mochila[i].tipo);
                            printf("Quantidade: %d\n", mochila[i].quantidade);
                            printf("--------------------------\n");
                            encontrado = 1;
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\nO item '%s' não foi encontrado na mochila.\n", nomeAux);
                    }

                } else {
                    printf("\nA mochila está vazia! Nada para buscar.\n");
                }
                break;

            // ---------------------------------------------------------------
            // OPÇÃO 5: Sair do sistema
            // ---------------------------------------------------------------
            case 5:
                printf("\nSaindo do sistema... Continue sua jornada, aventureiro!\n");
                break;

            // ---------------------------------------------------------------
            // OPÇÃO INVÁLIDA
            // ---------------------------------------------------------------
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 5); // repete enquanto o jogador não escolher sair

    printf("\nPrograma encerrado com sucesso.\n");
    return 0;
}

