#include <bits/stdc++.h>
using namespace std;
enum Color {WHITE, GREY, BLACK};
class Graph{
private:
    int V;
    list<int>* adj;
    bool DfsUtil(int v,int color[]);
public:
    Graph(int V);
    void addEdges(int v,int w);
    bool isCyclic();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdges(int v, int w) {
    adj[v].push_back(w);
    //cout<<"Yes ";
}
bool Graph::DfsUtil(int u, int *color) {
    color[u] = GREY;
    list<int>::iterator i;
    for(i = adj[u].begin();i != adj[u].end();i++){
        int v = *i;
        if(color[v] == GREY)
            return true;
        if(color[v] == WHITE && DfsUtil(v,color))
            return true;
    }
    color[u] = BLACK;
    return false;
}

bool Graph::isCyclic() {
    int *color = new int[V];
    for(int i=0;i<V;i++)
        color[i] = WHITE;
    for(int i=0;i<V;i++)
        if(color[i] == WHITE){
            if(DfsUtil(i,color))
                return true;
        }
    return false;
}
int main() {
    int n,m;
    cin>>n>>m;
    Graph g(n+1);
    for(int i=0;i<m;i++)
    {
        int a =0,b;
        cin>>a>>b;
        g.addEdges(a,b);
    }
    if(g.isCyclic())
        cout<<"1\n";
    else
        cout<<"0\n";
    return 0;
}
