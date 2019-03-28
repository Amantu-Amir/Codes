#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int , int>
#define fast ios_base::sync_with_stdio(0)
#define mod 1000000007
#define mx 1002
int BIT[mx][mx], mat[mx][mx];
int row = mx-1, col=mx-1;
void update(int x, int y, int delta)
{
    mat[x][y] = 1;
    for( x; x<=row; x+=(x&-x))
    {
        for(int j = y; j<=col; j+=(j&-j))
            BIT[x][j]+=delta;
    }
}
int query(int x, int y)
{
    int ans = 0;
    for( ; x; x-=(x&-x))
    {
        for(int j = y; j ; j-=(j&-j))
            ans+=BIT[x][j];
    }
    return ans;
}
int queryUtil(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
}
int main()
{
    
}