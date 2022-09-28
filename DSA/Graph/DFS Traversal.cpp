#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    list<int> *l;
    int V;
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i,int j,bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    void print(){
        for(int i =0;i<V;i++){
            cout<<i<<" -> ";
            for(auto nbr:l[i]){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
    void  dfsHelper(int node,bool *visited){
        visited[node]= true;
        cout<<node<<", ";
        for(auto nbr: l[node]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
        
        
        if(!visited[node]){
            
        }
    }
    
    
    void dfs(int source){
        bool *visited = new bool[V]{false};
        dfsHelper(source,visited);
    }
};

int main(){
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.print();
    g.dfs(1);
}
