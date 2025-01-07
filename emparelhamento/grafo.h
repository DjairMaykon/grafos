#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

struct Grafo {
    int v;
    int particao1 = 0;
    std::vector<std::vector<int>> adj;
    Grafo(int v);
    void adicionarAresta(int u, int v);
};

Grafo lerGrafo(const std::string& nomeArquivo, bool bipartido = false);

#endif // GRAFO_H
