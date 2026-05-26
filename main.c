#include <stdio.h>
#include <stdlib.h>

// ============================================================
//  ESTRUTURA
// ============================================================

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// ============================================================
//  FUNÇÕES
// ============================================================

No* criar_no(int dado) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->dado = dado;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int dado) {
    if (raiz == NULL)
        return criar_no(dado);

    if (dado < raiz->dado)
        raiz->esquerda = inserir(raiz->esquerda, dado);
    else if (dado > raiz->dado)
        raiz->direita = inserir(raiz->direita, dado);
    else
        printf("Aviso: valor %d já existe (duplicatas ignoradas).\n", dado);

    return raiz;
}

No* buscar(No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado)
        return raiz;

    if (dado < raiz->dado)
        return buscar(raiz->esquerda, dado);
    else
        return buscar(raiz->direita, dado);
}

No* minimo(No* raiz) {
    while (raiz && raiz->esquerda)
        raiz = raiz->esquerda;
    return raiz;
}

No* remover(No* raiz, int dado) {
    if (raiz == NULL) {
        printf("Aviso: valor %d não encontrado.\n", dado);
        return NULL;
    }

    if (dado < raiz->dado) {
        raiz->esquerda = remover(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = remover(raiz->direita, dado);
    } else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        } else if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        } else {
            No* sucessor = minimo(raiz->direita);
            raiz->dado = sucessor->dado;
            raiz->direita = remover(raiz->direita, sucessor->dado);
        }
    }

    return raiz;
}

void pre_ordem(No* raiz) {
    if (!raiz) return;
    printf("%d ", raiz->dado);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void em_ordem(No* raiz) {
    if (!raiz) return;
    em_ordem(raiz->esquerda);
    printf("%d ", raiz->dado);
    em_ordem(raiz->direita);
}

void pos_ordem(No* raiz) {
    if (!raiz) return;
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d ", raiz->dado);
}

int altura(No* raiz) {
    if (!raiz) return -1;
    int h_esq = altura(raiz->esquerda);
    int h_dir = altura(raiz->direita);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

int contar_nos(No* raiz) {
    if (!raiz) return 0;
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

void liberar_arvore(No* raiz) {
    if (!raiz) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

// ============================================================
//  MAIN
// ============================================================

void separador(const char* titulo) {
    printf("\n========================================\n");
    printf("  %s\n", titulo);
    printf("========================================\n");
}

int main(void) {
    No* raiz = NULL;

    // --- Inserção ---
    separador("INSERINDO VALORES");
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
        printf("Inserido: %d\n", valores[i]);
    }

    /*
     * Árvore resultante:
     *
     *         50
     *        /  \
     *      30    70
     *     / \   / \
     *   20  40 60  80
     */

    // --- Percursos ---
    separador("PERCURSOS");
    printf("Pré-Ordem  (raiz→esq→dir): "); pre_ordem(raiz);  printf("\n");
    printf("Em-Ordem   (esq→raiz→dir): "); em_ordem(raiz);   printf("\n");
    printf("Pós-Ordem  (esq→dir→raiz): "); pos_ordem(raiz);  printf("\n");

    // --- Informações ---
    separador("INFORMAÇÕES DA ÁRVORE");
    printf("Altura    : %d\n", altura(raiz));
    printf("Total nós : %d\n", contar_nos(raiz));

    // --- Busca ---
    separador("BUSCA");
    int val = 40;
    printf("Buscando %d: %s\n", val, buscar(raiz, val) ? "Encontrado" : "Não encontrado");
    val = 99;
    printf("Buscando %d: %s\n", val, buscar(raiz, val) ? "Encontrado" : "Não encontrado");

    // --- Remoção ---
    separador("REMOÇÃO");
    printf("Removendo 20 (folha)...          ");
    raiz = remover(raiz, 20); em_ordem(raiz); printf("\n");

    printf("Removendo 30 (um filho)...       ");
    raiz = remover(raiz, 30); em_ordem(raiz); printf("\n");

    printf("Removendo 50 (dois filhos)...    ");
    raiz = remover(raiz, 50); em_ordem(raiz); printf("\n");

    // --- Limpeza ---
    separador("LIBERANDO MEMÓRIA");
    liberar_arvore(raiz);
    raiz = NULL;
    printf("Memória liberada com sucesso.\n\n");

    return 0;
}