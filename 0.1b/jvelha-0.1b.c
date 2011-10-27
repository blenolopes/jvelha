/*
 * Jogo da Velha
 * ^^^^^^^^^^^^^
 * versão: 0.1b
 *
 * Bleno Vinicius
 * blenolopes@gmail.com
 * http://www.blenolopes.com
 *
 * -[ info ]-
 * Simples jogo da velha!
 *
 * -[ arquivos ]-
 * jvelha-0.1b.c : ô jogo!
 * jvelha-0.1b.h : header com funções, definições
 *                 e demais informações...
 *
 */
 
//
// includes...
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jvelha-0.1b.h"

//
// int main(void);
// ^^^^^^^^^^^^^^^
// Função principal :P
//

int main(void) {
    menu();
    
    inicializa_matriz();
    imprime_matriz();
    
    printf("\n");    
    return 0;
}

//
// _EOF_
//
