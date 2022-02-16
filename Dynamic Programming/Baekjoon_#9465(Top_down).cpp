#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int T,n;
int dp[MAXN][3],value[2][MAXN];


void init() {
	for(int i=0;i<=n;i++) {
		for(int j=0;j<3;j++) dp[i][j] = -1;
	}
}

int f(int c,int status) {
	if(c==n) return 0;
	if(dp[c][status]!=-1) return dp[c][status];
	
	int score = f(c+1,0);
	if(status!=1) score = max(score,f(c+1,1)+value[0][c]);
	if(status!=2) score = max(score,f(c+1,2)+value[1][c]);
	
	dp[c][status] = score;
	return score;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++) cin>>value[i][j];
		}
		init();
		cout<<f(0,0)<<'\n';
	}	
	
	return 0;
}
