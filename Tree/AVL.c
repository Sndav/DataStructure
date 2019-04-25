#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct TreeNode{
    int val,height;
    struct TreeNode *left,*right;
} Node;
int max(int a,int b){
    return a>b?a:b;
}
Node * newNode(int val){
    Node * node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}
int Height(Node * T){
    return T==NULL?0:T->height;
}
Node * LL(Node * T){
    Node *L = T->left,*R = T->right;
    T->left = L->right;
    L->right = T;
    T->height = max(Height(T->right),Height(T->left))+1;
    L->height = max(Height(L->right),Height(L->left))+1;
    return L;
}
Node * RR(Node * T){
    Node *L = T->left,*R = T->right;
    T->right = R->left;
    R->left = T;
    T->height = max(Height(T->right),Height(T->left))+1;
    R->height = max(Height(R->right),Height(R->left))+1;
    return R;
}
Node * LR(Node *T){
    T->left = RR(T->left);
    return LL(T);
}
Node * RL(Node *T){
    T->right = LL(T->right);
    return RR(T);
}
Node * insertNode(int val,Node * T){
    if(T == NULL) T = newNode(val);
    else{
        if(val < T->val){
            T->left = insertNode(val,T->left);
            if(Height(T->left) - Height(T->right) == 2){
                if(val < T->left->val)
                    T = LL(T);
                else
                    T = LR(T);
            }
        }
        if(val > T->val){
            T->right = insertNode(val,T->right);
            if(Height(T->left)-Height(T->right) == -2){
                if(val > T->right->val)
                    T = RR(T);
                else
                    T = RL(T);
            }
        }
    }
    T->height = max(Height(T->right),Height(T->left))+1;
    return T;
}
int main(){
    Node * T = NULL;
    int n;
    scanf("%d",&n);
    while(n--){
        int t;
        scanf("%d",&t);
        T = insertNode(t,T);
    }
    printf("%d",T->val);
    return 0;
}