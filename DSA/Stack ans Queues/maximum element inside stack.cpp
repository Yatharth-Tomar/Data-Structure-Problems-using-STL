#include<bits/stdc++.h>
using namespace std;
int maxN = INT_MIN;
int maxP = INT_MIN;
void max(){
   cout<<maxN<<endl; 
}

int main(){
    stack<int> s;
    int c;
    int N;
    cin>>N;
    
    while(N>0){
    cin>>c;
    switch(c){
        case 1:{
            int x;
            cin>>x;
            maxP = maxN;
            maxN = max(maxN,x);
            s.push(x);
            break;
        }
        case 2:{
            if(s.top()==maxN){
                maxN = maxP;
            }
            s.pop();
            
          break;  
        }
        case 3:{
            max();
           break; 
        }
            
    }
    N--;
        
    }
    
}
