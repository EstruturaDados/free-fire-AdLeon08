/*
==============================================================
DESAFIO Código da Ilha – Edição Free Fire - NÍVEL AVENTUREIRO
Aluno: Aderlon Barbosa Pessoa
Matéria: Estrutura de Dados
Descrição:
Neste nível, o sistema de mochila virtual é aprimorado para 
permitir a busca de itens pelo nome. Agora o jogador pode 
consultar rapidamente se um item está na mochila e visualizar 
seus detalhes. O programa utiliza busca sequencial com 
comparação de strings (strcmp) e controle por flag.
==============================================================
*/

#include <stdio.h>
#include <string.h> // Necessário para usar strcmp()

// Definindo o limite máximo de itens na mochila
#define MAX_ITENS 10

// Estrutura que representa cada item da mochila
struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS]; // Vetor que armazena os itens
    int totalItens = 0;             // Quantidade atual de itens na mochila
    int opcao;                      // Controle do menu
    int i;                          // Variável auxiliar para laços

    // Laço principal com menu interativo
    do {
        printf("\n===== MOCHILA DO SOBREVIVENTE - NÍVEL AVENTUREIRO =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item por nome\n"); // NOVA OPÇÃO!
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                // Adicionar novo item na mochila
                if (totalItens < MAX_ITENS) {
                    printf("\nDigite o nome do item: ");
                    fgets(mochila[totalItens].nome, sizeof(mochila[totalItens].nome), stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0'; // Remove o \n

                    printf("Digite o tipo do item: ");
                    fgets(mochila[totalItens].tipo, sizeof(mochila[totalItens].tipo), stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                    printf("Digite a quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    getchar(); // Limpa o buffer

                    totalItens++;
                    printf("\nItem adicionado com sucesso!\n");
                } else {
                    printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
                }
                break;

            case 2:
                // Remover item pelo nome
                if (totalItens > 0) {
                    char nomeRemover[50];
                    int encontrado = 0;

                    printf("\nDigite o nome do item a remover: ");
                    fgets(nomeRemover, sizeof(nomeRemover), stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                    for (i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1]; // Move os itens
                            }
                            totalItens--;
                            encontrado = 1;
                            printf("\nItem removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\nItem não encontrado na mochila.\n");
                    }
                } else {
                    printf("\nA mochila está vazia.\n");
                }
                break;

            case 3:
                // Listar todos os itens
                if (totalItens > 0) {
                    printf("\n======= ITENS NA MOCHILA =======\n");
                    printf("%-20s %-20s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("---------------------------------------------\n");

                    for (i = 0; i < totalItens; i++) {
                        printf("%-20s %-20s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                } else {
                    printf("\nA mochila está vazia!\n");
                }
                break;

            case 4:
                // Buscar item pelo nome (nova função do nível Aventureiro)
                if (totalItens > 0) {
                    char nomeBusca[50];
                    int encontrado = 0;

                    printf("\nDigite o nome do item a buscar: ");
                    fgets(nomeBusca, sizeof(nomeBusca), stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                    for (i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            printf("\nItem encontrado!\n");
                            printf("Nome: %s\n", mochila[i].nome);
                            printf("Tipo: %s\n", mochila[i].tipo);
                            printf("Quantidade: %d\n", mochila[i].quantidade);
                            encontrado = 1;
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\nItem não encontrado na mochila. Tente outro nome!\n");
                    }
                } else {
                    printf("\nA mochila está vazia!\n");
                }
                break;

            case 5:
                printf("\nSaindo do programa... Até a próxima aventura!\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 5); // O programa continua até o jogador escolher sair

    return 0;
}
