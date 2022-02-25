#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define MOD 15746
int N;
int dp[MAXN];

int f(int x) {
	if(x==1) return 1;
	if(x==2) return 2;
	if(dp[x]!=0) return dp[x];
	dp[x] = (f(x-1)%MOD) + (f(x-2)%MOD);
	return dp[x]%=MOD;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	cout<<f(N)<<'\n';
	return 0;
}
