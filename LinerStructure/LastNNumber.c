/*
给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。

输入格式:
输入首先给出一个正整数K，随后是若干正整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。

输出格式:
输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息NULL。

输入样例:
4 1 2 3 4 5 6 7 8 9 0 -1
输出样例:
7
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ListNode {
    int val;
    struct ListNode * next;
} Node;
Node* newNode(int val){
    Node * tmp = malloc(sizeof(Node));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}
Node * scanl(){
    int val;scanf("%d",&val);
    Node *list = newNode(-1),*cur = list;
    while(val >= 0){
        Node * c = newNode(val);
        cur->next = c;
        cur = cur->next;
        scanf("%d",&val);
    }
    return list->next;
}
void printl(Node *l){
    while(l != NULL){printf("%d ",l->val);l = l->next;}
    printf("\n");
}
Node* getLastN(Node *l,int n){
    Node * c = l;
    for(int i=0;i<n-1;i++)if(c->next == NULL)
        return NULL;
    else
        c = c->next;
    while(c->next != NULL){
        c = c->next;
        l = l->next;
    }
    return l;
}
int main(){
    int n;scanf("%d",&n);
    Node * LastN = getLastN(scanl(),n);
    if(LastN == NULL) printf("NULL");
    else printf("%d",LastN->val);
    return 0;
}