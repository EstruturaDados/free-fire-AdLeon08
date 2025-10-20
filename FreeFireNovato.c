/*
====================================================================
    DESAFIO: Código da Ilha – Edição Free Fire - NÍVEL NOVATO
    Aluno: Aderlon Barbosa Pessoa
    Matéria: Estrutura de Dados
    Descrição:
        Este programa simula um sistema de mochila virtual de sobrevivência
        em uma ilha misteriosa. O usuário pode adicionar, remover e listar
        itens dentro de uma mochila com capacidade limitada a 10 itens.
        O objetivo é praticar o uso de estruturas (structs), vetores e
        controle de fluxo com menus e laços de repetição.
====================================================================
*/

#include <stdio.h>
#include <string.h>

// -------------------------------------------------------------------
// Estrutura que representa um item da mochila
// Cada item tem um nome, um tipo e uma quantidade
// -------------------------------------------------------------------
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

int main() {

    // -------------------------------------------------------------------
    // Declaração das variáveis principais do programa
    // -------------------------------------------------------------------
    struct Item mochila[10];   // Vetor estático que guarda até 10 itens
    int totalItens = 0;        // Conta quantos itens estão atualmente na mochila
    int opcao;                 // Guarda a escolha do usuário no menu
    char nomeRemover[30];      // Usada para armazenar o nome do item a ser removido

    // -------------------------------------------------------------------
    // Estrutura de repetição para manter o programa rodando até o usuário sair
    // O "do...while" garante que o menu apareça pelo menos uma vez
    // -------------------------------------------------------------------
    do {
        // Menu interativo
        printf("\n==============================\n");
        printf(" DESAFIO CÓDIGO DA ILHA - NIVEL NOVATO\n");
        printf("==============================\n");
        printf("1. Adicionar item à mochila\n");
        printf("2. Remover item da mochila\n");
        printf("3. Listar itens cadastrados\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer do teclado (evita problemas com fgets depois do scanf)

        switch(opcao) {

            // ---------------------------------------------------------------
            // OPÇÃO 1: Adicionar item à mochila
            // ---------------------------------------------------------------
            case 1:
                if (totalItens < 10) { // Verifica se ainda há espaço na mochila
                    printf("\n--- Adicionar novo item ---\n");

                    // Lê o nome do item
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, 30, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0'; // remove o '\n'

                    // Lê o tipo do item
                    printf("Tipo do item: ");
                    fgets(mochila[totalItens].tipo, 20, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0'; // remove o '\n'

                    // Lê a quantidade
                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    getchar(); // limpa o buffer

                    totalItens++; // Incrementa o número de itens cadastrados
                    printf("\nItem adicionado com sucesso!\n");

                } else {
                    // Caso o limite de 10 itens seja atingido
                    printf("\nA mochila está cheia! (Limite de 10 itens)\n");
                }
                break;

            // ---------------------------------------------------------------
            // OPÇÃO 2: Remover item da mochila
            // ---------------------------------------------------------------
            case 2:
                if (totalItens > 0) {
                    printf("\n--- Remover item ---\n");
                    printf("Digite o nome do item que deseja remover: ");
                    fgets(nomeRemover, 30, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0'; // remove o '\n'

                    int encontrado = 0; // flag para saber se o item foi encontrado

                    // Percorre todos os itens da mochila
                    for (int i = 0; i < totalItens; i++) {
                        // Compara o nome digitado com o nome dos itens da mochila
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            // Se encontrou, move os itens seguintes uma posição para trás
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            totalItens--; // Diminui a quantidade total
                            encontrado = 1; // Marca que o item foi encontrado
                            printf("\nItem removido com sucesso!\n");
                            break;
                        }
                    }

                    // Caso não encontre o item
                    if (!encontrado) {
                        printf("\nItem não encontrado na mochila!\n");
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
                    printf("\n--- Itens atuais na mochila ---\n");
                    printf("%-20s %-15s %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                    printf("-----------------------------------------------\n");

                    // Mostra todos os itens um por um
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
            // OPÇÃO 4: Sair do programa
            // ---------------------------------------------------------------
            case 4:
                printf("\nSaindo do sistema... Boa sorte na ilha, sobrevivente!\n");
                break;

            // ---------------------------------------------------------------
            // OPÇÃO INVÁLIDA: Caso o usuário digite algo fora de 1 a 4
            // ---------------------------------------------------------------
            default:
                printf("\nOpção inválida! Por favor, tente novamente.\n");
        }

    } while (opcao != 4); // O menu continua até o usuário escolher "Sair"

    // Mensagem final para reforçar encerramento
    printf("\nPrograma encerrado. Inventário salvo na memória temporária.\n");

    return 0; // Indica que o programa terminou sem erros
}

