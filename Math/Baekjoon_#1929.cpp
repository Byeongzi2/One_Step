#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define ll long long   
int M,N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>M>>N;
	vector<bool> isPrime(MAXN+1,true);
	isPrime[1] = false;
	for(int i=4;i<=MAXN;i+=2) isPrime[i] = false;
	for(ll i=3;i<=MAXN;i++) {
		if(!isPrime[i]) continue;
		// �������� N�� �ִ밪��  1,000,000 �̱� ������ j=i*i�κп���
		// int ���� ����� ���� �����ϱ� ���� j�� long long���� �����ؾ���.  
		for(ll j=i*i;j<=MAXN;j+=i*2) isPrime[j] = false;
	}
	
	for(int i=M;i<=N;i++) {
		if(isPrime[i]) cout<<i<<'\n';
	}
	return 0;
}
