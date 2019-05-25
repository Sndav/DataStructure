// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct BNode* BTree;
struct BNode
{
    int data;
    BTree left;
    BTree right;
};
int a[1001],b[1001],c[1001];
int cnt=0,cnt2=0,ppx=1; // ppx输出空格
void Insert(BTree &t,int data){
    if(!t){
        BTree p=(BTree)malloc(sizeof(BTree));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        t=p;
    }
    else if(data<t->data)Insert(t->left,data);
    else if(data>=t->data)Insert(t->right,data);
}
void PreorderTraversal(BTree t){
    if(t){
        b[cnt++]=t->data;
        PreorderTraversal(t->left);
        PreorderTraversal(t->right);
    }
}
void PostorderTraversal(BTree t){ // 前序遍历镜像
    if(t){
        c[cnt2++]=t->data;
        PostorderTraversal(t->right);
        PostorderTraversal(t->left);
    }
}
void Traversal(BTree t){ 
    if(t){
        Traversal(t->left);
        Traversal(t->right);
        if(ppx)ppx=0;
        else cout<<" ";
        cout<<t->data;
    }
}
void PostTraversal(BTree t){ //后序遍历镜像
    if(t){
        PostTraversal(t->right);
        PostTraversal(t->left);
        if(ppx)ppx=0;
        else cout<<" ";
        cout<<t->data;
    }
}
int main()
{
    int n;
    cin>>n;
    BTree t;
    t=NULL;
    for(int i=0;i<n;i++){
        cin>>a[i];
        Insert(t,a[i]);
    }
    PreorderTraversal(t);
    PostorderTraversal(t);
    int f=0,p=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            f=1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(c[i]!=a[i]){
            p=1;
            break;
        }
    }
    if(f&&p)cout<<"NO"<<endl;
    else if(!f){
        cout<<"YES"<<endl;
        Traversal(t);
    }
    else if(!p){
        cout<<"YES"<<endl;
        PostTraversal(t);
    }
}