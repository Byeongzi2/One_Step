#include<bits/stdc++.h>
using namespace std;
#define INF 97654321

int n;
int a[505][2];
int dp[505][505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i][0]>>a[i][1];
		for(int j=0;j<505;j++) {
			dp[i][j] = INF;
		}
		dp[i][i] = 0;
	}
	for(int i=n-1;i>=0;i--) {
		for(int j=i+1;j<n;j++) {
			for(int k=i;k<j;k++) {
				int cost = a[i][0] * a[k][1] * a[j][1]
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+cost);
			}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}
