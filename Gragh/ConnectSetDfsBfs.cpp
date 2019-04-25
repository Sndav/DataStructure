#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int G[15][15],vis[15],N,E;
void dfs(int i){
    cout<<i<<" ";
    vis[i] = 1;
    for(int j = 0;j<N;j++){
        if(G[i][j] == 1 && vis[j] == 0){
            dfs(j);
        }
    }
}
void bfs(int i){
    queue<int> Q;
    vis[i] = 1;
    Q.push(i);
    while(!Q.empty()){
        int i = Q.front();
        cout<<i<<" ";
        Q.pop();
        for(int j = 0;j<N;j++){
            if(G[i][j] == 1 && vis[j] == 0){
                Q.push(j);
                vis[j] = 1;
            }
        }
    }
}
int main(){
    cin>>N>>E;
    for(int i=0;i<E;i++){
        int a,b;cin>>a>>b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    for(int i=0;i<N;i++){
        if(vis[i]==0){cout<<"{ ";dfs(i);cout<<"}"<<endl;}
    }
    fill(vis,vis+N,0);
    for(int i=0;i<N;i++){
        if(vis[i]==0){cout<<"{ ";bfs(i);cout<<"}"<<endl;}
    }
    return 0;
}