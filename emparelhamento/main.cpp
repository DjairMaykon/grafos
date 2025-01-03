#include <iostream>
#include "grafo.h"
#include "algoritmo-simples.h"

int main() {
    // Nome do arquivo a ser lido
    std::string nomeArquivo = "grafo.txt";

    // Chamando a função para ler o grafo
    Grafo grafo = lerGrafo(nomeArquivo);

    // Exibindo os vértices
    std::cout << "Vértices do grafo: ";
    for (int i = 1; i <= grafo.v; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Exibindo as arestas
    std::cout << "Lista de adjacencia: " << std::endl;
    for (int i = 1; i <= grafo.v; i++) {
        std::cout << i << ": ";
        for (int v : grafo.adj[i]) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    
    std::vector<std::vector<int>> x = encontraEmparelhamentoMaximo(grafo);

    return 0;
}
