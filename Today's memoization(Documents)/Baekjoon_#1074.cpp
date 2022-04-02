#include<bits/stdc++.h>
using namespace std;

int z_search(int i, int j, int n, int r, int c) {
	if (n==0 ) return 0;
	int z = pow(2,n-1);
	if(r<i+z && c<j+z) return z_search(i,j,n-1,r,c); // 1사분면 
	else if (r<i+z) return z_search(i,j+z, n-1,r,c) + z*z; // 2사분면 
	else if (c<j+z) return z_search(i+z,j,n-1,r,c) + z*z*2; // 3사분면 
	else return z_search(i+z, j+z, n-1, r, c) + z*z*3;	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, c;
	cin>>n>>r>>c;
	cout<<z_search(n,r,c) <<'\n';
	return 0;
}
