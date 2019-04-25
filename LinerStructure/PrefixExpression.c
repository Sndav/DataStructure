#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
/ -25 + * - 2 3 4 / 8 4
*/
int main(){
    freopen("/Users/hackboy/Code/C/in","r",stdin);
    char S1[35][35];
    int top1=0,top2=0;
    float S2[35];
    while(scanf("%s",S1[top1])!=EOF)top1++;
    top1--;
    while(top1>=0){
        if(!(strlen(S1[top1]) == 1 && (S1[top1][0]>'9' || S1[top1][0] < '0')))
            S2[top2++] = atof(S1[top1]);
        else{
            float a = S2[--top2];
            float b = S2[--top2];
            if(S1[top1][0] == '-') a = a-b;
            if(S1[top1][0] == '+') a = a+b;
            if(S1[top1][0] == '*') a = a*b;
            if(S1[top1][0] == '/'){
                if(b == 0){printf("ERROR");return 0;}
                a = a/b;
            }
            S2[top2++] = a;
        }
        top1--;
    }
    if(top2 != 1)printf("ERROR");
    else printf("%.1f",S2[0]);
    return 0;\
}