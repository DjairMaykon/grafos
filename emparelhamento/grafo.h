#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

struct Grafo {
    int v;
    std::vector<std::vector<int>> adj;
    Grafo(int v);
    void adicionarAresta(int u, int v);
};

Grafo lerGrafo(const std::string& nomeArquivo);

#endif // GRAFO_H
