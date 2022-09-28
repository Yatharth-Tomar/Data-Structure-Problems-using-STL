#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    list<pair<int,int>> *l;
    int V;

    Graph(int v){
    V = v;
    l= new list<pair<int,int>>[V];
    }
    void addEdge(int i,int j,int wt,bool undir = true){
        
        l[i].push_back({j,wt});
        if(undir){
            l[j].push_back({i,wt});
        }
    }
    
    void print(){
        for(int i =0;i<V;i++){
            cout<<i<<"-> ";
            for(auto nbr:l[i]){
                cout<<"("<<nbr.first<<","<<nbr.second<<"), ";
            }
            cout<<endl;
        }
    }
    
    int dijkstra(int src,int dest){
        vector<int> distance(V,INT_MAX);
        set <pair<int,int>> s;
        distance[src] = 0;
        s.insert({src,0});
        while(!s.empty()){
            auto it = s.begin();
            int node = it->first;
            int disTillNow = it->second;
            s.erase(it);
            
            for(auto nbrPair:l[node]){
                int nbr = nbrPair.first;
                int currentEdgeDistance = nbrPair.second;
                if(disTillNow + currentEdgeDistance < distance[nbr]){
                    auto f = s.find({nbr,distance[nbr]});
                    if(f != s.end()){
                        s.erase(f);
                    }
                    
                    distance[nbr] = disTillNow +currentEdgeDistance;
                    s.insert({nbr,distance[nbr]});
                    
                }
                
            }
        }
        for(int i=0;i<V;i++){
			cout<<"Node i "<<i <<" Dist "<<distance[i] <<endl;
		}
		return distance[dest];
    }
    
};

int main(){
    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);
	g.print();
	cout<<g.dijkstra(0,4)<<endl;
    
}
