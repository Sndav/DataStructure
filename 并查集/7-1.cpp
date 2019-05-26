// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int f[50010],val[50010],ranks[50010],N;
int main(){
    val[0] = INF;
    for(int i = 0;i<N+10;i++){
        f[i] = i;
    }
    scanf("%d",&N);
    int i;
    for(i=1;i<=N;i++){
        int c,w,p;
        scanf("%d%d%d",&c,&w,&p);
        p += 1;
        f[i] = p;val[i] = c - w;
        if(c - w < 0)break;
        int tmp = f[i];
        while(tmp != f[tmp]){
            val[tmp] -= w;
            if(val[tmp] < 0){printf("%d",i-1);exit(0);}
            tmp = f[tmp];
        }
    }
    printf("%d",i-1);
    return 0;
}