#include<bits/stdc++.h>
using namespace std;
#define MAXN 9

int M, N;
int arr[MAXN];
set<int> s;

void backtrack(int idx, int pre) {
	if (idx == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= M; i++) {
		if (s.find(i) != s.end()) continue;
		arr[idx] = i;
		s.insert(i);
		backtrack(idx + 1, i);
		s.erase(i);
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	backtrack(0, 0);
	return 0;
}
