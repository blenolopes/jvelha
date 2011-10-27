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
// defines...
//

#define VERSION     "v0.1 beta"
#define AUTOR       "Bleno Vinicius"
#define EMAIL       "blenolopes@gmail.com"
#define WWW         "http://www.blenolopes.com"
#define M_LIN       100                     // maximo de linhas...
#define M_COL       80                      // maximo de colunas...
#define PROMPT_LIN  40                      // linha limite do prompt...
#define PROMPT_COL  80                      // coluna limite do prompt...
#define TL          '='                     // tipo de linha nas telas...          

//
// variaveis globais...
//

char matriz[3][3];

//
// funções...
//

void limpa_tela();
void xy(int linha, int coluna);
void xys(int linha, int coluna, char *str);
void centraliza(char *str, int linha);
void linha(int limite, char tipo);
void tela_principal(void);
void sair(int error);
void sobre(void);
void inicializa_matriz(void);
void imprime_matriz(void);
void jogada_humano(void);
void jogada_computador(void);
char verifica_ganhador(void);
void jogada(void);
void njogo(void);
void menu(void);

//
// void limpa_tela(void);
// ^^^^^^^^^^^^^^^^^^^^^^
//

void limpa_tela(void) {
    system("clear");
}

//
// void xy(int linha, int coluna);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Posiciona o cursor nas coordenadas
// "linha" e "coluna"...
//

void xy(int linha, int coluna) {
    char s[M_LIN] = {0};
    
    sprintf(s, "\033[%d;%df", linha, coluna);
    printf("%s", s);
}

//
// void xys(int linha, int coluna, char *str);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// O mesmo que xy(int, int); mas imprime também "str"...
//

void xys(int linha, int coluna, char *str) {
    xy(linha, coluna);
    printf("%s", str);
}

//
// void centraliza(char *str, int linha); 
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Centraliza uma string (str) em "linha"...
//

void centraliza(char *str, int linha) {
    int pos;
    pos = (M_COL - strlen(str)) / 2;
    
    xy(linha, pos);
    printf("%s", str);   
}

//
// void linha(int linha, int limite, char tipo = '-');
// ^^^^^^^^^^^^^^^^^^^^^^^
// Imprime uma linha com o "limite" de caracteres,
// usando o "tipo" de caractere passado via parametro!
//

void linha(int limite, char tipo) {
    int i;
    
    for(i = 1; i <= limite; i++) {
        printf("%c", tipo);
    }
}

//
// void tela_principal(void);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^
// Imprime a tela principal...
//

void tela_principal(void) {
    int m_lin;  // tamanho da linha do prompt...
    int m_col;  // tamanho da coluna do prompt...
    
    m_lin = PROMPT_LIN;
    m_col = PROMPT_COL;

    limpa_tela();
    
    //
    // inicio do cabeçalho...
    //
    
    xy(1, 1);
    linha(m_col, TL);
    
    xy(2, 1);
    printf("*");
    
    centraliza("Jogo da Velha ::: " VERSION, 2);
    
    xy(2, m_col);
    printf("*");
    
    xy(3, 1);
    linha(m_col, TL);
    
    //
    // inicio do rodapé...
    //
    
    xy((m_lin - 2), 1);
    linha(m_col, TL);
    
    xy((m_lin - 1), 1);
    printf("*");
    
    centraliza(EMAIL " ::: " WWW, (m_lin - 1));
    
    xy((m_lin - 1), m_col);
    printf("*");
    
    xy(m_lin, 1);
    linha(m_col, TL);    
}

//
// void sair(int error);
// ^^^^^^^^^^^^^^^^^^^^^
// Sai do programa com o int do erro!
//

void sair(int error) {
    limpa_tela();
    
    xys(1, 1, "Jogo da Velha ::: " VERSION);
    
    xys(3, 1, "por  : " AUTOR);
    xys(4, 1, "mail : " EMAIL);
    xys(5, 1, "http : " WWW);
    
    xys(7, 1, ";)");
    printf("\n");
    
    exit(error);
}

//
// void sobre(void);
// ^^^^^^^^^^^^^^^^^
// Informações sobre o Jogo da Velha! :P
//

void sobre(void) {
    tela_principal();
    
    centraliza("ooooo Sobre o Jogo da Velha ooooo", 5);
    centraliza("ooooooooooooooooooooooooooooooooo", 6);
    
    xys(10, 5, "o| | ");
    xys(11, 5, "-----");
    xys(12, 5, " |o| ");
    xys(13, 5, "-----");
    xys(14, 5, " | |o");
    
    xys(16, 5, "Simples jogo da velha, desenvolvido em C.");
    xys(17, 5, "Compilador em gcc 4.2.4 no ubuntu 8.04.");
    
    xys(19, 5, "Este software é livre e tem cunho não comerciais. Pode ser");
    xys(20, 5, "modificado, estudado e distribuido livremente. Conservando o autor");
    xys(21, 5, "e demais \"coders\".");
    
    xys(23, 5, "por  : " AUTOR);
    xys(24, 5, "mail : " EMAIL);
    xys(25, 5, "http : " WWW);
    
    centraliza("pressione [enter]...", 35);
    
    // Gambiarra :P 
    int gambiarra;
    scanf("%c", &gambiarra);
    scanf("%c", &gambiarra);
}


