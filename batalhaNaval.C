#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>
#include <conio.h>

char tabuleiro[10][10];
char tabuleiro1[10][10];
char tabuleiro2[10][10];
char tabuleiroA1[10][10];
char tabuleiroA2[10][10];

int acertosJogador1 = 0, acertosJogador2 = 0;
int jogador;
void apresentacao(){
    printf("- BEM VINDO À BATALHA NAVAL - \n\n");
    printf("Pressione qualquer tecla para continuar...");
    getch();
    system("cls");
}


void inicializarTabuleiro(char tabuleiro[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = '~';
        }
    }
}


void mostrar(char tabuleiro[10][10]){
    printf("- ESSE É O TABULEIRO - \n");
    printf("  0 1 2 3 4 5 6 7 8 9 \n");

    for(int i = 0; i < 10; i++){
      printf("%d ", i);
      for(int j = 0; j < 10; j++){
            printf("%c ", tabuleiro[i][j]);
        }printf("\n");
    }
}

void escolhaPosicao(char tabuleiro[10][10]){
    int linha, coluna;
    printf("Você vai escolher 5 posições. \n");

    for(int i = 0; i < 5; i++){
        printf("Digite a linha: ");
        scanf("%d", &linha);
        if(linha < 0 || linha > 9){
            printf("Linha inválida, escolha novamente: ");
            scanf("%d", &linha);
        }
        printf("Digite a coluna: ");
        scanf("%d", &coluna);
        if(coluna < 0 || coluna > 9){
            printf("Coluna inválida, escolha novamente: ");
            scanf("%d", &coluna);
        }
        if(tabuleiro[linha][coluna] == 'N'){
            printf("Posição já ocupada, escolha novamente em outra posição. \n\n");
            i--;
            continue;
        }
        tabuleiro[linha][coluna] = 'N';
        mostrar(tabuleiro);
    }
    printf("Você escolheu seus 5 navios, agora é a vez do seu adversário. \n");
    printf("Pressione qualquer tecla para continuar.");
    getch();
    system("cls");
}

void ataque(){

    int linha, coluna;
    if(jogador == 1 ){
        tabuleiro[10][10] = tabuleiroA1[10][10];
    }else tabuleiro[10][10] = tabuleiroA2[10][10];;
    if(jogador == 1){
        jogador = 1;
    } else jogador = 2;
    mostrar(tabuleiro);
    printf("Ataque do jogador %d\n", jogador);
    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);

    if (tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] =='X'){
        printf("Posição já escolhida, joque novamente. \n");
        printf("Linha: ");
        scanf("%d", &linha);

        printf("Coluna: ");
        scanf("%d", &coluna);
    }
    if(tabuleiro[linha][coluna] == 'N'){
        printf("Você acertou um navio inimigo!\n");
        tabuleiro[linha][coluna] = 'O';
        if(jogador == 1){
             acertosJogador1++;
        } else acertosJogador2++;
    } else{
        printf("Você errou os navios inimigos!\n");
        tabuleiro[linha][coluna] = 'X';
    }
    mostrar(tabuleiro);
    printf("Vez do jogador %d, pressione para continuar.", jogador + 1);
    getch();
    system("cls");
}

void rodadas(){
    while(acertosJogador1 != 5 && acertosJogador2 != 5){
        ataque(jogador = 1);
        if(acertosJogador1 != 5)
        ataque(jogador = 2);
        else break;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    inicializarTabuleiro(tabuleiro);
    inicializarTabuleiro(tabuleiro1);
    inicializarTabuleiro(tabuleiro2);
    inicializarTabuleiro(tabuleiroA1);
    inicializarTabuleiro(tabuleiroA2);

    apresentacao();
    // Jogador 1 escolhe navios
    mostrar(tabuleiro);
    escolhaPosicao(tabuleiro1);
    // Jogador 2 escolhe navios
    mostrar(tabuleiro);
    escolhaPosicao(tabuleiro2);
    //ataques
    rodadas();



    return 0;
}