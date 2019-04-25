/*
给定一段文字，如果我们统计出字母出现的频率，是可以根据哈夫曼算法给出一套编码，使得用此编码压缩原文可以得到最短的编码总长。然而哈夫曼编码并不是唯一的。例如对字符串"aaaxuaxz"，容易得到字母 'a'、'x'、'u'、'z' 的出现频率对应为 4、2、1、1。我们可以设计编码 {'a'=0, 'x'=10, 'u'=110, 'z'=111}，也可以用另一套 {'a'=1, 'x'=01, 'u'=001, 'z'=000}，还可以用 {'a'=0, 'x'=11, 'u'=100, 'z'=101}，三套编码都可以把原文压缩到 14 个字节。但是 {'a'=0, 'x'=01, 'u'=011, 'z'=001} 就不是哈夫曼编码，因为用这套编码压缩得到 00001011001001 后，解码的结果不唯一，"aaaxuaxz" 和 "aazuaxax" 都可以对应解码的结果。本题就请你判断任一套编码是否哈夫曼编码。

输入格式：
首先第一行给出一个正整数 N（2≤N≤63），随后第二行给出 N 个不重复的字符及其出现频率，格式如下：

c[1] f[1] c[2] f[2] ... c[N] f[N]
其中c[i]是集合{'0' - '9', 'a' - 'z', 'A' - 'Z', '_'}中的字符；f[i]是c[i]的出现频率，为不超过 1000 的整数。再下一行给出一个正整数 M（≤1000），随后是 M 套待检的编码。每套编码占 N 行，格式为：

c[i] code[i]
其中c[i]是第i个字符；code[i]是不超过63个'0'和'1'的非空字符串。

输出格式：
对每套待检编码，如果是正确的哈夫曼编码，就在一行中输出"Yes"，否则输出"No"。

注意：最优编码并不一定通过哈夫曼算法得到。任何能压缩到最优长度的前缀编码都应被判为正确。

输入样例：
7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
4
A 00000
B 00001
C 0001
D 001
E 01
F 10
G 11
A 01010
B 01011
C 0100
D 011
E 10
F 11
G 00
A 000
B 001
C 010
D 011
E 100
F 101
G 110
A 00000
B 00001
C 0001
D 001
E 00
F 10
G 11
输出样例：
Yes
Yes
No
No
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
    Node(int v):val(v),left(NULL),right(NULL){};
};
Node * insert(Node * T,char *A,int &a){
    if(strlen(A) == 0){
        if(T == NULL) T = new Node(1);
        else{T->val = 1;a=0;}
        return T;
    }else if(T == NULL){
        T = new Node(-1);
        if(A[0] == '0') {T->left = insert(T->left,A+1,a);return T;}
        if(A[0] == '1') {T->right = insert(T->right,A+1,a);return T;}
    }else{
        if(T->val != -1)return NULL;
        if(A[0] == '0') {T->left = insert(T->left,A+1,a);return T;}
        if(A[0] == '1') {T->right = insert(T->right,A+1,a);return T;}
    }
}
int main(){
    priority_queue< int, vector<int>, greater<int> > nums;
    map<char,int> code;
    int n,sum = 0;cin>>n;
    for(int i = 0;i<n;i++){
        char c[2];int f;
        scanf("%s%d",c,&f);
        code.insert(pair<char,int>(c[0],f));
        nums.push(f);
    }
    while(nums.size()>1){
        int s = nums.top();nums.pop();
        s += nums.top();nums.pop();
        nums.push(s);
        sum+=s;
    }
    int t;cin>>t;
    for(int i = 0;i<t;i++){
        int s = 0,ok=1;
        Node * T = NULL;
        for(int j=0;j<code.size();j++){
            char A[2],S[100];
            scanf("%s%s",A,S);
            s += strlen(S)*code[A[0]];
            T = insert(T,S,ok);
        }
        if(ok && s == sum)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}