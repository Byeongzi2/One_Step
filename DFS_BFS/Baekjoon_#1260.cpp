#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

vector<int> v[MAXN];
int N,M,V;
bool visited[MAXN];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = true;
	int curr;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		cout<<curr<<" ";
		int next;
		for(int i=0;i<v[curr].size();i++) {
			next=v[curr].at(i);
			if(!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

void dfs(int x) {
	visited[x] = true;
	cout<<x<<" ";
	int next;
	for(int i=0; i<v[x].size();i++) {
		next = v[x].at(i);
		if(!visited[next]) dfs(next);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M>>V;
	int a,b;
	for(int i=0;i<M;i++) {
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=N;i++) {
		sort(v[i].begin(),v[i].end());
	}
	
	dfs(V);
	for(int i=1;i<=N;i++) visited[i]=false;
	cout<<'\n';
	bfs(V);
	
	
	return 0;
}
