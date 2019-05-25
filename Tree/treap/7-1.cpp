#include<bits/stdc++.h>
using namespace std;
typedef double DB;
typedef long long LL;
typedef complex<double>CD;
const int maxn = 100010;
 
struct Treap
{
    struct node
    {
        int l,r;
        int v,rnd;
        int sizes,w;
    }tr[maxn];
    int sizes,root,ans;
    void Init()
    {
        sizes = root = 0;
    }
    int Random()
    {
        static int seed = 703;
        return seed = (int)(seed*48271LL%2147483647);
    }
    void Update( int k )
    {
        tr[k].sizes = tr[tr[k].l].sizes+tr[tr[k].r].sizes+tr[k].w;
    }
    void Right_rotate( int &k )
    {
        int t = tr[k].l;
        tr[k].l = tr[t].r;
        tr[t].r = k;
        tr[t].sizes = tr[k].sizes;
        Update( k );
        k = t;
    }
    void Left_rotate( int &k )
    {
        int t = tr[k].r;
        tr[k].r = tr[t].l;
        tr[t].l = k;
        tr[t].sizes = tr[k].sizes;
        Update( k );
        k = t;
    }
    void Insert( int &k , int x )
    {
        if ( k==0 )
        {
            k = ++sizes;
            tr[k].sizes = tr[k].w = 1;
            tr[k].v = x;
            tr[k].rnd = Random();
            tr[k].l = tr[k].r = 0;
            return;
        }
        tr[k].sizes++;
        if ( x==tr[k].v )
            tr[k].w++;
        else if ( x<tr[k].v )
        {
            Insert( tr[k].l , x );
            if ( tr[tr[k].l].rnd<tr[k].rnd )
                Right_rotate( k );
        }
        else
        {
            Insert( tr[k].r , x );
            if ( tr[tr[k].r].rnd<tr[k].rnd )
                Left_rotate( k );
        }
    }
    void Delete( int &k , int x )
    {
        if ( k==0 )
            return;
        if ( x==tr[k].v )
        {
            if ( tr[k].w>1 )
            {
                tr[k].w--;
                tr[k].sizes--;
                return;
            }
            if ( tr[k].l*tr[k].r==0 )
                k = tr[k].l+tr[k].r;
            else if ( tr[tr[k].l].rnd<tr[tr[k].r].rnd )
                Right_rotate( k ),Delete( k , x );
            else
                Left_rotate( k ),Delete( k , x );
        }
        else if ( x<tr[k].v )
            tr[k].sizes--,Delete( tr[k].l , x );
        else
            tr[k].sizes--,Delete( tr[k].r , x );
    }
    int Query_rank( int k , int x )
    {
        if ( k==0 )
            return 0;
        if ( tr[k].v==x )
            return tr[tr[k].l].sizes+1;
        else if ( x<tr[k].v )
            return Query_rank( tr[k].l , x );
        else
            return tr[tr[k].l].sizes+tr[k].w+Query_rank( tr[k].r , x );
    }
    int Query_num( int k , int x )
    {
        if ( k==0 )
            return 0;
        if ( x<=tr[tr[k].l].sizes )
            return Query_num( tr[k].l , x );
        else if ( x>tr[tr[k].l].sizes+tr[k].w )
            return Query_num( tr[k].r , x-tr[tr[k].l].sizes-tr[k].w );
        else
            return tr[k].v;
    }
    void Query_pro( int k , int x )
    {
        if ( k==0 )
            return;
        if ( tr[k].v<x )
        {
            ans = k;
            Query_pro( tr[k].r , x );
        }
        else
            Query_pro( tr[k].l , x );
    }
    void Query_sub( int k , int x )
    {
        if ( k==0 )
            return;
        if ( tr[k].v>x )
        {
            ans = k;
            Query_sub( tr[k].l , x );
        }
        else
            Query_sub( tr[k].r , x );
    }
}treap;
 
int main()
{
    for ( int n ; scanf ( "%d" , &n )==1 ; )
    {
        treap.Init();
        for ( int i=1 ; i<=n ; i++ )
        {
            int op,x;
            scanf ( "%d%d" , &op , &x );
            if ( op==1 )
                treap.Insert( treap.root , x );
            else if ( op==2 )
                treap.Delete( treap.root , x );
            else if ( op==3 )
                printf ( "%d\n" , treap.Query_rank( treap.root , x ) );
            else if ( op==4 )
                printf ( "%d\n" , treap.Query_num( treap.root , x ) );
            else if ( op==5 )
                treap.Query_pro( treap.root , x ),printf ( "%d\n" , treap.tr[treap.ans].v );
            else if ( op==6 )
                treap.Query_sub( treap.root , x ),printf ( "%d\n" , treap.tr[treap.ans].v );
        }
    }
    return 0;
}

