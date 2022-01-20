#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

priority_queue<int, vector<int>, greater<int> > pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,num;
	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>num;
		pq.push(num);
	}
	while(!pq.empty()) {
		num = pq.top();
		pq.pop();
		cout<<num<<'\n';
	}
	return 0;
}
