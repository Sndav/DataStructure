// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,start,stop;
int Gt[510][510],Gd[510][510];
int cnt[510],pre[510],vis[510];
int main(){
    cin>>N>>M;
    memset(Gt,INF,sizeof(Gt));
    memset(Gd,INF,sizeof(Gd));
    for(int i=0;i<M;i++){
        int v1,v2,ow,len,time; // ow : one way?
        cin>>v1>>v2>>ow>>len>>time;
    }
    cin>>start>>stop;
}