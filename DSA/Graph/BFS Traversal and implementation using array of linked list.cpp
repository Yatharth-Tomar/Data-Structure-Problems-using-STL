#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *l;
    
    //graph creation using array of doubly linked list
    Graph(int v){
        V = v;
        l = new list<int>[V];
        
    }
    void addEdge(int i,int j, bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    void printGraph(){
        for(int i =0;i<V;i++){
            cout<<i<<" -> ";
            for(auto nodes:l[i]){
                cout<<nodes<<", ";
            }
            cout<<endl;
        }
    }
    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int f = q.front();
            cout<<f<<endl;
            q.pop();
            
            for(auto nbrs:l[f]){
                if(!visited[nbrs]){
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
        }
    }
};

int main(){
    Graph g(8);
   
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.printGraph();
    cout<<endl;
    g.bfs(1);
}
