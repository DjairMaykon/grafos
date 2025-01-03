#include <iostream>
#include "grafo.h"
#include "algoritmo-simples.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Nome do arquivo a ser lido
    string nomeArquivo = "grafo.txt";

    // Chamando a função para ler o grafo
    Grafo grafo = lerGrafo(nomeArquivo);

    // Exibindo os vértices
    cout << "Vértices do grafo: ";
    for (int i = 1; i <= grafo.v; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Exibindo as arestas
    cout << "Lista de adjacencia: " << endl;
    for (int i = 0; i < grafo.v; i++) {
        cout << i+1 << ": ";
        for (int v : grafo.adj[i]) {
            cout << v+1 << " ";
        }
        cout << endl;
    }
    
    vector<int> m = encontraEmparelhamentoMaximo(grafo);
    
    for (int i = 0; i < grafo.v; i++) 
        cout << i + 1 << ": " << m[i] + 1 << " -- ";
    cout << endl;

    return 0;
}
