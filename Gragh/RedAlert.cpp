//By S@ltyF1sh
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int G[510][510],vis[510],N,M,K,nums;
void dfs(int i){
    vis[i] = 1;
    for(int j = 0;j<N;j++){
        if(G[i][j] == 1 && vis[j] == 0){
            dfs(j);
        }
    }
}
int getSeparateBlock(){
    int n = 0;
    fill(vis,vis+N,0);
    for(int i=0;i<N;i++){
        if(vis[i]==0){n++;dfs(i);}
    }
    return n;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        G[a][b] = 1,G[b][a] = 1;
    }
    nums = getSeparateBlock();
    cin>>K;
    for(int i = 0;i<K;i++){
        int a;cin>>a;
        for(int i=0;i<N;i++)if(G[a][i])G[i][a]=G[a][i]=0;
        int k = getSeparateBlock();
        if(k > nums+1)
            cout<<"Red Alert: "<<"City "<<a<<" is lost!";
        else
            cout<<"City "<<a<<" is lost.";
        cout<<endl;
        nums = k;
    }
    if(nums == N)cout<<"Game Over.";
    return 0;
}