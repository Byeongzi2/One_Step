#include<bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for(int g=1;g<=N;g++) {
		for(int i=0;i<N-g;i++) {
			cout<<' ';
		}
		for(int i=0;i<(2*g-1);i++) {
			if(!(i%2)) cout<<'*';
			else cout<<' '; 
		}
		cout<<'\n';
	}	
	return 0;
}
