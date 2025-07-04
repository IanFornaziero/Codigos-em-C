//
// Created by capit on 24/06/2025.
//

#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct grafo Grafo;
typedef struct Graf Graf;

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
void imprime_Grafo(Grafo *gr);

//Exercicio 4
Graf *CriaGraf(int qtdNos);
int InsereAresta(Graf *gr, int origem, int destino, int peso, int direcionado, int valor);
int RemoveAresta(Graf *gr, int origem, int destino, int direcionado);

//Exercicio 5
int menorVertice(float* dist, int* visitado, int n);
Grafo *Prim(Grafo* gr, int orig);

//Exercicio 6

int encontraNo(Grafo *gr, int no);
int encontraArestaMenorPeso(Grafo *gr, int *orig_min, int *dest_min, float *peso_min);

#endif //FUNCOES_H
