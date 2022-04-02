#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>&a, int l, int r) {
	if ( l >= r) return;
	int m = (l+r)/2;
	merge_sort(a,l,m); // left
	merge_sort(a,m+1,r); // right
	
	// 정렬된 두 구간을 하나의 정렬된 배열로 만들어줌 // merge
//	vector<int> tmp(r-1+l);
//	int i=l, j=m+1, k=0; // i는 왼쪽구간의 시작 인덱스, j는 오른쪽구간, k는 tmp배열의 시작 인덱스 
//	while(i<=m && j<=r) {
//		tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];
//	}
//	while (i <= m) {
//		tmp[k] = a[i];
//		i++;
//		k++;
//	} 
//	while( j<= r) {
//		tmp[k] = a[j];
//		j++;
//		k++;
//	}
//	for(int i=l, j=0; i<= r; ++i,++j) {
//		a[i] = tmp[j];
//	}
	vector<int> tmp;
	merge(a.begin()+l,a.begin()+m+1, a.begin() + m + 1,a.begin()+r+1, back_inserter(tmp));
	
}

// o (N ^ 2)
// theta( n log n ) 
void quick_sort(vector<int>& a, int l, int r) {
	if(l>=r) return;
	
	int i = l, j = l;
	int& pivot = a[r];
	while(j < r) {
		if (a[j] < pivot) {
			swap(a[i],a[j]);
			i++;
		}
		j++;
	}
	swap(pivot,a[i]);
	quick_sort(a,l,i-1);
	quick_sort(a,i+1,r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a[n];
	for(int& i : a) cin>>i;
	merge_sort(a,0,n-1);
	for(int i : a) cout<< i<<'\n';
	return 0;
}
