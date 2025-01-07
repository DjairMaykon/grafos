#include "hopcroft-karp.h"
#include "grafo.h"
#include <vector>
#include <numeric>
#include <climits>
#include <queue>

using namespace std;

#define INF INT_MAX

bool achaCaminhosAumento(Grafo g, vector<int> m, vector<int> &d) {
    queue<int> fila;

    for (int i = 0; i < g.particao1; i++) {
        if (m[i] == i) {
            d[i] = 0;
            fila.push(i);
        } else {
            d[i] = INF;
        }
    }

    int k = INF;
    while (!fila.empty()) {
        int v = fila.front();
        fila.pop();

        if (d[v] < k) {
            for (int u : g.adj[v]) {
                if (m[u] == u && k == INF) {
                    k = d[v] + 1;
                } else if (d[m[u]] == INF) {
                    d[m[u]] = d[v] + 1;
                    fila.push(m[u]);
                }
            }
        }
    }

    return k != INF;
}

bool aumentaEmparelhamento(Grafo g, vector<int> &m, vector<int> &d, int v) {
    for (int u : g.adj[v]) {
        if (m[u] == u || (d[m[u]] == d[v] + 1 && aumentaEmparelhamento(g, m, d, m[u]))) {
            m[u] = v;
            m[v] = u;
            return true;
        }
    }
    d[v] = INF;
    return false;
 }


vector<int> hopcroftKarp(Grafo g) {
    vector<int> m(g.v);
    iota(m.begin(), m.end(), 0);
    vector<int> d(g.particao1);

    while (achaCaminhosAumento(g, m, d)) {
        for (int i = 0; i < g.particao1; i++) {
            if (m[i] == i) 
                aumentaEmparelhamento(g, m, d, i);
        }
    }

    return m;
}