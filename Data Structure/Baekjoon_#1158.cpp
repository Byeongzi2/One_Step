#include<bits/stdc++.h>
using namespace std;

int N,K,num;
queue<int> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>K;
	for(int i=1;i<=N;i++) q.push(i);
	cout<<'<';
	while(!q.empty()) {
		if(q.size()==1) {
			num = q.front();
			cout<<num<<'>';
			q.pop(); 
		}
		else {
			for(int i=0;i<K-1;i++) {
				num=q.front();
				q.pop();
				q.push(num);
			}
			num=q.front();
			q.pop();
			cout<<num<<", ";
		}
		
		
	}
	return 0;
}
