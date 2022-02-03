#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int N,tmp;
int arr[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for(int i=0; i<N; i++) cin>>arr[i];
	
	sort(arr,arr+N);
	cout<<arr[0]*arr[N-1]<<'\n';
	return 0;
}

