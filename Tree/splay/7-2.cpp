// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> A;
vector<int>::iterator it;
int c[100005];
int main(){
	int n;
	scanf("%d",&n);
	int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        it=lower_bound(A.begin(),A.end(),x);
        A.insert(it,x); 
        auto it2=lower_bound(A.begin(),A.end(),x);
        printf("%d %d\n",x,it2-A.begin());
    }
    for(int i=0;i<A.size();i++) {
        printf("%d ",A[i]); 
    }
	return 0;
} 