#include<bits/stdc++.h>
using namespace std;

int n, a[305], dp[305];

int f(int x) {
	if (x > n) return 0;
	if(x==n) return -1e9;
	if (dp[x] != -1) return dp[x];
	return dp[x] = max(f(x+2) + a[x+1], f(x+3) + a[x+1] + a[x+2]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<max(f(0),f(1));
	return 0;
}
