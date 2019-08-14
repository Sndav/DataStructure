// By Zelong Bai
// Floyd
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,G[110][110],D[110][110];
void printArr(int *arr,int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>N>>M;
    memset(G,INF,sizeof(G));
    memset(D,INF,sizeof(G));
    for(int i=1;i<=N;i++)D[i][i] = G[i][i]=0;
    for(int i=0;i<M;i++){
        int n1,n2,w;
        cin>>n1>>n2>>w;
        D[n1][n2] = D[n2][n1] = G[n1][n2] = G[n2][n1] = w;
    }
    for(int k = 1;k<=N;k++)
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=N;j++){
                D[i][j] = min(D[i][k] + D[k][j],D[i][j]);
            }
    for(int i = 1;i<=N;i++)
        printArr(D[i],N);
}