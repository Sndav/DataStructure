// By Zelong Bai
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int stack[100000];
	int n,top = -1;
	string str;
	vector<int> order; // 排序数组
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "Push") {
			scanf("%d", &stack[++top]);
			order.insert(lower_bound(order.begin(), order.end(), stack[top]), stack[top]); // 二分查找
		}
		else if (str == "Pop"&&top >= 0) {
			order.erase(lower_bound(order.begin(), order.end(), stack[top]));
			printf("%d\n", stack[top--]);
		}
		else if (str == "PeekMedian"&&top >= 0)
			printf("%d\n", order[top / 2]);
		else
			printf("Invalid\n");
	}
	return 0;
}