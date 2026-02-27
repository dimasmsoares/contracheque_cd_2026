#include <stdio.h>
#include <stdlib.h>
#include "lib_menu.h"

int main(void){

    char *opcoes[] ={"Simular contracheque mensal", "Simular ganhos anuais"};

    MenuSimple m = {
        .titulo = "CONTRACHEQUE DA CÂMARA",
        .n_opcoes = 2,
        .opcoes = opcoes,
        .comando = "Selecione uma opção",
        
        // Cores do TITULO (onde está o cursor)
        .cor_texto_titulo = COR_PRETA,
        .cor_fundo_titulo = COR_PADRAO,

        // Cores do item SELECIONADO (onde está o cursor)
        .cor_texto_sel = COR_VERMELHA,
        .cor_fundo_sel = COR_PADRAO,

        // Cores dos itens NÃO selecionados (normal)
        .cor_texto_norm = COR_PRETA,
        .cor_fundo_norm = COR_PADRAO
    };

    menu_simple(&m);
    
    return 0;
}