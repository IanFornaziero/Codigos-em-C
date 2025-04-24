//criado por ian batista fornaziero RA 2677210
//Lista Pilha dinâmica

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>

typedef struct No{
    int dado;
    struct No* proximo;
} No;

No *topo = NULL;
No *topo_copia = NULL;

void push(int dado, No **topo_Ref) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    novo->dado = dado;
    novo->proximo = *topo_Ref;
    *topo_Ref = novo;
}

void pop(No **topo_Ref) {
    if(*topo_Ref == NULL) {
        printf("Pilha vazia");
        return;
    }

    No* temp = *topo_Ref;
    printf("Elemento desempilhado: %d\n", temp ->dado);
    *topo_Ref = temp -> proximo;
    free(temp);

}

//Exercicio 1

void Push2(int valor, int valor2) {
    No* novo = (No*) malloc (sizeof(No));

    if(novo == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    novo -> dado = valor;
    novo -> proximo = topo;
    topo = novo;

    printf("Elemento empilhado: %d\n",novo -> dado);

    No* novo2 = (No*) malloc (sizeof(No));

    if(novo2 == NULL) {
        printf("Erro ao alocar memoria");
        exit(-1);
    }

    novo2 -> dado = valor2;
    novo2 -> proximo = topo;
    topo = novo2;

    printf("Elemento empilhado: %d\n",novo2 -> dado);
}

//basicamente é a função push comum, só que duplicado, ele recebe 2 valores, o qual vai empilhar,
//vai criar uma instância nova para cada valor, vai alocar e definir os valores, e depois vai definir o topo da pilha
//e então, ele dá print nos elementos empilhados, que nessa forma, ele printa na ordem de cima para baixo
//mas é possivel ver a ordem da pilha no Pop2

void Pop2() {
    if(topo == NULL) {
        printf("Pilha vazia, nao tem mais nada para desempilhar");
        exit(-1);
    }

    No* temp = topo;
    printf("Elemento desempilhado: %d\n", temp ->dado);
    topo = topo -> proximo;
    free(temp);

    temp = topo;
    printf("Elemento desempilhado: %d\n", temp ->dado);
    topo = topo -> proximo;
    free(temp);
}

//mesmo coisa que o push, é um pop duplicado, no caso ele vai verificar se a pilha está vazia e impedir que ocorra bugs
//por conta da memoria, logo em seguida ele recebe o valor do topo em uma variavel temporária, a mesma a qual vai ser
//liberada, e para verificar se o valor liberada é o certo, ele vai printar o valor de temp

//exercicio 2

int PopN(int n) {
    if(n == 0) {
        return 0;
    }
    if(topo == NULL) {
        printf("pilha vazia, nao e possivel desempilhar mais");
        return -1;
    }

    No* temp = topo;
    printf("Elemento desempilhado: %d\n", temp -> dado);
    topo = topo -> proximo;
    free(temp);

    PopN(n - 1);
}

/*
para que seja desempilhado N itens, eu utilizei uma chamada recursiva para evitar o uso de um for
então na função ele tem como caso base o N ser igual a 0, pois ele vai diminuindo N como se fosse um contador
eu poderia ter utilizado o topo como caso base, até faria mais sentido, então poderia ser if(topo == NULL)
porém, ele iria desempilhar tudo, não N, pois ele ia chamando até que não tivesse mais pilha, por isso eu preferi
utilizar o N para fazer a recursividade, e se caso o N for maior, ele vai parar até a pilha estar vazia e retornar que
o numero é maior
*/

//exercicio 3

void PopAll(No *topo) {
    if(topo == NULL) {
        printf("pilha vazia\n");
        return;
    }
    No* temp = topo;
    printf("Elemento desempilhado: %d\n", temp -> dado);
    topo = temp -> proximo;
    free(temp);

    PopAll(topo);
}

No *CopiaPilha(No *topo_aux) {
    No* atual = topo;

    while (atual != NULL) {
        No* aux = (No*) malloc(sizeof(No));

        if (aux == NULL) {
            printf("Erro de alocação\n");
            exit(1);
        }

        aux->dado = atual->dado;
        aux->proximo = topo_aux;
        topo_aux = aux;

        atual = atual->proximo;
    }

    atual = topo_aux;

    while (atual != NULL) {
        No* copia = (No*) malloc (sizeof(No));

        if(copia == NULL) {
            printf("Erro ao alocar memoria");
            exit(-1);
        }

        copia -> dado = atual -> dado;
        copia -> proximo = topo_copia;
        topo_copia = copia;
        printf("Elemento empilhado na copia: %d \n", topo_copia -> dado);
        atual = atual -> proximo;
    }

    PopAll(topo_aux);
    return topo_copia;
}

/*
 Basicamente, na função de copiar a pilha, ele vai empilhar uma pilha auxiliar, que vai ser na ordem contraria
 da pilha normal, e logo em seguida, vai utilizar a essa pilha ao contrario, para empilar a cópia, que vai empilhar
 na mesma ordem que a pilha normal, e no final da função, ele vai usar a popAll na pilha auxilia,
 popAll é uma função que desempilha os elementos de uma pilha selecionada
*/

//exercicio 4

void MMM(No *topo) {
    int maior = topo->dado;
    int menor = topo->dado;
    float media = 0;
    int contador = 0;

    while(topo != NULL) {

        if(maior < topo -> dado) {
            maior = topo -> dado;
        }

        if(menor > topo -> dado) {
            menor = topo -> dado;
        }

        media += topo -> dado;
        contador++;
        topo = topo -> proximo;
    }

    media = media / contador;

    printf("O maior numero da pilha e: %d\n",maior);
    printf("O menor numero da pilha e: %d\n", menor);
    printf("O media dos numeros da pilha e: %.2f\n", media);
}

/*
basicamente, a função MMM "Maior, Menor, Media" vai receber um topo de uma pilha, e vai passar a pilha por um while
até que o topo chegue ao final topo = NULL, ai ele vai definir o maior da pilha no primeiro if e o menor no segundo,
para tirar a média, primeiro ele vai somar todos os elementos da pilha e enquanto passa o loop, ele vai incrementar
um contador para ser o denominador da media, e depois do while, ele vai tirar a media fazendo o calculo
soma dividido pelo contador, e dai ele vai printar os 3
 */

//exercicio 5
void compararPilha(No *topo, No *topo2) {
    if(topo == NULL || topo2 == NULL) {
        printf("alguma das duas pilhas estao vazias\n");
        return;
    }

    while(topo != NULL && topo2 != NULL) {
        if(topo -> dado != topo2 -> dado) {
            printf("Pilhas diferentes\n");
            return;
        }
        topo = topo -> proximo;
        topo2 = topo2 -> proximo;
    }
    printf("Pilhas sao iguais\n");
}

/*
Sem muito segredo, a função recebe dois topos e compara as pilhas para ver se eleas são iguais
no if dentro do loop, se algum elemento for diferente elas já não mais iguais, então ele retorna
e caso ele passe pelo loop, quer dizer que todos os elementos são iguais
 */

//exercicio 6

typedef struct frase {
    char algo;
    struct frase* prox;
} frase;

frase *topo_frase = NULL;
frase *topo_frase2 = NULL;

//pilhas para o exercicio 8
frase *topo_X = NULL;
frase *topo_Y = NULL;

void pushFrase(char algo, frase **topo_Ref) {
    frase *novo = (frase*) malloc (sizeof(frase));

    if(novo == NULL) {
        printf("Erro ao alocar memoria");
        exit(-1);
    }

    novo -> algo = algo;
    novo->prox = *topo_Ref;
    *topo_Ref = novo;
    printf("Empilhado\n");
}

void fraseInversa(frase *topo) {
    if(topo == NULL) {
        return;
    }

    fraseInversa(topo -> prox);
    printf("%c", topo -> algo);
}

frase *copiaFrase(frase *topo) {
    frase* atual = topo;

    while (atual != NULL) {
        frase* aux = (frase*) malloc(sizeof(frase));

        if (aux == NULL) {
            printf("Erro de alocação\n");
            exit(1);
        }

        aux->algo = atual->algo;
        aux->prox = topo_frase2;
        topo_frase2 = aux;

        atual = atual->prox;
    }
}

void compararFrase(frase *topo, frase *topo2) {
    while(topo != NULL && topo2 != NULL) {
        if(topo -> algo != topo2 -> algo) {
            printf("\nFrase nao palindromo\n");
            return;
        }
        topo = topo -> prox;
        topo2 = topo2 -> prox;
    }
    printf("\nFrase palindromo\n");
}

/*
 * criei uma struct para armazenar os caracteres, então o usuário vai inserir todos os caracteres até apertar 0 e parar
 * ai em seguida ele vai imprimir ao contrario utilizando recursividade, onde ele vai passar pelos elementos da pilha
 * até a pilha estar Null, ai ele vai voltar e printar os elementos de trás para frente
 * e para confirmar se a frase é polindromo ou não, ele vai copiar a pilha que vai copiar de trás para frente
 * e então vai comparar as duas pilhas, porque se elas forem iguais, então é polindromo
 */

//Exercicio 7

void IP(No *topo) {
    int Pares = 0;
    int Impares = 0;

    if(topo == NULL) {
        printf("Pilha vazia\n");
    }

    while(topo != NULL) {
        if(topo -> dado % 2 == 0) {
            Pares++;
        }else {
            Impares++;
        }
        topo = topo -> proximo;
    }
    printf("A quantidade de pares na pilha e: %d\n", Pares);
    printf("A quantidade de impares na pilha e: %d\n", Impares);
}

/*
 * Na função IP "Impar par" ele vai receber o topo a qual vai testar, e vai passar pelos elementos da pilha
 * verificando se cada um é divisivel por 2, se for, então é par, se passar pelo if, então é par
 * e vai printar a quantidade de impares e pares depois do loop
 */

//exercicio 8

void compararXY() {
    frase *temp1 = topo_X;
    frase *temp2 = topo_Y;

    if(topo_X == NULL || topo_Y == NULL) {
        printf("Alguma das pilhas esta vazia\n");
        return;
    }

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> algo == temp2 -> algo) {
            printf("%c\n", temp1 -> algo);
            printf("%c\n", temp2 -> algo);
            printf("As duas pilhas nao satisfazem x C y\n");
            return;
        }
        temp1 = temp1 -> prox;
        temp2 = temp2 -> prox;
    }

    printf("As duas pilhas satisfazem x C y\n");
}

