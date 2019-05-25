// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
const int N = 110;
 
int main()
{
    vector<string> name(N);
    map<string, string> father;
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    while(n--)
    {
        string str;
        getline(cin, str);
        int cnt = count(str.begin(), str.end(), ' ');
        if(cnt == 0)
        {
            father[str] = "no";
            name[0] = str;
        }
        else
        {
            str = str.substr(cnt); 
            father[str] = name[cnt/2-1];
            name[cnt/2] = str;
        }
    }
    while(m--)
    {
        string a, b, c, d;
        cin >> a >> b >> b >> c >> b >> d;
        switch(c[0])
        {
            case 'p':
                swap(a, d);
            case 'c':
                if(father[a] == d)
                    printf("True\n");
                else
                    printf("False\n");
                break;
            case 's':
                if(father[a] == father[d])
                    printf("True\n");
                else
                    printf("False\n");
                break;
            case 'a':
                swap(a, d);
            case 'd':
                while(father[a] != d && father[a] != "no") a = father[a];
                if(father[a] == "no")
                    printf("False\n");
                else
                    printf("True\n");
        }
    }
    return 0;
}