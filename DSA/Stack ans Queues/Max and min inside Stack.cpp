#include<bits/stdc++.h>
using namespace std;
int maxN = INT_MIN;
int maxP = INT_MIN;
int minP = INT_MAX;
int minN = INT_MAX;
void maxM(){
   cout<<maxN<<endl; 
}
void minM(){
    cout<<minN<<endl;
}

int main(){
    stack<int> s;
    string c;
    int N;
    cin>>N;
   int count=0;
    
    
    for(int i =0;i<N;i++){
       cin>>c;
 
    
   
    
        if(c=="Add"){
          
            int x;
            cin>>x;
            maxP = maxN;
            maxN = max(maxN,x);
            minP = minN;
            minN = min(minN,x);
            s.push(x);
           
        }
        else if(c=="Remove"){
          
            if(s.empty()){
                cout<<"Invalid"<<endl;
               
            }
            else{
                
            if(s.top()==maxN){
                maxN = maxP;
             }
           
            if(s.top()==minN){
                minN = minP;
            }
            s.pop();
                
            }
            
            
            
         
        }
       else if( c=="CallMax"){
       
            if(s.empty()){
                cout<<"Invalid"<<endl;
               
            }
            else{
                maxM();
            }
         
        }
        else if(c=="CallMin"){
        
            if(s.empty()){
                cout<<"Invalid"<<endl;
                
            }
            else{
                minM();
            }
            
          
        }
       
            
   
    
        
    }
    
}
