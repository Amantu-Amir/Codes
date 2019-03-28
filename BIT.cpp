#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long 
ll arr[mx], tree[mx];
int LSB(int pos)
{
	return pos&(-pos);
}
ll prefixSum(int pos)
{
	ll sum = 0;
	for(;pos;pos-=LSB(pos))
		sum+=tree[pos];
	return sum;
}
ll rangeQuery(int i, int j)
{
	return prefixSum(j) - prefixSum(i-1);
}
void updateAdd(int pos, ll delta, int n)
{
	for(; pos<=n; pos+=LSB(pos))
		tree[pos]+=delta;
}
void updateSet(int pos, ll delta, int n)
{
	ll val = rangeQuery(pos, pos);
	delta-=val;
	for(; pos<=n; pos+=LSB(pos))
		tree[pos]+=delta;
}
void buildLogN(int n)
{
	memset(tree, 0, sizeof tree);
	for(int i=1; i<=n; i++)
		updateAdd(i,arr[i],n);
}
void buildN(int n)
{
	tree[0] = 0;
	for(int i=1; i<=n; i++) tree[i] = arr[i];
	for(int i=1; i<=n; i++){
		int j = i + LSB(i);
		if(j<=n) tree[j]+=tree[i];
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &arr[i]);
	}
}