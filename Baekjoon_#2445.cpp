#include<bits/stdc++.h>
using namespace std;
int N;

void star(int i) {
	for(int j=0;j<N-i;j++) cout<<' ';
	for(int j=0;j<i;j++) cout<<'*';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for(int i=1;i<=N;i++) {
		star(i);
		cout<<'\n';
	}
	for(int i=N-1;i>0;i--) {
		star(i);
		cout<<'\n';
	}
	return 0;
}
