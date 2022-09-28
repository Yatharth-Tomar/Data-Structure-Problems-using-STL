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
    bool dfs(int node,bool *visited,int parent){
        visited[node] = true;
        for(auto nbr:l[node]){
            if(!visited[nbr]){
                bool nbrFoundCycle = dfs(nbr,visited,node);
                if(nbrFoundCycle){
                    return true;
                }
                
            }
            else if(nbr!= parent){
                return true;
            }
            
            
            
        }
        return false;
        
    }
    
    bool cycle(){
        bool *visited = new bool[V]{false};
        return dfs(0,visited,-1);//source node,visited array and parent node
    }    
};

int main(){
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(3,4);
   
    g.print();
    if(g.cycle()){
        cout<<endl<<"cyclic Graph!";
    }else{
        cout<<endl<<"Not a cyclic graph";
    }
}
