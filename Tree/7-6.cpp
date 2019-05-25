// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
struct node{
	int data;
	struct node *left;
	struct node *right;
}*root;
int pre[35],in[35];
vector<int> vec;
struct node *InPreToPro(int in[], int pre[],int il,int ir, int pl, int pr)
{
	if(pl > pr || il > ir)
		return NULL;
	int pos;
	for(int i = il; i <= ir ; i++)
	{
		if(in[i] == pre[pl])
		{
			pos = i;
			break;
		}
	}
	struct node * root = new node();
	root->data = pre[pl];
	root->left = InPreToPro(in,pre,il,pos - 1,pl + 1,pl + pos - il); 
	root->right = InPreToPro(in,pre,pos + 1,ir,pl + pos - il + 1,pr); 
	return root;
}
void bfs(struct node* root){
	queue<node*>qu;
	qu.push(root);
	vec.push_back(root->data);
	while(qu.empty() == 0){
		struct node * tmp = qu.front();
		qu.pop();
		if(tmp->right){
			qu.push(tmp->right);
			vec.push_back(tmp->right->data);
		}
		if(tmp->left){
			qu.push(tmp->left);
			vec.push_back(tmp->left->data);
		}
	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
		scanf("%d",&in[i]);
	for(int i = 1; i <= n; i ++)
		scanf("%d",&pre[i]);
	root = InPreToPro(in,pre,1,n,1,n); 
	bfs(root);
	for(int i = 0 ; i < n; i ++)
		printf("%d%c",vec[i]," \n"[i == n - 1]);
	return 0;
} 