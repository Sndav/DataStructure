// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> T;
int minsta,allcnt,delcnt;
void add(int x){
    for(auto iter = T.begin();iter != T.end();){
        *iter += x;
        if(*iter > minsta){
            delcnt++;
            T.erase(iter);
        }
        else ++iter;
    }
}
int Kth(int k){
    return T[k-1];
}
void insert(int n){
    auto it = lower_bound(T.begin(),T.end(),-n);
    T.insert(it,-n);
}
int main(){
    int n;
    freopen("/Users/hackboy/Code/C/in/1.in","r",stdin);
    freopen("/Users/hackboy/Code/C/out","w",stdout);
    scanf("%d %d\n",&n,&minsta);
    minsta *= -1;
    for(int i=0;i<n;i++){
        char O;int x;
        scanf("%c %d\n",&O,&x);
        switch (O){
        case 'I':
            if(x < -minsta)
                break;
            allcnt++;
            insert(x);
            break;
        case 'A':
            add(-x);
            break;
        case 'S':
            add(x);
            break;
        case 'F':
            if(x>T.size()) printf("-1\n");
            else printf("%d\n",-Kth(x));
            break;
        }
    }
    printf("%d",delcnt);
    return 0;
}