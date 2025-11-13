/*
 * Sistema de Inventário - Free Fire Novato
 * 
 * Este programa simula a mochila de loot inicial de um jogador no Free Fire.
 * Permite gerenciar itens essenciais como armas, munições, kits médicos e ferramentas.
 * 
 * Autor: Sistema de Inventário FF
 * Data: Novembro 2025
 * Curso: Análise de Sistemas - Estruturas de Dados
 */

#include <stdio.h>    // Para funções de entrada e saída
#include <string.h>   // Para manipulação de strings
#include <stdlib.h>   // Para funções gerais do sistema

#define MAX_ITENS 10  // Capacidade máxima da mochila

/*
 * Estrutura Item - Representa um item do inventário
 * 
 * Campos:
 * - nome[30]: Nome do item (ex: "AK47", "Kit Médico")
 * - tipo[20]: Categoria do item (ex: "arma", "munição", "cura")
 * - quantidade: Número de unidades deste item
 */
typedef struct {
    char nome[30];      // Nome do item
    char tipo[20];      // Tipo/categoria do item
    int quantidade;     // Quantidade disponível
} Item;

// Variáveis globais para o inventário
Item mochila[MAX_ITENS];  // Vetor que representa a mochila
int totalItens = 0;       // Contador de itens atualmente na mochila

/*
 * Protótipos das funções
 */
void inserirItem();
void removerItem();
void listarItens();
void buscarItem();
void exibirMenu();
void limparBuffer();

/*
 * Função principal - Controla o fluxo do programa
 */
