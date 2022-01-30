#include<iostream>
using namespace std;
#define MAXN 13

int K,cnt;
int arr[MAXN],ans[6];

void backtrack(int idx) {
	if (idx == K||cnt==6) {
		if (cnt == 6) {
			for (int i = 0; i < 6; i++) cout << ans[i] << ' ';
			cout << '\n';
		}
		return;
	}
	ans[cnt++] = arr[idx];

	backtrack(idx + 1);
	cnt--;
	backtrack(idx + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> K;
		if (!K) break;
		cnt = 0;
		for (int i = 0; i < K; i++) cin >> arr[i];
		backtrack(0);
		cout << '\n';
	}
	return 0;
}
