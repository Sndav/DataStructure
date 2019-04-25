// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,start,stop;
int Gl[510][510],Gt[510][510],pnl[510],pnt[510],vis[510],d[510],t[510];
// Gl Graph of length , Gt Graph of time
// pnl,pnt previous node
// d distance ,t time
// vis visited?
struct Node{int v,d,p;}; // v vertex,d distance from origin,p privious node
bool operator < (Node a,Node b){
    return a.d>b.d;
}
int main(){
    cin>>N>>M;
    memset(Gl,INF,sizeof(Gl));
    memset(Gt,INF,sizeof(Gt));
    for(int i=0;i<M;i++){
        int v1,v2,ow,len,time; // ow : one way?
        cin>>v1>>v2>>ow>>len>>time;
        if(ow)Gt[v1][v2] = time,Gl[v1][v2] = len;
        else  Gt[v1][v2] = Gt[v2][v1] = time,Gl[v1][v2] = Gl[v2][v1] = len;
    }
    cin>>start>>stop;
    // solve dis
    priority_queue<Node> Q;
    fill(d,d+N+1,INF);
    fill(vis,vis+N+1,0);
    d[start] = 0;
    pnl[start] = -1;
    pnt[start] = -1;
    Q.push((Node){start,0});
    while(!Q.empty()){
        // printArr(d,N);
        Node n = Q.top();Q.pop();
        int v = n.v;
        if(vis[v])continue;
        vis[v] = 1;
        for(int i = 1;i<=N;i++){
            if(d[i] > d[v]+Gl[v][i]){
                d[i] = d[v]+Gl[v][i];
                // maxD = max(maxD,d[i]);
                Q.push((Node){i,d[i]});
                pnl[i] = v;
            }
        }
    }
    fill(t,t+N+1,INF);
    fill(vis,vis+N+1,0);
    t[start] = 0;
    pnl[start] = -1;
    Q.push((Node){start,0});
    while(!Q.empty()){
        // printArr(d,N);
        Node n = Q.top();Q.pop();
        int v = n.v;
        if(vis[v])continue;
        vis[v] = 1;
        for(int i = 1;i<=N;i++){
            if(t[i] > t[v]+Gt[v][i]){
                t[i] = t[v]+Gt[v][i];
                // maxD = max(maxD,d[i]);
                Q.push((Node){i,t[i]});
                pnt[i] = v;
            }
        }
    }
    vector<int> tt,dd;
    int node = stop;
    while(node != -1){
        tt.push_back(node);
        node = pnt[node];
    }
    node = stop;
    while(node != -1){
        dd.push_back(node);
        node = pnl[node];
    }
    if(tt!=dd){
        cout<<"Time = "<<t[stop]<<": "<<start;
        for(auto iter = tt.rbegin()+1;iter!=tt.rend();++iter)
            cout<<" => "<<*iter;
        cout<<endl;
        cout<<"Distance = "<<d[stop]<<": "<<start;
        for(auto iter = dd.rbegin()+1;iter!=dd.rend();++iter)
            cout<<" => "<<*iter;
    }else{
        cout<<"Time = "<<t[stop]<<"; ";
        cout<<"Distance = "<<d[stop]<<": "<<start;
        for(auto iter = dd.rbegin()+1;iter!=dd.rend();++iter)
            cout<<" => "<<*iter;
    }
    return 0;
}