#include <bits/stdc++.h>
using namespace std;

void explore(int x,vector<vector<int> > &adj, vector<bool> &visited){
    visited[x] = true;
    for(std::size_t i =0; i< adj[x].size(); i++){
        int w = adj[x][i];
        if(!visited[w])
            explore(w, adj,visited);
    }
}

int component(vector<vector<int> > &adj) {
    //write your code here
    vector<bool> visited;
    visited.resize(adj.size());
    int sum =0;
    for(size_t i=0;i<adj.size();i++){
        if(!visited[i]){
            explore(i,adj,visited);
        sum++;
        }

    }
    return sum;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << component(adj);
}
