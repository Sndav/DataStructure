#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct PNode{
    int name;
    int arrive;
    int deal;
}PNode;
int circle[20000]={0};
int Hash(char *str){
   return (str[0]-65)*26*26+(str[1]-65)*26+(str[2]-65);
}
void unhash(int s){ // unhash
    printf("%c%c%c\n",s/26/26+65,s/26%26+65,s%26+65);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    PNode *p=(PNode*)malloc(sizeof(PNode)*n); // 分配空间
    int head=0,tail=0;
    int *vis=(int*)malloc(sizeof(int)*n);
    memset(circle,0,sizeof(circle));
    for(int i=1;i<=m;i++){
        int num;scanf("%d",&num);
        while(num--){
            char s[4];
            scanf("%s",s);
            circle[Hash(s)]=i;//归属哪一个圈子
        }
    }
    for(int i=0;i<n;i++){
        char s[4];
        scanf("%s%d%d",s,&p[i].arrive,&p[i].deal);
        if(p[i].deal>60) p[i].deal=60;
        p[i].name=Hash(s);
    }
    int coun=0;
    vis[0]=1;
    unhash(p[0].name);
    int finish,sum=0;
    finish=p[0].arrive+p[0].deal; // 业务完成时间
    coun++;
    PNode front=p[0];
    while(coun<=n){
        //寻找下一个需要办理的人
        int flag=0;
        // 插队
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            if(p[i].arrive>finish) break;
            if(circle[front.name]==circle[p[i].name]&&p[i].arrive<=finish){
                   flag=1;
                   vis[i]=1;
                   unhash(p[i].name);
                   sum+=finish-p[i].arrive; // finish 结束时间 arrive 到达时间
                   finish+=p[i].deal; // 时间扩充
                   front=p[i]; // 队列头
                   break;
            }
        }
        if(!flag){//按顺序进行查找，不插队
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                unhash(p[i].name);
                vis[i]=1;
                if(finish<=p[i].arrive) sum+=0;
                else sum+=finish-p[i].arrive;
                if(p[i].arrive>=finish) finish=p[i].arrive;
                finish+=p[i].deal;
                front=p[i];
                break;
            }
        }
        coun++;
    }
 
    printf("%.1lf\n",(sum*1.0)/n);
}