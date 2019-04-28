// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int G[210][210],n,m,k,C[210][210];
int L[3010];
int main(){
    freopen("/Users/hackboy/Code/C/in","r",stdin);
    cin>>n>>m>>k;
    memset(G,INF,sizeof(G));
    for(int i = 1;i<=n;i++)G[i][i]=0;
    for(int i=0;i<m;i++){
        int s,l,e;
        scanf("%d",&s);
        L[2*i] = s;
        do {
            scanf("%d%d",&l,&e);
            if(G[s][e] == INF || G[s][e] > l){
                G[s][e] = G[e][s] = l;
            }
            s = e;
		} while (getchar() != '\n');
        L[2*i+1] = s;
    }
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            for(int x = 1;x<=n;x++)
                G[i][x] = min(G[i][j]+G[j][x],G[i][x]);

    for(int i = 1;i<=n;i++){
        for(int j=0;j<2*m;j++)
            if(G[i][L[j]] < INF)
                C[i][L[j]] = 1;
        for(int j = 1;j<=n;j++){
            if(i != j){
                if(G[i][j] >= INF)continue;
                int flag = 0;
                for(int a = 1;a<=n;a++){
                    if(a != j && a!= i && G[i][a] < INF && G[i][a]/k == G[i][j]/k && G[i][a] > G[i][j]){
                        flag = 1;
                        break;
                    }
                }
                if(!flag)C[i][j] = 1;
            }
        }
    }
    int d;cin>>d;
    int Q[n],head = 0, tail = 0;
    while(d--){
        int ans[210];fill(ans,ans+n+1,0);
        // queue<int> Q;
        int start;cin>>start;
        head = tail = 0;
        Q[0] = start;
        ans[start] = 1;
        while(head<=tail){
            for(int i = 1;i<=n;i++)
                if(C[Q[head]][i] && !ans[i])
                    Q[++tail] = i,
                    ans[i] = 1;
            head++;
        }
        int flag = 0;
        for(int j = 1; j <=n; ++j)
            if(ans[j])
            {
                if(flag)
                    printf(" ");
                else
                    flag = 1;
                printf("%d", j);
            }
        printf("\n");
    }

    return 0;
}