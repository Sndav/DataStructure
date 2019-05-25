// By Zelong Bai
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
int x=0;
void BuildNext( char *pattern, int *next )
{
    int i, j;
    int m = strlen(pattern);
    next[0] = -1;
      
    for ( j=1; j<m; j++ ) {
        i = next[j-1];
        while ( (i>=0) && (pattern[i+1]!=pattern[j]) )
            i = next[i];
        if ( pattern[i+1]==pattern[j] )
             next[j] = i+1;
        else next[j] = -1;
    }
}
  
int KMP( char *string, char *pattern )
{
    int n = strlen(string);
    int m = strlen(pattern);
    int s, p, *next;
      
    if ( n < m ) return -1;
    next = (int *)malloc(sizeof(int) * m);
    BuildNext(pattern, next);
    s = p = 0;
    while ( s<n && p<m ) {
        x++;
        if ( string[s]==pattern[p] ) {
            s++; p++;
        }
        else if (p>0) p = next[p-1]+1;
        else s++;
    }
    return ( p==m )? (s-m) : -1;
}
int main() {
  char string[1000001] = {0};
  char pattern[1000001] = {0};
  scanf("%s\n", (char *)&string);
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s\n", (char *)&pattern);
    int p = KMP(string, pattern);
    if(p != -1) {
      if(i == n - 1) {
        printf("%s", (char *)string+p);
      } else {
        printf("%s\n", (char *)string+p);
      }
    } else {
      if(i == n - 1) {
        printf("Not Found");
      } else {
        printf("Not Found\n");
      }
    }
  }
  printf("%d",x);
  return 0;
}