#include <stdio.h>

int main(void)
{
    int n, m, k, i, j, a;
    scanf("%d %d %d", &n, &m, &k);

    //Init D
    int D[n][n];
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            D[i][j] = (i == j ? 0 : -1);

    //Get D
    int s1, s2, len, terminal[m*2];
    char ch;
    for(i = 0; i < m; ++i)
    {
        scanf("%d", &s1);
        s1--;
        terminal[i*2] = s1;
        ch = getchar();
        while(ch != '\n')
        {
            scanf("%d %d", &len, &s2);
            s2--;
            if(D[s1][s2] == -1 || D[s1][s2] > len)
            {
                D[s1][s2] = len;
                D[s2][s1] = D[s1][s2];
            }
            s1 = s2;
            ch = getchar();
        }
        terminal[i*2 + 1] = s1;
    }

    //Floyd
    for(a = 0; a < n; ++a)
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                if(D[i][a] != -1 && D[a][j] != -1)
                    if(D[i][j] == -1 || D[i][a] + D[a][j] < D[i][j])
                        D[i][j] = D[i][a] + D[a][j];

    //Preprocess
    int canArr[n][n];
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            canArr[i][j] = 0;
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < m*2; ++j)
            if(D[i][terminal[j]] != -1)
                canArr[i][terminal[j]] = 1;
        for(j = 0; j < n; ++j)
        {
            if(j != i)
            {
                if(D[i][j] == -1)
                    continue;
                for(a = 0; a < n; ++a)
                    if(a != i && a != j)
                        if(D[i][a] != -1 && D[i][a] / k == D[i][j] / k && D[i][a] > D[i][j])
                            break;
                if(a == n)
                    canArr[i][j] = 1;
            }
        }
    }

    //Solve Problem
    int q, start, arr[n], queue[n], head, tail, flag;
    scanf("%d", &q);
    for(i = 0; i < q; ++i)
    {
        for(j = 0; j < n; ++j)
            arr[j] = 0;
        scanf("%d", &start);
        arr[--start] = 1;

        head = 0, tail = 0;
        queue[0] = start;

        while(head <= tail)
        {
            for(j = 0; j < n; ++j)
                if(!arr[j] && canArr[queue[head]][j])
                {
                    queue[++tail] = j;
                    arr[j] = 1;
                }
            head++;
        }

        flag = 0;
        for(j = 0; j < n; ++j)
            if(arr[j])
            {
                if(flag)
                    printf(" ");
                else
                    flag = 1;
                printf("%d", j+1);
            }
        printf("\n");
    }
    return 0;
}