// By Zelong Bai
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_N 200010
int n,m;
int G[MAX_N][MAX_N];
int father[MAX_N];
int find(int x){
    while(x!=father[x])
        x=father[x];
    return x;    
}
void add(int a,int b){
    int fa=find(a),fb=find(b);
    if(fa!=fb)
        father[fa]=fb;
}
int check(){
    for(int i = 1;i<=m;i++)
        father[i] = i;
    // for(auto iter = )
}
int main(){
    return 0;
}