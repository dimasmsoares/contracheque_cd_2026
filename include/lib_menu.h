// lib_menu.h
#ifndef LIB_MENU_H
#define LIB_MENU_H

// Cores disponíveis para o usuário
typedef enum {
    COR_PRETA,
    COR_VERMELHA,
    COR_VERDE,
    COR_AMARELA,
    COR_AZUL,
    COR_MAGENTA,
    COR_CIANO,
    COR_BRANCA,
    COR_PADRAO // Cor original do terminal
} Cor;

typedef struct Menu Menu;   // Permite usar Menu * antes da definição completa

typedef struct {    
    void (*exibir_menu)(Menu *self);
} MenuVTable;

typedef struct Menu{
    // VTABLE
    const MenuVTable *vtable;

    // ATRIBUTOS
    char *titulo;
    char *comando;

    int n_opcoes;            // Tamanho do array
    int n_opcao_selecionada; // Índice atual
    int n_max_opcoes;        // Tamanho do array
    char **opcoes;           // Ponteiro para ponteiro (Array de strings)

    int n_botoes;            // Tamanho do array
    char **botoes;           // Ponteiro para ponteiro (Array de strings)
    
    // Cores do TITULO (onde está o cursor)
    Cor cor_texto_titulo;
    Cor cor_fundo_titulo;

    // Cores do item SELECIONADO (onde está o cursor)
    Cor cor_texto_sel;
    Cor cor_fundo_sel;

    // Cores dos itens NÃO selecionados (normal)
    Cor cor_texto_norm;
    Cor cor_fundo_norm;
} Menu;

// CONSTRUTOR
void menu_init(Menu *obj, int a1, float a2) {
    obj->vtable = &CLASSE_VTABLE;
    obj->atributo1 = a1;
    obj->atributo2 = a2;
}

/*
typedef struct {
    int n_opcoes;            // Tamanho do array
    int n_opcao_selecionada; // Índice atual
    char **opcoes;           // Ponteiro para ponteiro (Array de strings)
    char *titulo;
    char *comando;

    // Cores do TITULO (onde está o cursor)
    Cor cor_texto_titulo;
    Cor cor_fundo_titulo;

    // Cores do item SELECIONADO (onde está o cursor)
    Cor cor_texto_sel;
    Cor cor_fundo_sel;

    // Cores dos itens NÃO selecionados (normal)
    Cor cor_texto_norm;
    Cor cor_fundo_norm;
} MenuSimple;

typedef struct {
    int n_opcoes;               // Tamanho do array
    char *selecoes;
    char **opcoes;              // Ponteiro para ponteiro (Array de strings)
    char *titulo;
    char *comando;

    // Cores do TITULO (onde está o cursor)
    Cor cor_texto_titulo;
    Cor cor_fundo_titulo;

    // Cores do item SELECIONADO (onde está o cursor)
    Cor cor_texto_sel;
    Cor cor_fundo_sel;

    // Cores dos itens NÃO selecionados (normal)
    Cor cor_texto_norm;
    Cor cor_fundo_norm;
} MenuMulti;

void menu_simple(MenuSimple *menu);

void menu_multi(MenuMulti *menu);

int get_key_press();

Menu *init_menu()
*/

#endif