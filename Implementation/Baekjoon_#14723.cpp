#include<bits/stdc++.h>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	int i;
	for(i=1;i*(i+1)/2<N;i++);
	int s = (i-1)*i/2+1;
	cout<<i-(N-s)<<" "<<N-s+1;
	return 0;
}
