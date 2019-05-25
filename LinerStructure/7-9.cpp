// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <int> G[10005];
int vis[10005];
int depth[10005];
int n, m, k;
int maxDep, ansNode;
void BFS(int num){
    maxDep=0;ansNode=0;
    memset(vis, 0, sizeof(vis));
    memset(depth, -1, sizeof(depth));
    queue<int> q;
    q.push(num);
    vis[num]=1;
    depth[num]=maxDep;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int j=0;j<G[x].size();j++){ // 遍历
            int i = G[x][j];
            if(vis[i]==0){
                vis[i] = 1;
                q.push(i);
                depth[i] = depth[x]+1;
                if(depth[i]>maxDep){ // 更新
                    maxDep = depth[i];
                    ansNode = i;
                }else if(depth[i]==maxDep)
                    if(ansNode>i)
                        ansNode = i;
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;i++){
        int m1, m2;
        scanf("%d %d", &m1, &m2);
        G[m1].push_back(m2);
        G[m2].push_back(m1);
    }
    for(int i=0;i<k;i++){
        int x;
        scanf("%d", &x);
        BFS(x);
        if(maxDep==0){
            printf("0\n");
        }else{
            printf("%d\n", ansNode);
        }

    }
    return 0;
}