#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



const int maxn=100;

char M[maxn][35];

struct tree{
    int l,r;
    int val,add;
    int max[2];
    int min[2];
} t[4*maxn+2];

void update(int p){
    // t[p].max = max(t[p*2+1],t[p*2]);
    // t[p].min = min(t[p*2+1],t[p*2]);
    if(t[p*2+1].max[0] > t[p*2].max[0]){
        t[p].max[0] = t[p*2+1].max[0];
        t[p].max[1] = t[p*2+1].max[1];
    }else{
        t[p].max[0] = t[p*2].max[0];
        t[p].max[1] = t[p*2].max[1];
    }
    if(t[p*2+1].min[0] < t[p*2].min[0]){
        t[p].min[0] = t[p*2+1].min[0];
        t[p].min[1] = t[p*2+1].min[1];
    }else{
        t[p].min[0] = t[p*2].min[0];
        t[p].min[1] = t[p*2].min[1];
    }
    if(t[p*2+1].max[0] == t[p].max[0] && t[p*2+1].max[1] < t[p].max[1]){
        t[p].max[1] = t[p*2+1].max[1];
    }
    if(t[p*2].max[0] == t[p].max[0] && t[p*2].max[1] < t[p].max[1]){
        t[p].max[1] = t[p*2].max[1];
    }
}

void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].val=1;
        t[p].max[0] = 1;
        t[p].max[1] = l;
        t[p].min[0] = 1;
        t[p].min[1] = l;
        return;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    update(p);
    // t[p].val=t[p*2].val+t[p*2+1].val;
} 

void spread(int p){
    if(t[p].add){
        t[p*2].max[0] += t[p].add;
        t[p*2+1].max[0] += t[p].add;
        t[p*2].min[0] += t[p].add;
        t[p*2+1].min[0] += t[p].add;
        // t[p*2].val+=t[p].add*(t[p*2].r-t[p*2].l+1);
        // t[p*2+1].val+=t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
        t[p*2].add+=t[p].add;
        t[p*2+1].add+=t[p].add;
        t[p].add=0;
    }
    update(p);
}

void change(int p,int x,int y,int z){
    if(x<=t[p].l && y>=t[p].r){
        // t[p].val+=(int)z*(t[p].r-t[p].l+1);
        t[p].max[0] += z;
        t[p].min[0] += z;
        t[p].add+=z;
        return;
    }
    spread(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(x<=mid) change(p*2,x,y,z);
    if(y>mid) change(p*2+1,x,y,z);
    // t[p].val=t[p*2].val+t[p*2+1].val;  
    update(p); 
}

int* ask_max(int p,int x,int y){
    if(x<=t[p].l && y>=t[p].r) return t[p].max;
    spread(p);
    int mid=(t[p].l+t[p].r)>>1;
    int a[2]={-2333333,0},*ans;ans = a;
    if(x<=mid){
        int *ret = ask_max(p*2,x,y);
        if(ret[0]>ans[0])
            ans = ret;
        else if(ret[0] == ans[0] && ret[1] < ans[1])
            ans = ret;
    }
    if(y>mid){
        int *ret = ask_max(p*2+1,x,y);
        if(ret[0]>ans[0])
            ans = ret;
        else if(ret[0] == ans[0] && ret[1] < ans[1])
            ans = ret;
    }
    return ans;
}

int * ask_min(int p,int x,int y){
    if(x<=t[p].l && y>=t[p].r) return t[p].min;
    spread(p);
    int mid=(t[p].l+t[p].r)>>1;
    int a[2]={0x3f3f3f3f,0},*ans;ans = a;
    if(x<=mid){
        int *ret = ask_min(p*2,x,y);
        if(ret[0]<a[0])
            ans = ret;
        else if(ret[0] == ans[0] && ret[1] < ans[1])
            ans = ret;
    }
    if(y>mid){
        int *ret = ask_min(p*2+1,x,y);
        if(ret[0]<ans[0])
            ans = ret;
        else if(ret[0] == ans[0] && ret[1] < ans[1])
            ans = ret;
    }
    return ans;
}

int Harem(int l,int r){
    if(r-l<2) return 0;
    if(r-l >= 50) return 1;
    vector<int> A;
    for(int i = l;i<=r;i++){
        A.push_back(ask_max(1,i,i)[0]);
    }
    sort(A.begin(),A.end());
    int flag = 0;
    for(int i = 0;i<A.size()-2;i++){
        if(A[i] + A[i+1] > A[i+2]){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    freopen("/Users/hackboy/Code/C/in","r",stdin);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",M[i]);
    build(1,1,n);
    int q;scanf("%d",&q);
    for(int i = 0;i<q;i++){
        string s;
        cin>>s;
        // cout<<s;
        if(s == "Battle"){
            int l,r,p;scanf("%d%d%d",&l,&r,&p);
            change(1,l,r,p);
        }else if(s == "Event"){
            int i,p;scanf("%d%d",&i,&p);
            change(1,i,i,p);
        }else if(s == "BF"){
            int l,r;scanf("%d%d",&l,&r);
            int *x = ask_max(1,l,r);
            cout<<M[x[1]]<<" "<<x[0];
            printf("\n");
        }else if(s == "GC"){
            int l,r;scanf("%d%d",&l,&r);
            int *x = ask_min(1,l,r);
            cout<<M[x[1]]<<" "<<x[0];
            printf("\n");
        }else if(s == "Harem?"){
            int l,r;scanf("%d%d",&l,&r);
            puts(Harem(l,r)?"Yes":"No");
        }
    }
    return 0;
}