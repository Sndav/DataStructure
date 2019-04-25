// By Zelong Bai
// Dijkstra
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,G[110][110],vis[110],d[110];
struct Node{int v,d;};
bool operator < (Node a,Node b){
    return a.d>b.d;
}
void printArr(int *arr,int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>N>>M;
    memset(G,INF,sizeof(G));
    for(int i=1;i<=N;i++)G[i][i]=0;
    for(int i=0;i<M;i++){
        int n1,n2,w;
        cin>>n1>>n2>>w;
        G[n1][n2] = G[n2][n1] = w;
    }
    int minV=INF,minD=INF;
    for(int j = N;j>=1;j--){
        int maxD = 0;
        fill(d,d+N+1,INF);
        fill(vis,vis+N+1,0);
        d[j] = 0;
        priority_queue<Node> Q;
        Q.push((Node){j,0});
        while(!Q.empty()){
            // printArr(d,N);
            Node n = Q.top();Q.pop();
            int v = n.v;
            if(vis[v])continue;
            vis[v] = 1;
            for(int i = 1;i<=N;i++){
                if(d[i] > d[v]+G[v][i]){
                    d[i] = d[v]+G[v][i];
                    // maxD = max(maxD,d[i]);
                    Q.push((Node){i,d[i]});
                }
            }
            // printArr(d,N);
        }
        for(int i = 1;i<=N;i++)maxD = max(maxD,d[i]);
        // printArr(d,N);
        // cout<<maxD<<endl;
        if(maxD <= minD)minD = maxD,minV = j;
    }
    if(minD == INF){
        cout<<"0"<<endl;
        return 0;
    }
    cout<<minV<<" "<<minD;
    return 0;
}