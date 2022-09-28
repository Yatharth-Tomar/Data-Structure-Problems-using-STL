#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1 = "(a+b)-(c)";
    stack<char> s;
    for(auto ch: s1){
        switch(ch){
            case '{': s.push(ch);
            break;
            case '(': s.push(ch);
            break;
            case '[':s.push(ch);
            break;
            case ')':{
                
            if(!s.empty() and s.top() == '(')
                        s.pop();
                        else
                        cout<<"Not Balanced";
                        break;
            
                
            }
            
            
            
            case '}':{
                   if(!s.empty()and s.top() == '{')
                        s.pop();
                        else
                         cout<<"Not Balanced";
                        break;
                
            }
            
            
            
         
            case ']':{
                 if(!s.empty()and s.top() == '[')
                        s.pop();
                        else
                        cout<<"Not Balanced";
                        break;
           
                
            }
             default:break;
            
           
        }
    }
    if(s.empty())
      cout<<"Balanced";
      else{
          cout<<"Not balanced";
      }
   
}