//
// void inicializa_matriz(void);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Inicializa matriz com jogadas "vazias".
//

void inicializa_matriz(void) {
    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            matriz[i][j] = ' ';
        }
    }
}

//
// void imprime_matriz(void);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^
//

void imprime_matriz(void) {
    int i;
    int lin, col;
    
    lin = 10;
    col = 40;
    
    for(i = 0; i < 3; i++) {
        xy(lin, col);
        printf(" %c | %c | %c ", matriz[i][0], matriz[i][1], matriz[i][2]);
        if(i != 2) {
            xys((lin + 1), col, "---|---|---");
            ++lin;
        }
        ++lin;
    }
}

//
// void jogada_humano(void);
// ^^^^^^^^^^^^^^^^^^^^^^^^^
//

void jogada_humano(void) {
    int x, y;
    
    xys(20, 20, "Sua jogada [linha,coluna]: ");
    scanf("%d,%d", &x, &y);
    
    x--;
    y--;
    
    if(matriz[x][y] != ' ') {
        xys(22, 20, ">> Jogada inválida!");
        xys(23, 20, ">> Informe outra jogada...");
        imprime_matriz();
        jogada_humano();
    } else {
        matriz[x][y] = 'X';
    }
}

//
// void jogada_computador(void);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//

void jogada_computador(void) {
    int x, y;
    
    for(x = 0; x < 3; x++) {
        for(y = 0; y < 3; y++) {
            if(matriz[x][y] == ' ') break;
        }
        if(matriz[x][y] == ' ') break;
    }
    
    if((x * y) == 9) {
        imprime_matriz();
        
        xys(22, 20, ">> EMPATE!!!");
        xys(23, 20, ">> pressione [enter] para sair do jvelha...");
    
        int gambiarra;
        scanf("%c", &gambiarra);
        scanf("%c", &gambiarra);
        
        sair(0);
    } else {
        matriz[x][y] = 'O';
    }
}

//
// char verifica_ganhador(void);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//

char verifica_ganhador(void) {
    int i;
    
    for(i = 0; i < 3; i++) {
        if((matriz[i][0] == matriz[i][1]) &&
           (matriz[i][0] == matriz[i][2])) return matriz[i][0];
    }
    
    for(i = 0; i < 3; i++) {
        if((matriz[0][i] == matriz[1][i]) &&
           (matriz[0][i] == matriz[2][i])) return matriz[0][i];
    }
    
    if((matriz[0][0] == matriz[1][1]) &&
       (matriz[1][1] == matriz[2][2])) return matriz[0][0];
       
    if((matriz[0][2] == matriz[1][1]) &&
       (matriz[1][1] == matriz[2][0])) return matriz[0][2];
       
    return ' ';
}

//
// void jogada(void);
// ^^^^^^^^^^^^^^^^^^
//

void jogada(void) {
    char ganhador = ' ';
    
    inicializa_matriz();
    do {
        imprime_matriz();
        jogada_humano();

        ganhador = verifica_ganhador();
        if(ganhador != ' ') break;
        
        jogada_computador();
        ganhador = verifica_ganhador();
    } while(ganhador == ' ');
    
    if(ganhador == 'X') {
        imprime_matriz();
        
        xys(22, 20, ">> VOCÊ GANHOU!!!");
        xys(23, 20, ">> pressione [enter] para terminar...");
        
        // Gambiarra :P
        int gambiarra;
        scanf("%c", &gambiarra);
        scanf("%c", &gambiarra);
    } else {
        imprime_matriz();
    
        xys(22, 20, ">> COMPUTADOR GANHOU!!! :(");
        xys(23, 20, ">> pressione [enter] para terminar...");

        // Gambiarra :P        
        int gambiarra;
        scanf("%c", &gambiarra);
        scanf("%c", &gambiarra);
    }
}

//
// void njogo(void);
// ^^^^^^^^^^^^^^^^^
// Inicializa novo jogo!
//

void njogo(void) {
    tela_principal();
    jogada();
}

//
// void menu(void);
// ^^^^^^^^^^^^^^^^
// Cria menu e direciona as escolhas...
//

void menu(void) {
    int escolha;
    
    for(;;) {
        tela_principal();
        
        centraliza("ooooo MENU ooooo", 5);
        centraliza("oooooooooooooooo", 6);
        
        xys(10, 15, "[ 1 ] : Novo Jogo!");
        xys(11, 15, "[ 2 ] : Sobre...");
        xys(12, 15, "[ 3 ] : Sair");
        
        xys(14, 15, ">> Sua escolha: ");
        scanf("%d", &escolha);
        // escolha = getchar();
        
        switch(escolha) {
            case 1  :
                njogo();
                break;
            case 2  : 
                sobre();
                break;
            case 3  :
                sair(0);
                break;
            default :
                xys(16, 15, ">> Escolha inválida!");
                xys(17, 15, ">> Informe outra opção...");
        }
    }
}

//
// _EOF_
//
