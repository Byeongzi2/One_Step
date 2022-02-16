#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
int T,n,MAXnum;
int value[2][MAXN],dp[3][MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=0;i<2;i++) {
			for(int j=0;j<n;j++) cin>>value[i][j];
		}
		dp[1][0] = value[0][0];
		dp[2][0] = value[1][0]; 
		MAXnum = max(dp[1][0],dp[2][0]);
		for(int i=1;i<n;i++) {
			dp[0][i] = MAXnum;
			dp[1][i] = max(dp[0][i-1]+value[0][i], dp[2][i-1]+value[0][i]);
			dp[2][i] = max(dp[0][i-1]+value[1][i],dp[1][i-1]+value[1][i]);
			MAXnum = max({dp[0][i],dp[1][i],dp[2][i]});
		}
		cout<<MAXnum<<'\n';
	}
	
	
	return 0;
}