/*
 *Ele vai ler os valores para a pilha X e a pilha Y, e depois vai comparar se forem iguais, não são inversos
 *se forem diferentes, são inversos
 */

//exercicio 9

void pilhaVazia(No **topo_Ref) {
    if(*topo_Ref == NULL) {
        printf("A pilha esta vazia\n");
        return;
    }
        printf("Pilha nao vazia\n");
}

void lerTopo(No **topo_Ref) {
    No *temp = *topo_Ref;

    if(*topo_Ref == NULL) {
        printf("A pilha esta vazia\n");
        return;
    }

    printf("O valor do topo da pilha e: %d\n", temp -> dado);
}

void DecimalBinario(int x) {
    if(x == 0) return;

    DecimalBinario(x / 2);

    printf("%d", x % 2);
}

void Menu() {
    int escolha;
    int valor;
    int continuar = 1;

    do {
        printf("1-Verifica estado da pilha.\n"); //verifica se ta vazia ou cheia
        printf("2-Empilha o elemento na pilha.\n");
        printf("3-Desempilha elemento da pilha.\n");
        printf("4-Le topo de um pilha.\n");
        printf("5-Converte um numero decimal em binario.\n");
        printf("6-Sair.\n");
        scanf("%d", &escolha);

        switch(escolha) {
            case 1:
                pilhaVazia(&topo);
            break;
            case 2:
                printf("Insira um valor: ");
            scanf("%d", &valor);
            push(valor, &topo);
            break;
            case 3:
                pop(&topo);
            break;
            case 4:
                lerTopo(&topo);
            break;
            case 5:
                DecimalBinario(topo -> dado);
                printf("\n");
            break;
            case 6:
                continuar = 0;
            break;
            default:
                printf("Opcao invalida\n");
            break;
        }
    } while(continuar == 1);
}

