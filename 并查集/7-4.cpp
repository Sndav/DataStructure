// By Zelong Bai
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_N 400500
int n,m;
// vector< pair<int,int> > datas;
int datas[MAX_N][2];
int dels[MAX_N];
vector<int> G[MAX_N];
int stack[MAX_N];
int s=0;
int flag[MAX_N];
int father[MAX_N];
int block=0;
int find(int x){
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];    
}
void add(int a,int b){
    if(father[a] == -1 || father[b] == -1)return;
    int fa=find(a),fb=find(b);
    if(fa!=fb){
        block--;
        father[fa]=fb;
    }
}
int check(){
    int cnt=0;
    for(int i = 0;i<n;i++)
        if(father[i] == i)cnt++;
    return cnt;
}
int main(){
    freopen("/Users/hackboy/Code/C/in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)father[i] = i;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        datas[i][0] = x;
        datas[i][1] = y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int k;scanf("%d",&k);
    for(int i = 0;i<k;i++){
        int t;scanf("%d",&t);
        dels[i]=t;
        flag[t] = 1;
        father[t] = -1;
    }
    for(int it = 0;it<m;++it){
        if( (!flag[datas[it][0]] && !flag[datas[it][1]]) ){
            add(datas[it][0],datas[it][1]);
        }
    }
    block = check();
    stack[s++] = block;
    for(int it=k-1;it>=0;--it){
        father[ dels[it] ]=dels[it];
        block++;
        for(int it2 = 0;it2 < G[dels[it]].size();++it2){
            add(dels[it],G[dels[it]][it2]);
        }
        stack[s++] = block;
    }
    while(s--){
        printf("%d\n",stack[s]);
    }
    return 0;
}