#include<bits/stdc++.h>
using namespace std;
#define MAXN 9
int N, M;
int arr[MAXN],num[MAXN];
bool used[MAXN];
void backtrack(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	int curr;
	for (int i = 0; i < N; i++) {
		curr = num[i];
		if(used[i]) continue;
		arr[idx] = curr;
		used[i] = true;
		backtrack(idx + 1);
		used[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i=0;i<N;i++) {
		cin>>num[i];
	}
	sort(num,num+N);
	backtrack(0);
	return 0;
}
