#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
int N,M,V;
bool visitedA[MAXN], visitedB[MAXN];
vector<int> vA[MAXN], vB[MAXN];

void dfs(int curr) {
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>N>>M>>V;
	for(int i=0;i<M;i++) {
		cin>>a>>b;
		vA.push_back(b);
		vB.push_back(a);
	}
	
	return 0;
}
