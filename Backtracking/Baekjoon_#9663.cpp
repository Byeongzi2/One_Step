#include<bits/stdc++.h>
using namespace std;
#define MAXN 15

int N,ans;
int Col[MAXN];

bool check(int c) {
	for(int i=0;i<c;i++) {
		if(Col[i]==Col[c] || abs(Col[c] - Col[i]) == c-i) return false;
	}
	return true;
}
void backtrack(int c) {
	
	if(c==N) {
		ans++;
		return;
	}
	
	for(int i=0;i<N;i++) {
		Col[c] = i;
		if(check(c)) backtrack(c+1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	backtrack(0);
	cout<<ans<<'\n';
	return 0;
} 
