//JOGO DA VELHA EM C
//incluir biblioteca
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    //criar as variaveis das jogadas e do placar
    int menu;
    char sair;
    char casas[9] = {'1','2','3','4','5','6','7','8','9'};
    char res;
    int jogador1 = 0,jogador2 = 0, empate = 0;
    int contjogo, jogada=1, vez = 0,i;

    setlocale(LC_ALL,"Portuguese");

    do{
        system ("cls");
        printf("MENU\n");//menu
        printf("1 - Jogar\n");
        printf("2 - Mostrar Placar\n");
        printf("0 - Sair do Jogo\n\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                system ("cls"); //limpando tabuleiro
                int tabuleiro (char casas2[9]){
                    system ("cls");//COM VETOR
                printf ("     ...JOGO DA VELHA... \n\n ");//criando o tabuleiro
                printf ("\t  %c | %c | %c                   1 | 2 | 3 \n",casas2 [0],casas2[1],casas2[2]);
                printf ("\t -----------                 ----------- \n");
                printf ("\t  %c | %c | %c                   4 | 5 | 6 \n",casas2 [3],casas2[4],casas2[5]);
                printf ("\t -----------                 ----------- \n");
                printf ("\t  %c | %c | %c                   7 | 8 | 9\n\n",casas2 [6],casas2[7],casas2[8]);

                }
                do{
                    contjogo = 1;
                        for(i=0;i<=8;i++){
                            casas[i] = ' ';
                        }

                    do{
                        tabuleiro (casas);
                        if(jogada==0){
                            printf("Jogada inválida tente novamente\n");
                        }
                        printf ("DIGITE A CASA [1-9]\n");
                        if(vez%2==0){
                            printf("Jogador X\n");
                        }else{
                            printf("Jogador O\n");
                        }
                        scanf("%i",&jogada);
                        if(jogada<1|| jogada>9){
                            jogada = 0;
                        }else if (casas[jogada-1]!=' '){
                            jogada = 0;
                        }else{
                        if (vez%2==0){
                            printf("O JOGADOR 'X' FEZ SUA JOGADA.\n\n");
                            casas[jogada-1] = 'X';
                        }else {
                            printf("O JOGADOR 'O' FEZ SUA JOGADA.\n\n");
                            casas[jogada-1] = 'O';
                        }
                        contjogo++;
                        vez++;
                        }
                        if (casas[0]=='X'&& casas[1]=='X' && casas[2]=='X'){contjogo = 11;}
                        if (casas[3]=='X'&& casas[4]=='X' && casas[5]=='X'){contjogo = 11;}
                        if (casas[6]=='X'&& casas[7]=='X' && casas[8]=='X'){contjogo = 11;}
                        if (casas[0]=='X'&& casas[3]=='X' && casas[6]=='X'){contjogo = 11;}
                        if (casas[1]=='X'&& casas[4]=='X' && casas[7]=='X'){contjogo = 11;}
                        if (casas[2]=='X'&& casas[5]=='X' && casas[8]=='X'){contjogo = 11;}
                        if (casas[0]=='X'&& casas[4]=='X' && casas[8]=='X'){contjogo = 11;}
                        if (casas[2]=='X'&& casas[4]=='X' && casas[6]=='X'){contjogo = 11;}

                        if (casas[0]=='O'&& casas[1]=='O' && casas[2]=='O'){contjogo = 12;}
                        if (casas[3]=='O'&& casas[4]=='O' && casas[5]=='O'){contjogo = 12;}
                        if (casas[6]=='O'&& casas[7]=='O' && casas[8]=='O'){contjogo = 12;}
                        if (casas[0]=='O'&& casas[3]=='O' && casas[6]=='O'){contjogo = 12;}
                        if (casas[1]=='O'&& casas[4]=='O' && casas[7]=='O'){contjogo = 12;}
                        if (casas[2]=='O'&& casas[5]=='O' && casas[8]=='O'){contjogo = 12;}
                        if (casas[0]=='O'&& casas[4]=='O' && casas[8]=='O'){contjogo = 12;}
                        if (casas[2]=='O'&& casas[4]=='O' && casas[6]=='O'){contjogo = 12;}

                    }while (contjogo <= 9);
                    tabuleiro(casas);
        //APRESENTAÇÃO DO VENCEDOR OU EMPATE.
                    if(contjogo==10){
                        printf("jogo empatado\n");
                        empate++;
                    }if(contjogo==11){
                        printf("vencedor 'X'\n");
                        jogador1++;
                    }if(contjogo==12){
                        printf("vencedor 'O'\n");
                        jogador2++;
                    }
        //imprimindo o placar
                    printf ("Vitorias jogador 'X' = %i\n",jogador1);
                    printf ("Vitorias jogador 'O' = %i\n",jogador2);
                    printf ("EMPATE               =%i\n",empate);
//NO FIM DO JOGO APRESENTARÁ SE DESEJA JOGAR NOVAMENTE
                    printf ("Deseja jogar novamente? [S-N]\n");
                    scanf("%s",&res);

                }while(res=='s');
            case 2:
                system ("cls");
                printf("Placar:\n");
                printf("Jogador 1 = %d\n", jogador1);
                printf("Jogador 2 = %d\n", jogador2);
                printf("Empates   = %d\n", empate);
                printf("\nPressione qualquer tecla para retornar ao menu...");
                scanf("\n%c", &sair);
                break;
        }
    }while(menu!=0);

    printf("Placar:\n");
    printf("Jogador 1 = %d\n", jogador1);
    printf("Jogador 2 = %d\n", jogador2);
    printf("Empates   = %d\n", empate);

return 0;
}

