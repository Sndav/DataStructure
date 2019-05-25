// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,a[200];
int main(){
    while(~scanf("%d %d",&n,&k)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        k=k%n;
        printf("%d",a[k]);
        for(int i=k+1;i<n;i++) printf(" %d",a[i]);
        for(int i=0;i<=k-1;i++) printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}