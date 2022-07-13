#include <stdio.h>
#include <stdlib.h>

/*
 * Programa: Jogo da velha em C
*/

int main(){
    int tabuleiro[3][3];
    int jogador = 1;
    
    //desenhar tabuleiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = 0;
        }
    }
    //imprimir tabuleiro na tela
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    //iniciar jogo
    while(1){
        //ler jogada do jogador
        int linha, coluna;
        printf("Jogador %d, digite a linha e a coluna: ", jogador);
        scanf("%d %d", &linha, &coluna);
        //verificar se a jogada é válida
        if(tabuleiro[linha][coluna] != 0){
            printf("Jogada inválida!\n");
            continue;
        }
        //marcar jogada
        tabuleiro[linha][coluna] = jogador;
        //imprimir tabuleiro na tela
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        //verificar se o jogo acabou
        int venceu = 0;
        for(int i = 0; i < 3; i++){
            if((tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) && tabuleiro[i][0] != 0){
                venceu = 1;
            }
            if((tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) && tabuleiro[0][i] != 0){
                venceu = 1;
            }
        }
        if((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) && tabuleiro[0][0] != 0){
            venceu = 1;
        }
        if((tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) && tabuleiro[0][2] != 0){
            venceu = 1;
        }
        if(venceu){
            printf("Jogador %d venceu!\n", jogador);
            break;
        }
        //alternar jogador
        jogador = (jogador == 1) ? 2 : 1;
    }
}