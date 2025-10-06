#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item do inventário
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int contador = 0;
    int opcao;

    do {
        printf("\n===== CODIGO DA ILHA - NIVEL NOVATO =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer do teclado

        switch (opcao) {
            case 1: {
                if (contador >= MAX_ITENS) {
                    printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
                    break;
                }
                printf("\n--- Adicionar Item ---\n");
                printf("Nome: ");
                fgets(mochila[contador].nome, sizeof(mochila[contador].nome), stdin);
                mochila[contador].nome[strcspn(mochila[contador].nome, "\n")] = '\0'; // remover \n

                printf("Tipo: ");
                fgets(mochila[contador].tipo, sizeof(mochila[contador].tipo), stdin);
                mochila[contador].tipo[strcspn(mochila[contador].tipo, "\n")] = '\0';

                printf("Quantidade: ");
                scanf("%d", &mochila[contador].quantidade);
                getchar();

                contador++;
                printf("Item adicionado com sucesso!\n");
                break;
            }

            case 2: {
                if (contador == 0) {
                    printf("\nNenhum item na mochila para remover.\n");
                    break;
                }

                char nomeRemover[50];
                printf("\n--- Remover Item ---\n");
                printf("Digite o nome do item que deseja remover: ");
                fgets(nomeRemover, sizeof(nomeRemover), stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                int encontrado = -1;
                for (int i = 0; i < contador; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        encontrado = i;
                        break;
                    }
                }

                if (encontrado != -1) {
                    // Desloca os itens seguintes para preencher o espaço
                    for (int i = encontrado; i < contador - 1; i++) {
                        mochila[i] = mochila[i + 1];
                    }
                    contador--;
                    printf("Item '%s' removido com sucesso!\n", nomeRemover);
                } else {
                    printf("Item '%s' não encontrado.\n", nomeRemover);
                }
                break;
            }

            case 3: {
                printf("\n--- Itens da Mochila ---\n");
                if (contador == 0) {
                    printf("Mochila vazia.\n");
                } else {
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("-----------------------------------------------\n");
                    for (int i = 0; i < contador; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;
            }

            case 4:
                printf("\nSaindo do sistema... Boa sorte na ilha!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
