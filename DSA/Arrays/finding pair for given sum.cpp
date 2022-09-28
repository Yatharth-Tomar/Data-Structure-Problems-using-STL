#include<bits/stdc++.h>
using namespace std;

pair<int,int> doublet(vector<int> a,int sum){
    int n = a.size();
    unordered_set<int> u;
    for(int i =0;i<n;i++){
        u.insert(a[i]);
        
    }
    for(int i =0;i<n;i++){
        int x = sum - a[i];
        if(u.find(x)!=u.end()){
            return {a[i],x};
        }
    }
   
}

int main(){
    vector<int> v{1,7,5,2,3,9};
   
    pair<int,int> p =  doublet(v,12);
    cout<<"Required pair is : "<<p.first<<", "<<p.second;
    
}
