#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    list<int>* adj;
    void topologicalUntl(int v,bool visited[], stack<int>& Stack);
public:
    Graph(int V);
    void addEdges(int v,int w);
    void topologySort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdges(int v, int w) {
    adj[v].push_back(w);
}

void Graph::topologicalUntl(int v, bool visited[], stack<int>& stack) {
    list<int>::iterator i;
    visited[v] = true;
    for(i = adj[v].begin(); i != adj[v].end();i++) {
        int u = *i;
        if (!visited[u]) {
            topologicalUntl(u, visited, stack);
        }
    }
    stack.push(v);
}

void Graph::topologySort() {
    stack<int> stack;
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]){
            topologicalUntl(i,visited,stack);
        }
    }
    for(int i=0;i<V-1;i++){
        cout<<stack.top()<<" ";
        stack.pop();
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    Graph g(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g.addEdges(a,b);
    }
    g.topologySort();
    return 0;
}
