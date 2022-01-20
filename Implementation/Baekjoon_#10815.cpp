#include<bits/stdc++.h>
using namespace std;
#define MAXN 500001

int arr[MAXN];
int N,M;

bool check(int idx,int target) {
	int tmp = arr[idx];
	if(target<=tmp) return 1;
	return 0;
}
void binSearch(int x) {
	int lo=0, hi=N-1;
	int mid;
	while(lo<hi) {
		mid = (lo+hi)/2;
		if(check(mid,x)) hi=mid;
		else lo = mid+1;
	}
	if(arr[lo]==x) cout<<"1 ";
	else cout<<"0 ";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	sort(arr,arr+N);
	cin>>M;
	int tmp;
	for(int i=0;i<M;i++) {
		cin>>tmp;
		binSearch(tmp);
	}
	return 0;
}
