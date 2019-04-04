#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int table[mx][18];
int arr[mx];
void preProcess(int n )
{
//    for(int i=0; i<=n; i++){
//        for(int j=0; j<18; j++){
//            table[i][j] = 100000000;
//        }
//    }
    for(int i=1; i<=n; i++){
        table[i][0] = i;
    }
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; (i + (1<<j)-1) <=n; i++){
            if(arr[ table[i][j-1] ] < arr[ table[i+(1<<(j-1))][j-1] ]){
                table[i][j] = table[i][j-1];
            }
            else{
                table[i][j] = table[i+(1<<(j-1))][j-1];
            }
        }
    }
}
int query(int i, int j)
{
    int l = j-i+1;
    int k = log2(l);
    return min(arr[ table[i][k] ], arr[ table[i+l-(1<<k)][k] ]);
}
int main()
{
    int cs=1,tc,n,q,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        scanf("%d",&q);
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        preProcess(n);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&a,&b);
            printf("%d\n",query(a,b));
        }
    }
    return 0;
}