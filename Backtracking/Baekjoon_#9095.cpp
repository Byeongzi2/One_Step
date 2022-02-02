#include<iostream>
using namespace std;
#define MAXN 11
int T,n;
int dp[MAXN];

int backtrack(int x) {
	if (x <= 0) return 0;
	if (dp[x] != 0) return dp[x];
	dp[x] = backtrack(x - 1) + backtrack(x - 2) + backtrack(x - 3);
	return dp[x];
}
void init() {
	for (int i = 0; i < MAXN; i++) dp[i] = 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (T--) {
		cin >> n;
		backtrack(n);
		cout << dp[n]<<'\n';
	}

	return 0;
}
