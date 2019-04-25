// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct Arc{
    int weight;
    int nextNode;
    Arc(int weight,int nextNode):weight(weight),nextNode(nextNode){};
};
struct Node{
    int EC=0,LC=INF;
};
vector<Arc> G[110]; // 邻接表
vector<Arc> G2[110]; // 邻接表
int N,M,in[110],out[110],lv;
Node node[110];
bool check(int i,int j){
    return node[i].EC == node[i].LC && node[j].EC == node[j].LC;
}
void printArr(int *arr,int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int f,e,w;cin>>f>>e>>w;
        in[e]++;out[f]++;
        G[f].push_back(Arc(w,e));
        G2[e].push_back(Arc(w,f));
    }
    // printArr(in,N);
    queue<int> Q;
    int cnt=0;
    for(int i=1;i<=N;i++)if(in[i]==0){
        Q.push(i);
        node[i].EC = 0;
        cnt++;
    }
    while(!Q.empty()){
        lv = Q.front();
        vector<Arc> Vertex = G[lv];
        int ow = node[lv].EC;Q.pop();
        for(auto iter=Vertex.begin();iter != Vertex.end();++iter){
            if(--in[iter->nextNode] == 0){
                Q.push(iter->nextNode);
                cnt++;
            }
            node[iter->nextNode].EC = max(node[iter->nextNode].EC,iter->weight+ow);
        }
    }
    if(cnt<N){
        cout<<"0"<<endl;
        return 0;
    }
    node[lv].LC = node[lv].EC;
    for(int i=1;i<=N;i++)if(out[i]==0){
        Q.push(i);
    }
    while(!Q.empty()){
        int id = Q.front();
        vector<Arc> Vertex = G2[id];
        int ow = node[id].LC;Q.pop();
        for(auto iter=Vertex.begin();iter != Vertex.end();++iter){
            if(--out[iter->nextNode] == 0)
                Q.push(iter->nextNode);
        node[iter->nextNode].LC = min(node[iter->nextNode].LC,ow-iter->weight);
        }
    }
    cout<<node[lv].EC<<endl;
    for(int i = 1;i<=N;i++){
        vector<Arc> Vertex = G[i];
        for(auto iter=Vertex.rbegin();iter != Vertex.rend();++iter){ // 输入数据相反QvQ
            if(iter->weight == node[iter->nextNode].LC - node[i].EC)cout<<i<<"->"<<iter->nextNode<<endl;
        }
    }
    return 0;
}