#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
int N,num,ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector<bool> isPrime(MAXN+1,true);
	isPrime[1] = false;
	for(int i=4;i<=MAXN;i+=2) isPrime[i] = false;
	for(int i=3;i<=MAXN;i++) {
		if(!isPrime[i]) continue;
		for(int j=i*i;j<=MAXN;j+=i*2) isPrime[j] = false;
	}
	
	for(int i=0;i<N;i++) {
		cin>>num;
		if(isPrime[num]) ans++;
	}
	cout<<ans;
	return 0;
	system("pause");
}
