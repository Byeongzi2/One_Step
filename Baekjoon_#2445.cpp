#include<bits/stdc++.h>
using namespace std;
int N,MAXN;

void star(int start) {
	for(int j=0;j<start;j++) cout<<' ';
	for(int j=0;j<(MAXN-2*start);j++) cout<<'*';
	cout<<'\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	MAXN = 2*N-1;
	for(int i=0;i<N;i++) {
		star(i);
	}
	for(int i=N-2;i>=0;i--) {
		star(i);
	}
	
	return 0;
}
