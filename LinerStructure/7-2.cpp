#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<numeric>
using namespace std;
int main(){
	vector<int> c1;
	vector<int> c2;
	while(true){
		int input;
		scanf("%d",&input);
		if(input!=-1)
			c1.push_back(input);
		else
			break;
	}
	while(true){
		int input;
		scanf("%d",&input);
		if(input!=-1)
			c2.push_back(input);
		else
			break;
	}
	int l1=c1.size(),l2=c2.size();
	vector<int> ans(max(l1,l2));
	auto iter=set_intersection(c1.begin(),c1.end(),c2.begin(),c2.end(),ans.begin());
	ans.erase(iter,ans.end());
	if(ans.size()==0)
		printf("NULL");
	else{
		auto it=ans.begin();
		printf("%d",*it);
		it++;
		for(; it!=ans.end(); it++)
			printf(" %d",*it);
	}
	return 0;
}