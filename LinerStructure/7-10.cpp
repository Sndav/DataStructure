#include<iostream>
using namespace std;
const int maxn=100001;
struct LNode{
    int data,next;
}Node[maxn];
int origin[maxn],ans[maxn];//origin数组依次存储链表中的结点地址，ans数组存储重排后的结点地址
 
int main()
{
    int index,n,t;
    scanf("%d%d",&index,&n);
    for(int i=0;i<n;i++)
    {
        cin>>t;
        cin>>Node[t].data>>Node[t].next;
    }
    int r=0;
    origin[r++]=index;
    t=Node[index].next;
    while(t!=-1)
    {
        origin[r++]=t;
        t=Node[t].next;
    }
    int left=0,right=r-1;
    r=0;
    while(left<=right) // 换位置
    {
        ans[r++]=origin[right--];
        if(left<=right)
            ans[r++]=origin[left++];
    }
    for(int i=0;i<r;i++)
    {
        if(i!=r-1)
            printf("%05d %d %05d\n",ans[i],Node[ans[i]].data,ans[i+1]);
        else
            printf("%05d %d -1\n",ans[i],Node[ans[i]].data);
    }
    return 0;
}