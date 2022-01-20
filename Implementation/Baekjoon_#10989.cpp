#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001

int check[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,num;
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>num;
		check[num-1]++;
	}
	for(int i=0;i<MAXN;i++) {
		for(int j=0;j<check[i];j++) {
			cout<<i+1<<'\';
		}
	}
	return 0;
}
