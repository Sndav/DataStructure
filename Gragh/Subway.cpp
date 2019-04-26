// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int G[210][210],n,m,k;
vector<int> P[210];
int L[210];
int main(){
    freopen("/Users/hackboy/Code/C/in","r",stdin);
    cin>>n>>m>>k;
    memset(G,INF,sizeof(G));
    for(int i = 1;i<=n;i++)G[i][i]=0;
    for(int i=0;i<m;i++){
        int s,l,e;
        cin >> s;
        L[s] = 1;
        do {
            cin>>l>>e;
            G[s][e] = G[e][s] = l;
            s = e;
		} while (getchar() != '\n');
        L[e] = 1;
    }
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            for(int x = 1;k<=n;k++)
                G[i][x] = min(G[i][j]+G[j][x],G[i][x]);
    for(int i = 1;i<=n;i++){
        int M[10000];
        fill(M,M+n+1,-1);
        for(int j = 1;j<=n;j++)if(G[i][j]!=INF)
            M[2+G[i][j]/k] = max(M[2+G[i][j]/k],G[i][j]);
        for(int j = 1;j<=n;j++)if(G[i][j]!=INF)
            if(M[2+G[i][j]/k] == G[i][j]|| L[j] || i == j)
                P[i].push_back(j);
    }
    int q;cin>>q;
    while(q--){
        int s;cin>>s;
        for(auto iter = P[s].begin();iter!=P[s].end();++iter)
            cout<<*iter<<" ";
        cout<<endl;
    }
    return 0;
}