// By Zelong Bai
/*
Note : DFS 会有BUG，最后一个点不能过，因为对于一个图
        1
      /   \
    2       3  -  7 
   /         \
  4  - 5   -  6
  第一次就会把3给放到vis，然后7就无法访问
  而后，用Vector做邻接表真的舒服。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> G[10010];
int N,M,vis[10010];
void addEdge(int x,int y){
    G[x].push_back(y);
    G[y].push_back(x);
}
int bfs(int i){
    struct T{
        int level,node;
        T(int level,int node):level(level),node(node){};
    };
    int sum=0;
    queue<T> Q;
    vis[i] = 1;
    Q.push(T(0,i));
    while(!Q.empty()){
        T node = Q.front();
        if(node.level > 6)break;
        sum++;
        for(const int &i: G[node.node]){
            if(!vis[i]){
                Q.push(T(node.level+1,i));
                vis[i] = 1;
            }
        }
        Q.pop();
    }
    return sum;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        addEdge(a,b);
    }
    for(int i = 1;i<=N;i++){
        int sum=0;
        fill(vis,vis+N+1,0);
        printf("%d: %.2f%%\n",i,(float)bfs(i)/(float)N*100);
    }
    return 0;
}