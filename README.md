# Sistema de Inventário - Free Fire Novato

## Descrição
Este programa simula um sistema de inventário para o jogo Free Fire, permitindo que os jogadores gerenciem sua mochila de loot inicial. O sistema foi desenvolvido em C utilizando estruturas de dados compostas (structs) e listas sequenciais.

## Funcionalidades Implementadas

### ✅ Requisitos Funcionais
- **Struct Item**: Estrutura com campos nome[30], tipo[20] e quantidade (int)
- **Cadastro de Itens**: Sistema permite cadastrar até 10 itens com nome, tipo e quantidade
- **Remoção de Itens**: Exclusão de itens da mochila informando o nome
- **Listagem Completa**: Exibição de todos os itens cadastrados após cada operação
- **Busca Sequencial**: Localização de itens na mochila por nome

### ✅ Requisitos Não Funcionais
- **Usabilidade**: Interface clara com mensagens orientativas
- **Performance**: Resposta rápida a comandos (< 2 segundos)
- **Documentação**: Código comentado explicando structs, funções e fluxo
- **Manutenibilidade**: Nomes de variáveis e funções claros e descritivos

## Estrutura do Programa

### Bibliotecas Utilizadas
```c
#include <stdio.h>    // Entrada e saída de dados
#include <string.h>   // Manipulação de strings
#include <stdlib.h>   // Funções gerais do sistema
```

### Struct Principal
```c
typedef struct {
    char nome[30];      // Nome do item
    char tipo[20];      // Categoria do item
    int quantidade;     // Quantidade disponível
} Item;
```

### Funções Implementadas
- `inserirItem()` - Cadastra novos itens na mochila
- `removerItem()` - Remove itens da mochila por nome
- `listarItens()` - Exibe todos os itens cadastrados
- `buscarItem()` - Busca sequencial por nome de item
- `exibirMenu()` - Mostra o menu principal
- `limparBuffer()` - Função auxiliar para limpeza de buffer

## Como Usar

### Compilação
```bash
gcc -o inventario_freefire inventario_freefire.c
```

### Execução
```bash
./inventario_freefire
```

## Exemplos de Uso

### 1. Cadastrar Item
```
Escolha: 1
Nome do item: AK47
Tipo: arma
Quantidade: 1
```

### 2. Cadastrar Munição
```
Escolha: 1
Nome do item: Balas 7.62
Tipo: municao
Quantidade: 120
```

### 3. Cadastrar Kit Médico
```
Escolha: 1
Nome do item: Kit Medico
Tipo: cura
Quantidade: 3
```

### 4. Buscar Item
```
Escolha: 4
Nome para buscar: AK47
```

### 5. Remover Item
```
Escolha: 2
Nome para remover: Balas 7.62
```

## Tipos de Itens Sugeridos

### Armas
- AK47, M4A1, AWM, MP40, Groza

### Munição
- Balas 5.56, Balas 7.62, Balas .45

### Cura
- Kit Medico, Bandagem, Inibidor

### Ferramentas
- Granada, Smoke, Gloo Wall

## Limitações
- Capacidade máxima: 10 itens
- Nome do item: até 29 caracteres
- Tipo do item: até 19 caracteres
- Quantidade: números inteiros positivos

## Estrutura de Dados Utilizada
- **Vetor sequencial**: Para armazenar os itens da mochila
- **Busca sequencial**: Algoritmo O(n) para localizar itens
- **Remoção com deslocamento**: Mantém a estrutura sequencial

## Fluxo de Execução
1. Inicialização do sistema
2. Exibição do menu principal
3. Leitura da opção do usuário
4. Execução da função correspondente
5. Atualização e exibição do inventário
6. Retorno ao menu (até sair)

## Considerações Técnicas
- Uso de `fgets()` para leitura segura de strings
- Validação de entrada para quantidades positivas
- Limpeza de buffer para evitar problemas de entrada
- Tratamento de casos especiais (mochila vazia/cheia)

## Autor
Sistema de Inventário FF - Estruturas de Dados
Novembro 2025