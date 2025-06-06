//Criado por Ian Fornaziero
//Calculadora de matrizes

#include <stdio.h>
#include <stdlib.h>

void CriarMatriz(int i,int j,int matriz_A[i][j]){  //função para criação da primeira matriz
    for(int linhas=0;linhas<i;linhas++){
        for(int colunas=0;colunas<j;colunas++){
            printf("informe o valor da posicao [%d][%d] da primeira matriz: ",linhas+1,colunas+1);
                scanf("%d",&matriz_A[linhas][colunas]);
        }
    }
}

void CriarMatriz2(int i2,int j2,int matriz_B[i2][j2]){ //função para criação da segunda matriz
    for(int linhas=0;linhas<i2;linhas++){
        for(int colunas=0;colunas<j2;colunas++){
            printf("informe o valor da posicao [%d][%d] da segunda matriz: ",linhas+1,colunas+1);
                scanf("%d",&matriz_B[linhas][colunas]);
        }
    }
}

void MostrarMatriz_SeB(int i,int j,int matriz_C[i][j]){ //função para mostrar a matriz em situação de soma e subtração
    for(int linhas=0;linhas<i;linhas++){
        printf("\n");
        for(int colunas=0;colunas<j;colunas++){
            printf("%d ",matriz_C[linhas][colunas]);
        }
    }
}

void MostrarTransposta(int i3,int j3, int matriz_T[i3][j3]){ //função para mostrar a matriz transposta
    for(int linhas=0;linhas<i3;linhas++){
        printf("\n");
            for(int colunas=0;colunas<j3;colunas++){
                printf("%d ",matriz_T[linhas][colunas]);
            }
    }
}

