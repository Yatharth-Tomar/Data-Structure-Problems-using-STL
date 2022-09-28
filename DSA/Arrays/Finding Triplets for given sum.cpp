#include<bits/stdc++.h>
using namespace std;


pair<int,pair<int,int>> triplet(vector<int> v,int sum){
    int n = v.size();
    sort(v.begin(),v.end());
    for(int i =0;i<n;i++){
        int j = i+1;
        int k = n-1;
        while(j<k){
            if(v[i]+v[j]+v[k]<sum){
                j++;
            }
            else if(v[i]+v[j]+v[k]==sum){
                return {v[i],{v[j],v[k]}};
            }
            else{
                k--;
            }
        }
    }
    
    
}

int main(){
    vector<int> v{2,5,6,8,1,2,3,4};
    pair<int,pair<int,int>> p = triplet(v,19);
    cout<<"Required Triplet is {"<<p.first<<", "<<p.second.first<<", "<<p.second.second<<"}";
    
}
