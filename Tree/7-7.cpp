#include<iostream>
#include<string>
#include<map>
using namespace std;
struct Node {
	int height;
	int parent = -1;
	int left=-1, right=-1;
};
map<int, Node> T;
void insert(int head, int tmp,int height) {   //构造搜索树
	if (head != -1) {
		int r = tmp < head ? T[head].left : T[head].right;
		if (r != -1)
			insert(r, tmp,height+1);
		else {
			(tmp < head ? T[head].left : T[head].right) = tmp;
			T[tmp].parent = head;        //记录父结点
			T[tmp].height = height;      //存储结点深度
		}
	}
}
bool judge(int head,int a, int b, string relation) {
	if (relation == "root")
		return head == a;
	if (T.find(a) == T.end() || T.find(b) == T.end())  //当搜索的结点不在树中，返回false
		return false;
	else if (relation == "siblings") 
		return T[a].parent==T[b].parent;
	else if (relation == "parent")
		return T[a].left == b || T[a].right == b;
	else if (relation == "left")
		return T[b].left == a;
	else if (relation == "right")
		return T[b].right == a;
	else if (relation == "level")
		return T[a].height == T[b].height;
}
int main() {
	int n, m, tmp, a=0, b=0, head;
	string relation, str;
	cin >> n >> head;
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		insert(head, tmp, 1);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> str;
		if (str == "and") {
			cin >> b >> str >> str;
			if (str == "siblings")
				relation = str;
			else 
				cin >> str >> str >> relation;	
		}
		else {
			cin >> str >> relation;
			if (relation == "parent") 
				cin >> str >> b;
			else if(relation!="root")
				cin >> str >> str >> b;		
		}
		cout << (judge(head, a, b, relation) ? "Yes" : "No") << endl;
	}
	return 0;
}

