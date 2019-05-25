#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minsta;
int cnt;
int allcnt;

struct Node{
    int key;
    int size;
    int priority;
    Node *left;
    Node *right;
    int lazy;
};

Node tmp = {0,0,0,0,0,0};
Node* Null = &tmp;

Node *root = Null;    //根节点


void update(Node* &node){
    if(node == Null)return;
    if(node->left != Null){
        if(node->right != Null){
            node->size = node->left->size+node->right->size+1;
        }else{
            node->size = node->left->size+1;
        }
    }else{
        if(node->right != Null)
            node->size = node->right->size +1;
        else
            node->size = 1;
    }
    
}


Node* pushdown(Node* &node){
    if(node->lazy == 0)return node;
    if(node == Null) return Null;
    node->key += node->lazy;
    if(node->key < minsta){
        node->lazy = 0;
        cnt += node->left->size + 1;
        return node->right!=NULL?node->right:Null;
    }
    if(node->left != Null){
        node->left->lazy += node->lazy;
        node->left = pushdown(node->left);
        update(node->left);
    }
    if(node->right != Null){
        node->right->lazy += node->lazy;
        node->right = pushdown(node->right);
        update(node->right);
    }
    node->lazy = 0;
    update(node);
    return node;
}

void zig(Node * &node){ //右旋
    Node *x = node->left;
    node->left = x->right;
    x->right = node;
    node = x;
    update(node);
}

void zag(Node* &node){ //左旋
    Node *x = node->right;
    node->right = x->left;
    x->left = node;
    node = x;
    update(node);
}
void insert(Node* &root, int key){
    int priority = rand();
    if(root == Null){
         Node *node = new Node;
         node->key = key;
         node->priority = priority;
         node->left = node->right = Null;
         node->size = 1;
         node->lazy = 0;
         root = node;
    }
    else if(key <= root->key){
        insert(root->left, key);
        update(root);
        if(root->left->priority < root->priority)
            zig(root); //右旋
    }
    else{
        insert(root->right, key);
        update(root);
        if(root->right->priority < root->priority)
            zag(root); //左旋
    }
    update(root);
}

void add(int N){
    root->lazy += N;
}

int Kth(Node* &node ,int k){
    if(node == Null) return -1;
    if(node->right->size >= k){
        return Kth(node->right,k);
    }else if(node->right->size + 1 == k){
        return node->key;
    }else {
        return Kth(node->left,k - node->right->size -1);
    }
}

int main(){
    srand(time(0));
    // minsta = 50;
    // insert(root,94);
    // add(-50);
    // root = pushdown(root);
    int n;
    freopen("/Users/hackboy/Code/C/in","r",stdin);
    scanf("%d %d\n",&n,&minsta);
    for(int i=0;i<n;i++){
        char O;int x;
        scanf("%c %d\n",&O,&x);
        // printf("====>%c %d\n",O,x);
        switch (O){
        case 'I':
            allcnt++;
            if(x<minsta)break;
            insert(root,x);
            break;
        case 'A':
            add(x);
            root = pushdown(root);
            break;
        case 'S':
            add(-x);
            root = pushdown(root);
            break;
        case 'F':
            if(root->size < x)printf("-1\n");
            else printf("%d\n",Kth(root,x));
            break;
        }
    }
    update(root);
    printf("%d",allcnt-root->size);

}