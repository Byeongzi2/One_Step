#include<bits/stdc++.h>
using namespace std;

int N,MAX,tmp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	MAX = 2*N-1;
	for(int i=1;i<=N;i++) {
		tmp = (MAX-(2*i-1))/2;
		for(int j=0;j<tmp;j++) {
			cout<<' ';
		}
		for(int j=0;j<2*i-1;j++) {
			cout<<'*';
		}
		cout<<'\n';
	}
	
	return 0;
}
