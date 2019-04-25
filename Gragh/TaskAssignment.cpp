// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int G[110][110],N,in[110],cnt=0;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int num;cin>>num;
        while(num--){
            int a;cin>>a;
            G[a-1][i] = 1;
            in[i]++;
        }
    }
    queue<int> Q;
    for(int i = 0;i<N;i++)if(in[i] == 0)
        Q.push(i);
    while(!Q.empty()){
        int top = Q.front();Q.pop();
        cnt++;
        for(int i=0;i<N;i++)if(G[top][i] == 1){
            if(--in[i] == 0){
                Q.push(i);
            }
        }
    }
    cout<<(int)(cnt==N);
    return 0;
}