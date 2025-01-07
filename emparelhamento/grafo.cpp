#include "grafo.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Grafo::Grafo(int vertices) : v(vertices), adj(vertices+1) {}

void Grafo::adicionarAresta(int u, int v) {
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

Grafo lerGrafo(const std::string& nomeArquivo, bool bipartido) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return Grafo(0);
    }

    int a, b, n, m;
    if (bipartido) {
        arquivo >> a >> b >> m;
        n = a+b;
    } else {
        arquivo >> n >> m;
    }
    
    Grafo grafo(n);
    if (bipartido) grafo.particao1 = a;

    for (int i = 0; i < m; ++i) {
        int u, v;
        arquivo >> u >> v;
        grafo.adicionarAresta(u, v);
    }

    arquivo.close();
    return grafo;
}
