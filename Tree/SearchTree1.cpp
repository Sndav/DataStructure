// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node{
    int val;
    struct Node *left,*right;
    Node(int val):val(val),left(NULL),right(NULL){};
};
Node * build(Node * T,int val){
    if(T == NULL)T = new Node(val);
    if(val > T->val)T->right = build(T->right,val);
    if(val < T->val)T->left = build(T->left,val);
    return T;
}
int vis[15];
bool search(Node * T,int val){
    if(T == NULL) return false;
    if(T->val == val){vis[T->val] = 1;return true;}
    if(!vis[T->val]) return false;
    if(val > T->val) return search(T->right,val);
    if(val < T->val) return search(T->left,val);
}
int main(){
    int N,L;
    cin>>N;
    while(N != 0){
        // cout<<"==============L:"<<N<<endl;
        cin>>L;
        Node *T = NULL;
        for(int i = 0;i<N;i++){
            int val;cin>>val;
            T = build(T,val);
        }
        for(int j=0;j<L;j++){
            fill(vis,vis+N,0);
            bool flag = true;
            for(int i = 0;i<N;i++){
                int val;cin>>val;
                // cout<<val<<" ";
                if(flag && !search(T,val))flag=false;
            }
            if(flag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cin>>N;
    }
    return 0;
}