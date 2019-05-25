
#include<iostream>
using namespace std;
int in[31],post[31];
typedef struct TNode{
	int val;
	struct TNode *left;
	struct TNode *right;
}TNode,*Tree;
Tree Build(int *in,int *post,int n){
	if(n <= 0)
		return NULL;
	int *p = in;
	while(p){
		if(*p == *(post + n - 1))
			break;
		p++;
	}
	Tree T = new TNode;
	T->val = *p;
	int len = p - in;
	T->left = Build(in,post,len);
	T->right = Build(p + 1,post + len,n - len - 1);
	return T; 
}
void PreOrder(Tree T){
	if(T){
		printf(" %d",T->val);
		PreOrder(T->left);
		PreOrder(T->right);
	}
	return;
}
int main(){
	int n;
	Tree T; 
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&post[i]);
	for(int i = 0;i < n;i++)
		scanf("%d",&in[i]);
	T = Build(in,post,n);
	printf("Preorder:");
	PreOrder(T);
	return 0;
}