/*
 *Bem, ele vai mostrar o menu, e o usuário vai escolher qual módulo deseja
 *eu coloquei o menu em um loop para ficar melhor, e a verificação do módulo é por um switch case
 *no modulo de verificar se a pilha é cheia ou vazia, eu entendi que poderia ser a mesma função, está cheia ou vazia
 *no modulo de empilhar, ele vai puxar a função push comum e na de desempilhar vai chamar a função de pop comum
 *no modulo de ler topo, ele vai pegar o elemento do topo e printar
 *no modulo de transformar decimal em binário, ele vai transformar o topo em binário
 *para tal, ele vai puxar uma função recursiva, que nessa função, ele tem uma chamada recurisva, que vai dividir
 *o valor por 2 e quando der resto 0, ele vai printar 0, se for não for divisivel por 2, o resto vai dar 1
 *então ele vai printar 1
 *e no 6 ele sai
 *só não entendi o que é inicializar pilha, eu entendi como empilhar, por isso deixei de fora
 */

int main(void) {
    int valor = 10;
    int valor2 = 33;
    int valor3 = 40;
    int valor4 = 51;
    int N = 2;
    int Sair = 1;
    char Caractere;
    No *topo_aux = NULL;
    No *atual = topo_copia;

    Push2(valor, valor2);
    Pop2();

    getc(stdin);

    Push2(valor, valor2);
    PopN(N);
    getc(stdin);

    Push2(valor, valor2);
    CopiaPilha(topo_aux);
    getc(stdin);

    MMM(topo);
    getc(stdin);

    compararPilha(topo, topo_copia);
    getchar();

    while(Sair != 0) {
        printf("Digite um caractere ou aperte 0 para sair: ");
        scanf(" %c", &Caractere);

        if(Caractere == '0') {
            Sair = 0;
        }else {
            pushFrase(Caractere, &topo_frase);
        }
    }

    fraseInversa(topo_frase);
    copiaFrase(topo_frase);
    compararFrase(topo_frase, topo_frase2);
    getc(stdin);

    IP(topo);
    getc(stdin);

    Sair = 1;

   while(Sair != 0) {
        printf("Digite apenas A ou B para a pilha X, ou aperte 0 para sair: ");
        scanf(" %c", &Caractere);

        if(Caractere == '0') {
            Sair = 0;
        }else {
            pushFrase(Caractere, &topo_X);
        }
    }

    Sair = 1;

    while(Sair != 0) {
        printf("Digite apenas A ou B para a pilha Y, ou aperte 0 para sair: ");
        scanf(" %c", &Caractere);

        if(Caractere == '0') {
            Sair = 0;
        }else {
            pushFrase(Caractere, &topo_Y);
        }
    }

    compararXY();
    getc(stdin);

    Menu();

    return 0;
}