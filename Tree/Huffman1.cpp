/*
农夫要修理牧场的一段栅栏，他测量了栅栏，发现需要N块木头，每块木头长度为整数Li个长度单位，于是他购买了一条很长的、能锯成N块的木头，即该木头的长度是Li的总和。

但是农夫自己没有锯子，请人锯木的酬金跟这段木头的长度成正比。为简单起见，不妨就设酬金等于所锯木头的长度。例如，要将长度为20的木头锯成长度为8、7和5的三段，第一次锯木头花费20，将木头锯成12和8；第二次锯木头花费12，将长度为12的木头锯成7和5，总花费为32。如果第一次将木头锯成15和5，则第二次锯木头花费15，总花费为35（大于32）。

请编写程序帮助农夫计算将木头锯成N块的最少花费。

输入格式:
输入首先给出正整数N（≤104），表示要将木头锯成N块。第二行给出N个正整数（≤50），表示每段木块的长度。

输出格式:
输出一个整数，即将木头锯成N块的最少花费。

输入样例:
8
4 5 1 2 1 3 1 1
输出样例:
49
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> > nums;
    int n,sum=0;cin>>n;
    for(int i = 0;i<n;i++){
        int tmp;cin>>tmp;
        nums.push(tmp);
    }
    while(nums.size()>1){
        int s = nums.top();nums.pop();
        s += nums.top();nums.pop();
        nums.push(s);
        sum+=s;
    }
    cout<<sum;
    return 0;
}