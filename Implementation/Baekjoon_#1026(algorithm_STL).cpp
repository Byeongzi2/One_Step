#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
#define INF 987654321
int N,sum;
int A[MAXN], B[MAXN];

bool cmp(const int &a, const int &b) {
	if(a>b) return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int g=0;g<2;g++) {
		for(int i=0;i<N;i++) {
			if(g==0) cin>>A[i];
			else cin>>B[i];
		}
	}
	sort(A,A+N,cmp);
	int tmp;
	for(int i=0;i<N;i++) {
		tmp = (min_element(B,B+N) - B);
		sum+=(A[i]*B[tmp]);
		B[tmp] = INF;
	}
	cout<<sum<<'\n';
	return 0;
}
