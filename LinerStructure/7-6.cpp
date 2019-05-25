// By Zelong Bai
#include<stack>
#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	stack<int>s;
	queue<int>q;
	int m,n,k,num;
	cin>>m>>n>>k;
	while(k--){
		while(!q.empty())
		q.pop();
		while(!s.empty())
		s.pop();
	    for(int j=0;j<n;j++){
			scanf("%d",&num);
			q.push(num);
		}
		int i=1;
		while(s.size() < m && !q.empty()){		
			s.push(i);
			i++;
			while(!s.empty()&&!q.empty()&&s.top()==q.front()){
				q.pop();
				s.pop();
			}
			if(i==n+1) break;
		}
		if(i==n+1 && s.empty())
		    printf("YES\n");
		else
	        printf("NO\n");
		
	}
	return 0;
}