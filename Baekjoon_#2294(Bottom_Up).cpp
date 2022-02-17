#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAXN 101
#define MAXK 10001

int N,K,cost[MAXN],dp[MAXN][MAXK];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>K;
	for(int i=0;i<N;i++) cin>>cost[i];
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=K;j++) dp[i][j] = INF;
	}
	
	for(int i=0;i<N;i++) {
		dp[i][0] = 0;
		for(int j=0;j<=K;j++) {
			dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
			int jj = j + cost[i];
			if(jj<=K) dp[i][jj] = min(dp[i][jj],dp[i][j]+1);
		}
	}
	if(dp[N-1][K] == INF) cout<<"-1";
	else cout<<dp[N-1][K];
	return 0;
}