int main(){

    
    int i,j;
    int i2,j2;
    int i3,j3;
    int escolha;

    
    //O usuário inseri o tamanho das duas matrizes
    
    printf("antes de iniciar o programa, informe o numero de linhas da primeira matriz: ");
        scanf("%d",&i);
    printf("agora informe a quantidade de colunas: ");
        scanf("%d",&j);
    printf("agora informe a quantidade de linhas da segunda matriz: ");
        scanf("%d",&i2);
    printf("agora informe a quantidade de colunas: ");
        scanf("%d",&j2);

    int matriz_A[i][j];
    int matriz_B[i2][j2];
    int matriz_C[i][j];
    int modulo;

    
    //HUB do programa
    printf("eae ianzao, bem vindo a calculadora de matrizes\n");
    printf("\n");
    printf("\n");
    printf("cada modulo faz uma operacao com matrizes\n");
    printf("------------------\n");
    printf("1 - Soma de matrizes\n");
    printf("\n");
    printf("2 - Subtracao de matrizes\n");
    printf("\n");
    printf("3 - Multiplicacao de matrizes\n");
    printf("\n");
    printf("4 - Criar transposta\n");
    printf("------------------\n");
    printf("\n");
    printf("agora escolha o modulo: ");
        scanf("%d",&modulo);

    printf("\n");

    switch (modulo) //switch para definir as operações com matrizes
    {
case 1: //Soma de matrizes
        
        if(i!=i2 || j!=j2){ //bloqueio para operações irreguralares
            printf("A quantidade de linhas e colunas das duas matrizes devem ser iguais para essa operacao.\n");
            printf("Reiniciando programa...\n");
            return main();
        }else{

        //Trazendo as funções para criação das duas matrizes
        CriarMatriz(i,j,matriz_A); 
        CriarMatriz2(i2,j2,matriz_B);

        for(int linhas=0;linhas<i;linhas++){ //Loop para realizar a soma das matrizes
            for(int colunas=0;colunas<j;colunas++){
                matriz_C[linhas][colunas]=(matriz_A[linhas][colunas] + matriz_B[linhas][colunas]);
            }
        }

        printf("A soma das matrizes A e B e: ");
        MostrarMatriz_SeB(i,j,matriz_C); //trazendo a função para mostrar as matrizes
        }

break;

case 2: //Subtração de matrizes

        if(i!=i2 || j!=j2){ //bloqueio para operações irregurales
            printf("A quantidade de linhas e colunas das duas matrizes devem ser iguais para essa operacao.\n");
            printf("Reiniciando programa...\n");
            return main();
        }else{

        //trazendo as funções para criação das matrizes
        CriarMatriz(i,j,matriz_A);
        CriarMatriz2(i2,j2,matriz_B);

        for(int linhas=0;linhas<i;linhas++){ //Loop para realizar a subtração
            for(int colunas=0;colunas<j;colunas++){
                matriz_C[linhas][colunas]=(matriz_A[linhas][colunas] - matriz_B[linhas][colunas]);
            }
        }

        printf("A subtracao das matrizes A e B e: ");
        MostrarMatriz_SeB(i,j,matriz_C); //trazendo o comando para mostrar a matriz subtraida
        }

break;
    
case 3: //Multiplicação de matrizes

    if(j != i2){ //bloqueio para operações irregulares
        printf("O numero de linhas da primeira deve ser igual ao numero de colunas da outra matriz para esta operacao\n");
        printf("Reiniciando programa...\n");
        return main();
    }else{

        i3=i; //definindo que a linha da matriz resultado será do mesmo tamanho da linha da primeira matriz
        j3=j2; //definindo que a coluna da matriz resultado será do mesmo tamanho da coluna da segunda matriz

        //trazendo as funções para criar as duas matrizes
        CriarMatriz(i,j,matriz_A);
        CriarMatriz2(i2,j2,matriz_B);

        for(int linhas=0;linhas<i3;linhas++){ //inicializando a matriz igual a 0
            for(int colunas=0;colunas<j3;colunas++){
                matriz_C[linhas][colunas]=0;
            }
        }

        for(int linhas=0;linhas<i3;linhas++){ //fazendo a multiplicação
            for(int colunas=0;colunas<j3;colunas++){
                for(int k=0;k<j;k++){
                    matriz_C[linhas][colunas] += matriz_A[linhas][k] * matriz_B[k][colunas];
                }
            }
        }

         printf("A multiplicacao das matrizes e: \n");

        //Loop para mostrar a matriz resultado
        for(int linhas=0;linhas<i3;linhas++){
                printf("\n");
            for(int colunas=0;colunas<j3;colunas++){
                printf("%d ",matriz_C[linhas][colunas]);
            }
        }

    }
    

break;

case 4:
    //O usuário inseri qual das duas matrizes ele deseja fazer a transposta

    printf("voce deseja fazer a transposta da primeira matriz ou da segunda? \n");
    printf("selecione 1 para a primeira e 2 para a segunda: ");
        scanf("%d",&escolha);

    if(escolha==1){ //caso seja a primeira matriz
        CriarMatriz(i,j,matriz_A); //trazendo a função para criar a primeira matriz

            i3 = j; //definindo que a quantidade de linhas da transposta é igual a de colunas
            j3 = i; //definindo que a quantidade de colunas da transposta é igual a de linhas

        int matriz_T[i3][j3];

            //loop para criar a transposta
            for(int linhas=0;linhas<i;linhas++){
                printf("\n");
                    for(int colunas=0;colunas<j;colunas++){
                    matriz_T[colunas][linhas]=matriz_A[linhas][colunas];
                }
            }

        MostrarTransposta(i3,j3,matriz_T); //trazendo a função para mostrar a matriz transposta

    }else if(escolha==2){ //caso seja a segunda matriz

        CriarMatriz2(i2,j2,matriz_B); //trazendo a função para criar a segunda matriz

            i3 = j2; //definindo que a quantidade de linhas da transposta é igual a de colunas
            j3 = i2; //definindo que a quantidade de colunas da transposta é igual a de linhas

            int matriz_T[i3][j3];

            //Loop para criar a transposta
            for(int linhas=0;linhas<i2;linhas++){
                for(int colunas=0;colunas<j2;colunas++){
                    matriz_T[colunas][linhas]=matriz_B[linhas][colunas];
                }
            }

            MostrarTransposta(i3,j3,matriz_T); //trazendo a função para mostrar a matriz transposta

    }else{ //bloqueio para operações irregulares
        printf("valor inválido inserido\n");
        printf("Reiniciando programa...\n");
        return main();
    }
break;

default:
    printf("Valor invalido\n");
    printf("Encerrando programa...\n");
    return main();

break;
    }
    
    return 0;
}
