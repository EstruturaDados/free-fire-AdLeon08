/*
====================================================================
DESAFIO Código da Ilha – Edição Free Fire - NÍVEL MESTRE
Aluno: Aderlon Barbosa Pessoa
Matéria: Estrutura de Dados
Descrição:
Neste nível, a mochila virtual é aprimorada com um campo de 
prioridade (1 a 5) para cada item. É possível ordenar a mochila 
por nome, tipo ou prioridade usando Insertion Sort e realizar 
busca binária por nome. O programa também conta comparações 
para análise de desempenho, demonstrando conceitos avançados 
de manipulação de arrays e controle lógico.
====================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Necessário para o tipo bool

#define MAX_ITENS 10

// -------------------------------------------------------------------
// Enumeração para critérios de ordenação
// -------------------------------------------------------------------
enum Critério {
    POR_NOME = 1,
    POR_TIPO,
    POR_PRIORIDADE
};

// -------------------------------------------------------------------
// Estrutura que representa um item da mochila
// -------------------------------------------------------------------
struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade; // 1 a 5
};

// -------------------------------------------------------------------
// Protótipos de funções
// -------------------------------------------------------------------
void adicionarItem(struct Item mochila[], int *totalItens);
void removerItem(struct Item mochila[], int *totalItens);
void listarItens(struct Item mochila[], int totalItens);
void ordenarMochila(struct Item mochila[], int totalItens, enum Critério criterio);
int buscarBinaria(struct Item mochila[], int totalItens, char nomeBusca[]);

int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n===== MOCHILA DO SOBREVIVENTE - NÍVEL MESTRE =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Ordenar mochila\n");
        printf("5. Buscar item por nome (busca binária)\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                adicionarItem(mochila, &totalItens);
                break;
            case 2:
                removerItem(mochila, &totalItens);
                break;
            case 3:
                listarItens(mochila, totalItens);
                break;
            case 4: {
                int crit;
                printf("\nEscolha o critério de ordenação:\n");
                printf("1 - Nome\n2 - Tipo\n3 - Prioridade\n");
                printf("Digite: ");
                scanf("%d", &crit);
                getchar();
                if(crit>=1 && crit<=3)
                    ordenarMochila(mochila, totalItens, (enum Critério)crit);
                else
                    printf("Critério inválido!\n");
                break;
            }
            case 5: {
                char nomeBusca[50];
                printf("\nDigite o nome do item a buscar: ");
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                int idx = buscarBinaria(mochila, totalItens, nomeBusca);
                if(idx != -1) {
                    printf("\nItem encontrado!\n");
                    printf("Nome: %s\nTipo: %s\nQuantidade: %d\nPrioridade: %d\n",
                           mochila[idx].nome,
                           mochila[idx].tipo,
                           mochila[idx].quantidade,
                           mochila[idx].prioridade);
                } else {
                    printf("\nItem não encontrado ou mochila não está ordenada por nome.\n");
                }
                break;
            }
            case 6:
                printf("\nSaindo do programa... Boa sorte na ilha!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while(opcao !=6);

    return 0;
}

// -------------------------------------------------------------------
// Função para adicionar item
// -------------------------------------------------------------------
void adicionarItem(struct Item mochila[], int *totalItens){
    if(*totalItens < MAX_ITENS) {
        printf("\nDigite o nome do item: ");
        fgets(mochila[*totalItens].nome, sizeof(mochila[*totalItens].nome), stdin);
        mochila[*totalItens].nome[strcspn(mochila[*totalItens].nome, "\n")] = '\0';

        printf("Digite o tipo do item: ");
        fgets(mochila[*totalItens].tipo, sizeof(mochila[*totalItens].tipo), stdin);
        mochila[*totalItens].tipo[strcspn(mochila[*totalItens].tipo, "\n")] = '\0';

        printf("Digite a quantidade: ");
        scanf("%d", &mochila[*totalItens].quantidade);

        printf("Digite a prioridade (1 a 5): ");
        scanf("%d", &mochila[*totalItens].prioridade);
        getchar();

        (*totalItens)++;
        printf("\nItem adicionado com sucesso!\n");
    } else {
        printf("\nMochila cheia!\n");
    }
}

// -------------------------------------------------------------------
// Função para remover item pelo nome
// -------------------------------------------------------------------
void removerItem(struct Item mochila[], int *totalItens){
    if(*totalItens > 0){
        char nomeRemover[50];
        int encontrado = 0;
        printf("\nDigite o nome do item a remover: ");
        fgets(nomeRemover, sizeof(nomeRemover), stdin);
        nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

        for(int i=0; i<*totalItens; i++){
            if(strcmp(mochila[i].nome, nomeRemover)==0){
                for(int j=i;j<*totalItens-1;j++){
                    mochila[j]=mochila[j+1];
                }
                (*totalItens)--;
                encontrado=1;
                printf("\nItem removido com sucesso!\n");
                break;
            }
        }
        if(!encontrado) printf("\nItem não encontrado!\n");
    } else {
        printf("\nMochila vazia!\n");
    }
}

// -------------------------------------------------------------------
// Função para listar todos os itens
// -------------------------------------------------------------------
void listarItens(struct Item mochila[], int totalItens){
    if(totalItens>0){
        printf("\n%-20s %-20s %-10s %-10s\n", "Nome","Tipo","Quantidade","Prioridade");
        printf("-------------------------------------------------------------\n");
        for(int i=0;i<totalItens;i++){
            printf("%-20s %-20s %-10d %-10d\n",
                   mochila[i].nome,
                   mochila[i].tipo,
                   mochila[i].quantidade,
                   mochila[i].prioridade);
        }
    } else {
        printf("\nMochila vazia!\n");
    }
}

// -------------------------------------------------------------------
// Função para ordenar a mochila (Insertion Sort) por critério
// -------------------------------------------------------------------
void ordenarMochila(struct Item mochila[], int totalItens, enum Critério criterio){
    int comparacoes =0; // contador de comparações
    for(int i=1;i<totalItens;i++){
        struct Item chave = mochila[i];
        int j=i-1;
        // Dependendo do critério, comparamos diferentes campos
        while(j>=0){
            bool troca=false;
            if(criterio==POR_NOME && strcmp(mochila[j].nome,chave.nome)>0) troca=true;
            else if(criterio==POR_TIPO && strcmp(mochila[j].tipo,chave.tipo)>0) troca=true;
            else if(criterio==POR_PRIORIDADE && mochila[j].prioridade>chave.prioridade) troca=true;

            comparacoes++;
            if(!troca) break;

            mochila[j+1]=mochila[j];
            j--;
        }
        mochila[j+1]=chave;
    }
    printf("\nMochila ordenada! Total de comparações realizadas: %d\n", comparacoes);
}

// -------------------------------------------------------------------
// Função de busca binária pelo nome
// -------------------------------------------------------------------
int buscarBinaria(struct Item mochila[], int totalItens, char nomeBusca[]){
    int esquerda=0, direita=totalItens-1;
    while(esquerda<=direita){
        int meio=(esquerda+direita)/2;
        int cmp=strcmp(mochila[meio].nome, nomeBusca);
        if(cmp==0) return meio;
        else if(cmp<0) esquerda=meio+1;
        else direita=meio-1;
    }
    return -1; // não encontrado
}
