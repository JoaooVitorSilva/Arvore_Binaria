# 🌳 Árvore Binária de Busca em C

Implementação de uma **Árvore Binária de Busca (BST — Binary Search Tree)** em linguagem C, com menu interativo pelo terminal para inserção, remoção, busca e percursos.

---

## 📁 Estrutura do Projeto

```
📄 arvore_binaria.c   — único arquivo com toda a implementação
```

---

## 🧠 Como funciona uma BST?

Uma Árvore Binária de Busca organiza os dados seguindo uma regra simples:

```
         50
        /  \
      30    70
     / \   / \
   20  40 60  80
```

- Valores **menores** que o nó pai vão para a **esquerda**
- Valores **maiores** que o nó pai vão para a **direita**
- Duplicatas são ignoradas
- Busca eficiente: **O(log n)** no caso médio

---

## ⚙️ Funcionalidades

| Função           | Descrição                                              |
|------------------|--------------------------------------------------------|
| `inserir`        | Insere um valor respeitando a propriedade BST          |
| `buscar`         | Busca um valor e retorna o nó ou NULL                  |
| `remover`        | Remove um nó tratando os 3 casos possíveis             |
| `minimo`         | Retorna o nó com o menor valor da subárvore            |
| `pre_ordem`      | Percurso: raiz → esquerda → direita                    |
| `em_ordem`       | Percurso: esquerda → raiz → direita *(saída ordenada)* |
| `pos_ordem`      | Percurso: esquerda → direita → raiz                    |
| `altura`         | Calcula a altura da árvore                             |
| `contar_nos`     | Conta o total de nós                                   |
| `liberar_arvore` | Libera toda a memória alocada                          |

---

## 🗑️ Casos de Remoção

| Caso          | Exemplo      | Solução                                               |
|---------------|--------------|-------------------------------------------------------|
| Nó folha      | Remover 20   | Remove diretamente                                    |
| Um filho      | Remover 30   | Substitui pelo filho existente                        |
| Dois filhos   | Remover 50   | Substitui pelo sucessor in-ordem (mínimo da subárvore direita) |

---

## 🖥️ Menu Interativo

Ao executar o programa, o usuário opera a árvore por um menu no terminal:

```
========================================
   ÁRVORE BINÁRIA DE BUSCA (BST)
========================================

--- MENU ---
1. Inserir valor
2. Remover valor
3. Buscar valor
4. Exibir percursos
5. Informações da árvore
0. Sair
Escolha:
```

---

## 🚀 Como Compilar e Executar

### Terminal (GCC)
```bash
gcc arvore_binaria.c -o arvore_binaria
./arvore_binaria
```

### Visual Studio
1. Crie um novo projeto **Console App** vazio
2. Adicione `arvore_binaria.c` ao projeto
3. Pressione **F5** para compilar e executar

---

## 👨‍💻 Autor

Feito para a disciplina de Estruturas de Dados.
