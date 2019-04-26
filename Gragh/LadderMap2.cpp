// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,start,stop;
int Gt[510][510],Gd[510][510];
int cnt[510],pre[510],vis[510],d[510];
void SolveLen(){
    for(int i = 0; i < N; i++){
        vis[i] = 0;
        d[i] = Gd[start][i];
        pre[i] = start;
        cnt[i] = 1;
    }
    d[start] = 0;
    vis[start] = 1;
    pre[start] = -1;
    int t = N-1;
    int min=INF,minNode=1;
    while(t--){
        // printArr(d,N);
        min = INF;
        for(int i=0;i<N;i++){
            if(!vis[i] && d[i] < min)min = d[i],minNode = i;
        }
        vis[minNode] = 1;
        for(int i=0;i<N;i++){
            if(!vis[i] && d[i]> d[minNode]+Gd[minNode][i]){
                d[i] = d[minNode]+Gd[minNode][i];
                cnt[i] = cnt[minNode] + 1;
                pre[i] = minNode;
            }else if(!vis[i] && d[i] == d[minNode]+Gd[minNode][i]){
                if(cnt[i] > cnt[minNode]+1){
                    cnt[i] = cnt[minNode]+1;
                    pre[i] = minNode;
                }
            }
        }
    }
}
void SolveTime(){
    for(int i = 0; i < N; i++){
        vis[i] = 0;
        d[i] = Gt[start][i];
        pre[i] = start;
        cnt[i] = 1;
    }
    d[start] = 0;
    vis[start] = 1;
    pre[start] = -1;
    int t = N-1;
    int min=INF,minNode=1;
    while(t--){
        min = INF;
        // printArr(d,N);
        for(int i=0;i<N;i++){
            if(!vis[i] && d[i] < min)min = d[i],minNode = i;
        }
        vis[minNode] = 1;
        for(int i=0;i<N;i++){
            if(!vis[i] && d[i]> d[minNode]+Gt[minNode][i]){
                d[i] = d[minNode]+Gt[minNode][i];
                cnt[i] = cnt[minNode] + 1;
                pre[i] = minNode;
            }else if(!vis[i] && d[i] == d[minNode]+Gt[minNode][i]){
                if(cnt[i] > cnt[minNode]+1){
                    cnt[i] = cnt[minNode]+1;
                    pre[i] = minNode;
                }
            }
        }
    }
}
void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>N>>M;
    memset(Gt,INF,sizeof(Gt));
    memset(Gd,INF,sizeof(Gd));
    for(int i=0;i<M;i++){ // INPUT
        int v1,v2,ow,len,time; // ow : one way?
        cin>>v1>>v2>>ow>>len>>time;
		if(ow){
			if(Gt[v1][v2]>time)//去重
				Gt[v1][v2] = time;
			if(Gd[v1][v2]>len)//去重
				Gd[v1][v2] = len;
		}
		else{
			if(Gt[v1][v2]>time)//去重
				Gt[v1][v2] = Gt[v2][v1] = time;
			if(Gd[v1][v2]>len)//去重
				Gd[v1][v2] = Gd[v2][v1] = len;
		}
    }
    cin>>start>>stop;
    stack<int> S1,S2;int node,ts,ds;
    SolveLen();
    // printArr(d,N);
    // printArr(pre,N);
    node = stop;
    while(node != -1){
        S1.push(node);
        node=pre[node];
    }
    ds = d[stop];
    SolveTime();
    // printArr(d,N);
    // printArr(pre,N);
    ts = d[stop];
    node = stop;
    while(node != -1){
        S2.push(node);
        node=pre[node];
    }
    S1.pop();
    S2.pop();
    if(S1==S2){
        cout<<"Time = "<<ts<<"; Distance = "<<ds<<": "<<start;
        while(!S1.empty()){
            cout<<" => "<<S1.top();
            S1.pop();
        }
        cout<<endl;
    }else {
        cout<<"Time = "<<ts<<": "<<start;
        while(!S2.empty()){
            cout<<" => "<<S2.top();
            S2.pop();
        }
        cout<<endl;
        cout<<"Distance = "<<ds<<": "<<start;
         while(!S1.empty()){
            cout<<" => "<<S1.top();
            S1.pop();
        }
        cout<<endl;
    }
}