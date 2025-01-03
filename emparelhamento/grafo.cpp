#include "grafo.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Grafo::Grafo(int vertices) : v(vertices), adj(vertices+1) {}

void Grafo::adicionarAresta(int u, int v) {
    adj[u].push_back(v);  // Adiciona v à lista de adjacências de u
    adj[v].push_back(u);  // Se o grafo for não direcionado, adiciona u à lista de adjacências de v
}

Grafo lerGrafo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return Grafo(0);
    }

    int n, m;  // n - número de vértices, m - número de arestas
    arquivo >> n >> m;
    Grafo grafo(n);

    // Adicionando as arestas (pares de vértices) no vetor de arestas
    for (int i = 0; i < m; ++i) {
        int u, v;
        arquivo >> u >> v;
        grafo.adicionarAresta(u, v);
    }

    arquivo.close();
    return grafo;
}
