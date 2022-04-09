#include<bits/stdc++.h>
using namespace std;

int n,k;
int coin[105], dp[2][10005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	for(int i=0; i<n ;i++) {
		cin>>coin[i];
	}
	
	// 바텀업 + 슬라이딩 윈도우
	for ( int i=0; i* coin[0] <= k; i++) {
		dp[0][i*coin[0]] = 1;
	} 
	
	for(int i=1; i<n; i++) {
		for(int j=0;j<=k ; j++) {
			if (j>= coin[i]) {
				dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-coin[i]];
			}
			else {
				dp[i%2][j] = dp[(i-1)%2][j];
			}
		}
	}
	cout<<dp[(n-1)%2][k];
	return 0;
}
