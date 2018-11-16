#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector < set<int> > graph;
std::set<int>::iterator it;#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector < set<int> > graph;
std::set<int>::iterator it;

graph omplir(int n, int m) {
    graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }
    return G;
}


void escriure(const graph& G) {
    int n = G.size();
    for (int i = 0; i < n; ++i) {
        
        for (it = G[i].begin(); it != G[i].end(); ++it) 
            cout << " " << *it;
            
        cout  << endl;
    }
}



//dfs de booleans buscant arbres
//cas baseT: un vertex es un arbre
//cas baseF: vertex ja visitat
//cas recursiu: si un vertex w adjacent a un vertex u pertany a un graph
 


bool arribo_a_cicle (graph &G, int u, int next_col, vector<int> vis_col) {

    if (vis_col[u] == -1) {
        vis_col[u] = next_col;
    
}

int contar_conexes (graph& G) {
    int n = G.size();
    int n_comp_connexes = 0;
    
    bool hi_ha_cicle = false;
    vector<int> vis_col(n, -1);      //-1: Not visited    0:colorA    1:colorB
    
    for (int i = 0; i < n and not hi_ha_cicle; ++i) {
           if (vis[i] == -1) {
             if (arribo_a_cicle(G, i, -1, vis_col)) 
               hi_ha_cicle = true;
             else
               ++n_comp_connexes;
           }
    }
    
    if (hi_ha_cicle)
        return -1;
    
    else 
        return n_comp_connexes;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        graph G = omplir(n, m);
        int n_comp_connexes = contar_conexes(G);
        
        if (n_comp_connexes == -1)
            cout << "no" << endl;
        else 
            cout << n_comp_connexes << endl;
    }
}
