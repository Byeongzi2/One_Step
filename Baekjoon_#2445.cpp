#include<bits/stdc++.h>
using namespace std;
int MAXN;
void star(int start,int end) {
	for(int i=start;i<=end;i++) {
		for(int j=1;j<=i;j++){
			cout<<'*';
		}
		for(int j=0;j<(MAXN+1-2*i);j++) {
			cout<<' ';
		}
		for(int j=1;j<=i;j++) {
			cout<<'*';
		}
		cout<<'\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	MAXN = 2*N-1;
	star(1,N);
	for(int i=N-1;i>0;i--) {
		for(int j=1;j<=i;j++){
			cout<<'*';
		}
		for(int j=0;j<(MAXN+1-2*i);j++) {
			cout<<' ';
		}
		for(int j=1;j<=i;j++) {
			cout<<'*';
		}
		cout<<'\n';
	}
	return 0;
}
