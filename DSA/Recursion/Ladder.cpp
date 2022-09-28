#include<bits/stdc++.h>
using namespace std;

int ways(int N){
	if(N<0){
		return 0;
	}
    if(N == 0){
        return 1;
    }
    
    int ans = ways(N-3)+ways(N-2)+ways(N-1);
    return ans;


}
int main(){
    int N;
    cin>>N;
   int n = ways(N);
   cout<<"Number of ways to reach the destination ladder is "<<n;
}