int main() {
    int opcao;
    
    printf("=================================================\n");
    printf("    SISTEMA DE INVENTARIO - FREE FIRE NOVATO    \n");
    printf("=================================================\n");
    printf("Bem-vindo ao sistema de gerenciamento da sua mochila!\n");
    printf("Colete e organize seus itens para sobreviver!\n\n");
    
    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();  // Limpa o buffer de entrada
        
        printf("\n");
        
        switch(opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 5:
                printf("Saindo do jogo... Boa sorte na batalha!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
        printf("\n");
        
    } while(opcao != 5);
    
    return 0;
}

/*
 * Exibe o menu principal do sistema
 */
void exibirMenu() {
    printf("=================================================\n");
    printf("                 MENU PRINCIPAL                 \n");
    printf("=================================================\n");
    printf("1. Cadastrar item na mochila\n");
    printf("2. Remover item da mochila\n");
    printf("3. Listar todos os itens\n");
    printf("4. Buscar item especifico\n");
    printf("5. Sair do jogo\n");
    printf("=================================================\n");
    printf("Itens na mochila: %d/%d\n", totalItens, MAX_ITENS);
    printf("=================================================\n");
}

/*
 * Função para inserir um novo item na mochila
 * Verifica se há espaço disponível antes de adicionar
 */
void inserirItem() {
    // Verifica se a mochila está cheia
    if(totalItens >= MAX_ITENS) {
        printf("MOCHILA CHEIA! Voce precisa remover alguns itens primeiro.\n");
        printf("Capacidade maxima: %d itens\n", MAX_ITENS);
        return;
    }
    
    printf("=== CADASTRAR NOVO ITEM ===\n");
    
    // Lê o nome do item
    printf("Digite o nome do item: ");
    fgets(mochila[totalItens].nome, sizeof(mochila[totalItens].nome), stdin);
    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0; // Remove quebra de linha
    
    // Lê o tipo do item
    printf("Digite o tipo do item (arma/municao/cura/ferramenta): ");
    fgets(mochila[totalItens].tipo, sizeof(mochila[totalItens].tipo), stdin);
    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = 0; // Remove quebra de linha
    
    // Lê a quantidade
    printf("Digite a quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);
    limparBuffer();
    
    // Valida se a quantidade é positiva
    if(mochila[totalItens].quantidade <= 0) {
        printf("Quantidade deve ser maior que zero!\n");
        return;
    }
    
    totalItens++; // Incrementa o contador de itens
    
    printf("\nItem '%s' cadastrado com sucesso!\n", mochila[totalItens-1].nome);
    printf("Tipo: %s | Quantidade: %d\n", mochila[totalItens-1].tipo, mochila[totalItens-1].quantidade);
    
    // Lista os itens após a inserção
    printf("\n=== INVENTARIO ATUALIZADO ===\n");
    listarItens();
}

/*
 * Função para remover um item da mochila
 * Utiliza busca sequencial para localizar o item pelo nome
 */
void removerItem() {
    if(totalItens == 0) {
        printf("MOCHILA VAZIA! Nao ha itens para remover.\n");
        return;
    }
    
    char nomeItem[30];
    int encontrado = 0;
    int indice = -1;
    
    printf("=== REMOVER ITEM ===\n");
    printf("Digite o nome do item que deseja remover: ");
    fgets(nomeItem, sizeof(nomeItem), stdin);
    nomeItem[strcspn(nomeItem, "\n")] = 0; // Remove quebra de linha
    
    // Busca sequencial pelo item
    for(int i = 0; i < totalItens; i++) {
        if(strcmp(mochila[i].nome, nomeItem) == 0) {
            encontrado = 1;
            indice = i;
            break;
        }
    }
    
    if(encontrado) {
        printf("\nItem encontrado: %s (%s) - Quantidade: %d\n", 
               mochila[indice].nome, mochila[indice].tipo, mochila[indice].quantidade);
        
        // Move todos os elementos posteriores uma posição para frente
        for(int i = indice; i < totalItens - 1; i++) {
            mochila[i] = mochila[i + 1];
        }
        
        totalItens--; // Decrementa o contador
        printf("Item '%s' removido com sucesso!\n", nomeItem);
        
        // Lista os itens após a remoção
        printf("\n=== INVENTARIO ATUALIZADO ===\n");
        listarItens();
    } else {
        printf("Item '%s' nao encontrado na mochila.\n", nomeItem);
        printf("Verifique se o nome esta correto e tente novamente.\n");
    }
}

/*
 * Função para listar todos os itens da mochila
 * Exibe informações completas de cada item cadastrado
 */
void listarItens() {
    if(totalItens == 0) {
        printf("MOCHILA VAZIA! Nenhum item cadastrado.\n");
        printf("Colete alguns itens para começar sua jornada!\n");
        return;
    }
    
    printf("=== ITENS NA MOCHILA ===\n");
    printf("Total de itens: %d/%d\n", totalItens, MAX_ITENS);
    printf("----------------------------------------\n");
    
    for(int i = 0; i < totalItens; i++) {
        printf("%d. %s\n", i + 1, mochila[i].nome);
        printf("   Tipo: %s\n", mochila[i].tipo);
        printf("   Quantidade: %d\n", mochila[i].quantidade);
        printf("----------------------------------------\n");
    }
}

/*
 * Função de busca sequencial
 * Localiza um item específico pelo nome e exibe suas informações
 */
void buscarItem() {
    if(totalItens == 0) {
        printf("MOCHILA VAZIA! Nao ha itens para buscar.\n");
        return;
    }
    
    char nomeItem[30];
    int encontrado = 0;
    
    printf("=== BUSCAR ITEM ===\n");
    printf("Digite o nome do item que deseja buscar: ");
    fgets(nomeItem, sizeof(nomeItem), stdin);
    nomeItem[strcspn(nomeItem, "\n")] = 0; // Remove quebra de linha
    
    printf("\nRealizando busca sequencial...\n");
    
    // Busca sequencial no vetor de itens
    for(int i = 0; i < totalItens; i++) {
        if(strcmp(mochila[i].nome, nomeItem) == 0) {
            encontrado = 1;
            printf("\n=== ITEM ENCONTRADO ===\n");
            printf("Posicao na mochila: %d\n", i + 1);
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("======================\n");
            break;
        }
    }
    
    if(!encontrado) {
        printf("Item '%s' nao encontrado na mochila.\n", nomeItem);
        printf("Verifique se o nome esta correto.\n");
        printf("\nItens disponiveis na mochila:\n");
        for(int i = 0; i < totalItens; i++) {
            printf("- %s\n", mochila[i].nome);
        }
    }
}

/*
 * Função auxiliar para limpar o buffer de entrada
 * Previne problemas na leitura de dados
 */
void limparBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}