#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<stack>
#define INF 2100000000
#define ll long long
#define clr(x)  memset(x,0,sizeof(x))
#define maxclr(x)  memset(x,127,sizeof(x))

using namespace std;

#define M 100010

struct tree2{
    tree2 *son[2],*fa;
    int n,siz,num;
}*root,dizhi[M],*null,*Null;

#define lson son[0]
#define rson son[1]

int n,t;

tree2 *newtree(tree2 *fa,int x)
{
    tree2 *tree=&dizhi[t++];
    tree->siz=tree->num=1;
    tree->lson=tree->rson=Null;
    tree->n=x;
    tree->fa=fa;
    return tree;
}

void pushup(tree2 *tree)
{
    if(tree==null)return ;
    tree->siz=tree->num+tree->lson->siz+tree->rson->siz;
}

void rotate(tree2 *tree,int x)
{
    tree2 *fa=tree->fa;
    fa->son[x^1]=tree->son[x];
    if(tree->son[x]!=Null)tree->son[x]->fa=fa;
    fa->fa->son[fa->fa->son[1]==fa]=tree;
    tree->fa=fa->fa;
    fa->fa=tree;
    tree->son[x]=fa;
    pushup(fa);
}

void splay(tree2 *tree,tree2 *goal)
{
    if(tree==goal)return ;
    while(tree->fa!=goal)
    {
        tree2 *fa=tree->fa,*gfa=fa->fa;
        if(gfa==goal)
        {
            rotate(tree,fa->son[0]==tree);
            break;
        }
        int x=gfa->son[1]==fa;
        if((fa->son[1]==tree)==x)
        {
            rotate(fa,x^1);
            rotate(tree,x^1);
        }
        else
        {
            rotate(tree,x);
            rotate(tree,x^1);
        }
    }
    pushup(tree);
    if(goal==null)root=tree;
}

void insert(int k)
{
    if(root==NULL)
    {
        root=newtree(null,k);
        return ;
    }
    tree2 *temp=root;
    while(temp->son[temp->n<k]!=Null)
    {
        if(temp->n==k)break;
        temp=temp->son[temp->n<k];
    }
    if(temp->n==k)
    {
        temp->siz++;
        temp->num++;
        splay(temp,null);
        return;
    }
    temp->son[temp->n<k]=newtree(temp,k);
    splay(temp->son[temp->n<k],null);
}

tree2 *find(int k){
    tree2 *temp=root;
    if(root == NULL || root == Null)return Null;
    while(temp->son[temp->n<k])
    {
        if(temp->n==k)break;
        temp=temp->son[temp->n<k];
    }
    if(temp != Null) splay(temp,null);
    return temp;
}

void dele(int k)
{
    tree2 *temp=find(k);
    splay(temp,null);
    tree2 *temp2 = root;
    if(temp2->lson == Null){
        root = temp2->rson;
    }
}

int query(int k)
{
    tree2 *temp=root;
    int num=0;
    while(temp->n!=k)
    {
        int x=temp->n<k;
        if(x==1)num+=temp->lson->siz+temp->num;
        temp=temp->son[x];
    }
    num+=temp->lson->siz;
    splay(temp,null);
    return num+1;
}

int query_rank(int k)
{
    tree2 *temp=root;
    int num=temp->lson->siz;
    while(!(k>num&&k<=num+temp->num))
    {
        if(k>num)
        {
            k-=num+temp->num;
            temp=temp->rson;
        }
        else temp=temp->lson;
        num=temp->lson->siz;
    }
    splay(temp,null);
    return temp->n;
}


int get_pre(int k,int &c)
{
    tree2 *tree=root;
    int ret=0;
    while(tree->lson!=Null||tree->rson!=Null)
    {
        if(tree->n>=k)
            if(tree->lson!=Null)tree=tree->lson;
            else break;
        else
        {
            if(tree->n >= ret) c = 1;
            ret=max(ret,tree->n);
            if(tree->rson!=Null)tree=tree->rson;
            else break;
        }
    }
    if(tree->n >= ret) c = 1;
    if(tree->n<k)ret=max(ret,tree->n);
    splay(tree,null);
    return ret;
}

int get_next(int k ,int &c)
{
    tree2 *tree=root;
    int ret=INF;
    while(tree->lson!=Null||tree->rson!=Null)
    {
        if(tree->n<=k)
            if(tree->rson!=Null)tree=tree->rson;
            else break;
        else
        {
            if(tree->n <= ret) c = 1;
            ret=min(ret,tree->n);
            if(tree->lson!=Null)tree=tree->lson;
            else break;
        }
    }
    if(tree->n <= ret) c = 1;
    if(tree->n>k)ret=min(ret,tree->n);
    splay(tree,null);
    return ret;
}

int main()
{
    freopen("/Users/hackboy/Code/C/in","r",stdin);
    freopen("/Users/hackboy/Code/C/out","w",stdout);
    map<int,string> MA;
    int cnt = 0,maxa=0,mina=0x3f3f3f3f;
    int n;scanf("%d",&n);
    Null=&dizhi[t++];null=&dizhi[t++];    
    for(int i=1;i<=n;i++)
    {
        int c,x;scanf("%d",&c);
        if(c == 1){
            string tmp;
            int x;
            cin>>tmp>>x;
            x = -x;
            MA[x] = tmp;
            insert(x);
            cnt++; 
            continue;
        }
        scanf("%d",&x);x = -x;
        // cout<<x<<endl;
        tree2* tmp;
        // cout<<c<<"xxxx\n";
        switch(c)
        {
            case 2:
                if(find(x)==Null){printf("NO\n");break;}
                cnt--;
                dele(x);
                cout<<MA[x]<<endl;
                break;
            case 3:
                if(find(x)==Null){printf("NO\n");break;}
                cout<<query(x)<<endl;
                break;
            case 4:
                x = -x;
                if(x>cnt || x<=0){printf("NO\n");break;}
                cout<<MA[query_rank(x)]<<endl;
                break;
            case 5:
                if((tmp = find(x)) == Null){
                        cout<<"NO\n";
                }else{
                    splay(tmp,null);
                    if(root->lson != Null)
                        cout<<MA[root->lson->n]<<endl;
                    else
                        cout<<"NO\n";
                }
                break;
            case 6:
                if((tmp = find(x)) == Null){
                        cout<<"NO\n";
                }else{
                    splay(tmp,null);
                    if(root->rson != Null)
                        cout<<MA[root->rson->n]<<endl;
                    else
                        cout<<"NO\n";
                }
                break;
        }
    }
    return 0;
}