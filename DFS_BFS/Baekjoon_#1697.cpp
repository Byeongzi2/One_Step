#include<bits/stdc++.h>
using namespace std;
#define MAXN 200001
#define INF 987654321

int N,K;
int cnt[MAXN];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	cnt[x]=1;
	int curr;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		if(curr==K) return;
		if(curr*2<MAXN&&cnt[curr*2]==0) {
			q.push(curr*2);
			cnt[curr*2] = cnt[curr]+1;
		}
		if(curr-1>=0&&cnt[curr-1]==0) {
			q.push(curr-1);
			cnt[curr-1] = cnt[curr]+1;
		}
		if(curr+1<MAXN&&cnt[curr+1]==0) {
			q.push(curr+1);
			cnt[curr+1] = cnt[curr]+1;
		}
		
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//for(int i=0;i<MAXN;i++) cnt[i] = INF;
	
	cin>>N>>K;
	bfs(N);
	cout<<cnt[K]-1;
	return 0;
}
