#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char> s;
    string s2 = "((a)) + (a+b)";
    bool operator_found;
    for(auto ch: s2){
        if(ch!=')'){
            s.push(ch);
            
        }
        else{
            operator_found = false;
            
            while(!s.empty() and s.top()!='('){
                char top = s.top();
                if(top == '%'||top == '-'||top == '*'||top == '/'||top == '+'){
                    operator_found = true;
                }
                s.pop();
               
            }
            s.pop();
            if(operator_found ==false){
                cout<<"contains";
                exit(1);
            }
        }
                
    }
            
        
    cout<<"Do not contains";
 
}
