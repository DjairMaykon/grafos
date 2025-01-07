#include <iostream>
#include "grafo.h"
#include "algoritmo-simples.h"
#include "hopcroft-karp.h"
#include <vector>
#include <string>

using namespace std;

void testeAlgoritimoSimples() {
    Grafo grafo = lerGrafo("grafo.txt");

    cout << "Vértices do grafo: ";
    for (int i = 1; i <= grafo.v; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Lista de adjacencia: " << endl;
    for (int i = 0; i < grafo.v; i++) {
        cout << i+1 << ": ";
        for (int v : grafo.adj[i]) {
            cout << v+1 << " ";
        }
        cout << endl;
    }
    
    vector<int> m = algoritmoSimples(grafo);
    
    for (int i = 0; i < grafo.v; i++)  {
        cout << i + 1 << ": " << m[i] + 1;
        if (i < grafo.v-1) cout << ", ";
    }
    cout << endl;
}

void testeHopcroftKarp() {
    Grafo grafo = lerGrafo("grafo-bipartido.txt", true);

    cout << "Vértices do grafo: " << endl;
    for (int i = 1; i <= grafo.v; i++) {
        cout << i << " - partição " << 1 + (i > grafo.particao1) << endl;
    }
    cout << endl;

    cout << "Lista de adjacencia: " << endl;
    for (int i = 0; i < grafo.v; i++) {
        cout << i+1 << ": ";
        for (int v : grafo.adj[i]) {
            cout << v+1 << " ";
        }
        cout << endl;
    }
    
    vector<int> m = hopcroftKarp(grafo);
    
    for (int i = 0; i < grafo.v; i++) {
        cout << i + 1 << ": " << m[i] + 1;
        if (i < grafo.v-1) cout << ", ";
    }
    cout << endl;
}


int main() {

    cout << "------------------------- ALGORITIMO SIMPLES -------------------------" << endl;    
    testeAlgoritimoSimples();
    cout << "------------------------- ALGORITIMO SIMPLES -------------------------" << endl;    
    
    cout << "------------------------- HOPCROFT KARP -------------------------" << endl;    
    testeHopcroftKarp();
    cout << "------------------------- HOPCROFT KARP -------------------------" << endl;    

    return 0;
}
