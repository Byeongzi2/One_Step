#include<bits/stdc++.h>
using namespace std;
#define ll long long

// a + ar + ar^2 + ar^3 + ar^4 + ar^5			=> 전체문제 
// (a + ar + ar^2) (1 + r^3) // O(log^2 (n) )	=> 부분문제 

ll a, r, n, mod;

ll mpow(ll a, ll e, ll m) {
	ll r = 1;
	while (e > 0) {
		if (e & 1) r = r * a % m;
		a = a * a % m;
		e >>= 1;
	}
	return r;
}

ll dnc(ll n) {
	if (n==1) return a;
	if (n%2==1) {
		return (dnc(n/2) * (1 + mpow(r, n/2, mod)) % mod + a * mpow(r,n-1,mod) % mod) % mod;
	} 
	else {
		return dnc(n/2) * (1 + mpow(r,n/2,mod)) % mod;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>a>>r>>n>>mod;
	cout<<dnc(n)<<'\n';

	return 0;
}
