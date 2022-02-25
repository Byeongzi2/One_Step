#include<bits/stdc++.h>
using namespace std;
#define MAXN 91
#define ll long long

int N;
ll dp[MAXN];

ll f(int x) {
	if(x==1||x==2) return 1;
	if(dp[x]!=0) return dp[x];
	return dp[x] = f(x-1)+f(x-2);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	cout<<f(N);
	return 0;
}
