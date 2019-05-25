#include <stdio.h>
#include <stdlib.h>
#define MaxN 10
#define Null -1
struct node{
	char data;
	int left, right;
}T1[MaxN], T2[MaxN];
int check[MaxN];
int makeTree(struct node T[]){
	int n, root = -1, i;
	char cl, cr;
	scanf("%d\n", &n);
	if(n) {
		for(i = 0; i < n; i++)
			check[i] = 0;		//要重置为0，否则T2会出错
		for(i = 0; i < n; i++){
			scanf("%c %c %c\n", &T[i].data, &cl, &cr);
			if(cl != '-'){
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else T[i].left = Null;
			if(cr != '-'){
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else T[i].right = Null;
		}
		for(i = 0; i < n; i++){
			if(!check[i]) break;
		}
		root = i;
		
	}
	return root;
}
int isomorphic(int R1, int R2){
	//both empty
	if(R1 == Null && R2 == Null) 
		return 1;	
 
	//one of them is empty
	if((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null)) 
		return 0; 
 
	//roots are different
	if(T1[R1].data != T2[R2].data) 
		return 0;	
 
	//both have no left subtree
	if(T1[R1].left == Null && T2[R2].left == Null) 
		return isomorphic(T1[R1].right, T2[R2].right);		
 
	//no need to swap the left and right
	if((T1[R1].left != Null && T2[R2].left != Null) && (T1[ T1[R1].left ].data == T2[ T2[R2].left ].data))
		return ( isomorphic( T1[R1].left, T2[R2].left ) && isomorphic( T1[R1].right, T2[R2].right ) );
	//need to swap the left and right
	else 
		return ( isomorphic( T1[R1].left, T2[R2].right ) && isomorphic( T1[R1].right, T2[R2].left ) );
}
int main(){
	int R1, R2;
	R1 = makeTree(T1);
	R2 = makeTree(T2);
	if(isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");
	system("pause");
	return 0;
}