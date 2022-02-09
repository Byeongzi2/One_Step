#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
int N,M,a,b,cnt;
vector<int> v[MAXN];
bool visited[MAXN];

void dfs(int x) {
	visited[x]=true;
	cnt++;
	int next;
	for(int i=0;i<v[x].size();i++) {
		next = v[x].at(i);
		if(!visited[next]) dfs(next);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout<<cnt-1;
	return 0;
}
