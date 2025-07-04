#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])//elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

//exercicio 4

typedef struct Elemento {
    int indice;
    int valor;
    int peso;
    struct Elemento *prox;
    struct Elemento *ant;
}Elemento;

typedef Elemento *Lista;

struct Graf {
    Lista *vet;
    int nos;
};

Graf *CriaGraf(int qtdNos)
{
    Graf *gr;
    gr = (Graf*) malloc(sizeof(Graf));

    if(gr == NULL) return NULL;

    gr -> nos = qtdNos;
    gr -> vet = (Lista *)calloc(qtdNos, sizeof(Lista));

    if(gr -> vet == NULL)
    {
        free(gr);
        return NULL;
    }

    return gr;
}

int InsereAresta(Graf *gr, int origem, int destino, int peso, int direcionado, int valor)
{
    if(gr == NULL) return 0; //caso o grafo não exista
    if(origem < 0 || origem >= gr -> nos) return 0; //caso a origem seja menor que zero ou maior que a quantidade de nós
    if(destino < 0 || destino >= gr -> nos) return 0; //caso o destino seja menor que zero ou maior que a quantidade nós

    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));

    if(novo == NULL) return 0; //erro de alocação

    novo -> indice = destino;
    novo -> valor = valor;
    novo -> peso = peso;
    novo -> prox = gr -> vet[origem];
    novo -> ant = NULL;

    if(gr -> vet[origem] != NULL)
    {
        gr -> vet[origem] -> ant = novo;
    }

    gr -> vet[origem] = novo;

    if(!direcionado)
    {
        InsereAresta(gr, destino, origem, peso, 1, valor);
    }

    return 1;
}

int RemoveAresta(Graf *gr, int origem, int destino, int direcionado)
{
    if(gr == NULL) return 0; //caso o grafo não exista
    if(origem < 0 || origem >= gr -> nos) return 0; //caso a origem seja menor que zero ou maior que a quantidade de nós
    if(destino < 0 || destino >= gr -> nos) return 0; //caso o destino seja menor que zero ou maior que a quantidade nós

    Elemento *atual = gr -> vet[origem];

    while(atual != NULL)
    {
        if(atual -> indice == destino)
        { //remove o elemento da lista
            if(atual -> ant != NULL) atual -> ant -> prox = atual -> prox;
            else gr -> vet[origem] = atual -> prox;

            if(atual -> prox != NULL) atual -> prox -> ant = atual -> ant;

            free(atual);

            if(!direcionado) RemoveAresta(gr, destino, origem, 1);

            return 1;
        }

        atual = atual -> prox;
    }

    return 0;
}

//Exercicio 5

int menorVertice(float* dist, int* visitado, int n)
{ //busca o menor vértice com o menor custo
    int menor = -1;
    for (int i = 0; i < n; i++) {
        if (!visitado[i] && (menor == -1 || dist[i] < dist[menor]))
            menor = i;
    }
    return menor;
}

Grafo *Prim(Grafo* gr, int orig)
{
    if (gr == NULL || !gr->eh_ponderado) return NULL;

    int n = gr->nro_vertices;
    int *visitado = (int*) calloc(n, sizeof(int)); //vértice que já entrou na árvore
    int *anterior = (int*) calloc(n, sizeof(int)); //de onde o vértice foi conectado
    float *dist = (float*) malloc(n * sizeof(float)); //menor custo das arestas

    for (int i = 0; i < n; i++)
    {
        dist[i] = 1000000; //um numero muito grande
        anterior[i] = -1;
    }

    dist[orig] = 0; //"coloca" o vértice na árvore

    for (int i = 0; i < n - 1; i++) {
        int u = menorVertice(dist, visitado, n); //escolhe o menor vértice com menor peso
        if (u == -1) break; //impede que seja feito a ligação da aresta

        visitado[u] = 1; //marca que o vértice foi visitado

        for (int j = 0; j < gr->grau[u]; j++) //passa por todos os vizinhos
        {
            int v = gr->arestas[u][j]; //pega o vértice do vizinho
            float peso = gr->pesos[u][j]; //pega o peso

            if (!visitado[v] && peso < dist[v]) //verifica se já está na árvore e se o novo peso é menor que o atual
            {
                dist[v] = peso; //atualiza o peso
                anterior[v] = u; //atualiza o que foi ligado
            }
        }
    }

    // Cria a árvore
    Grafo* ArvGM = cria_Grafo(n, gr->nro_vertices - 1, 1);
    for (int i = 0; i < n; i++) {
        if (anterior[i] != -1)
            insereAresta(ArvGM, i, anterior[i], 0, dist[i]); // insere as arestas
    }

    // Libera auxiliares
    free(visitado);
    free(anterior);
    free(dist);

    return ArvGM;
}

//Exercicio 6

/*
 * 1. Encontra um nó específico no grafo.
 * 2. Verifica se o grafo é válido e se o nó está dentro dos limites.
 * 3. Percorre os nós do grafo para encontrar o nó especificado.
 * 4. Retorna 1 se o nó foi encontrado, ou 0 caso contrário.
 */
//? 1.
int encontraNo(Grafo *gr, int no)
{
    //? 2.
    if (gr == NULL || no < 0 || no >= gr->nro_vertices)
        return 0;

    //? 3.
    for (int i = 0; i < gr->nro_vertices; i++)
    {
        if (i == no)
            return 1; // nó encontrado
    }
    //? 4.
    return 0; // nó não encontrado
}

/*
 * 1. Encontra a aresta de menor peso no grafo.
 * 2. Verifica se o grafo é válido e se é ponderado.
 * 3. Percorre todos os vértices e suas arestas para encontrar o menor peso.
 * 4. Se encontrou pelo menos uma aresta, retorna os valores por referência.
 * 5. Retorna 1 se encontrou uma aresta, 0 se o grafo está vazio ou não é ponderado.
 */
//? 1.
int encontraArestaMenorPeso(Grafo *gr, int *orig_min, int *dest_min, float *peso_min)
{
    //? 2.
    if (gr == NULL || !gr->eh_ponderado)
        return 0;

    int encontrou_aresta = 0;
    float menor_peso;
    int origem_menor, destino_menor;

    //? 3.
    for (int i = 0; i < gr->nro_vertices; i++)
    {
        for (int j = 0; j < gr->grau[i]; j++)
        {
            if (!encontrou_aresta)
            {
                menor_peso = gr->pesos[i][j];
                origem_menor = i;
                destino_menor = gr->arestas[i][j];
                encontrou_aresta = 1;
            }
            else if (gr->pesos[i][j] < menor_peso)
            {
                menor_peso = gr->pesos[i][j];
                origem_menor = i;
                destino_menor = gr->arestas[i][j];
            }
        }
    }

    //? 4.
    if (encontrou_aresta)
    {
        *orig_min = origem_menor;
        *dest_min = destino_menor;
        *peso_min = menor_peso;
        //? 5.
        return 1;
    }

    //? 5.
    return 0;
}