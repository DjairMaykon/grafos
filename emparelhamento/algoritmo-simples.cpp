#include "algoritmo-simples.h"
#include "grafo.h"
#include <vector>
#include <numeric>

using namespace std;

bool achaCaminhoAumento(Grafo g, vector<int> &m, int v, vector<bool> seen = vector<bool>()) {
    if (seen.empty()) {
        seen = vector<bool>(g.v, false);
    }
    for (int u : g.adj[v]) {
        if (seen[u]) continue;
        seen[u] = true;
        if (m[u] == u || achaCaminhoAumento(g, m, m[u], seen)) {
            m[v] = u;
            m[u] = v;
            return true;
        }
    }
    return false;
}

vector<int> algoritmoSimples(Grafo g) {
    vector<int> m(g.v);
    iota(m.begin(), m.end(), 0);

    for (int i = 0; i < g.v; i++) {
        if (m[i] == i) {
            achaCaminhoAumento(g, m, i);
        }
    }

    return m;
}