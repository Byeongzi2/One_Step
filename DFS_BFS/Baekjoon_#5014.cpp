#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define INF 1e13
#define ll long long

int F, G, S, U, D;
ll depth[MAXN];

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	depth[idx] = 0;
	int curr;
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		if (curr == G) break;
		if (U!=0&&curr + U <= F&&depth[curr+U]==INF) {
			depth[curr + U] = depth[curr] + 1;
			q.push(curr + U);
		}
		if (D!=0&&curr - D > 0&&depth[curr-D]==INF) {
			depth[curr - D] = depth[curr] + 1;
			q.push(curr - D);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;
	for (int i = 0; i <= F; i++) depth[i] = INF;
	bfs(S);
	if (depth[G] != INF) cout << depth[G];
	else cout << "use the stairs";
	
	return 0;
}
