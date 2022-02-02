#include<iostream>
using namespace std;
#define MAXN 21

int N,S,arr[MAXN],cnt,sum;
void backtrack(int idx) {
	if (idx == N) return;
	if (sum + arr[idx] == S) cnt++;
	backtrack(idx + 1);

	sum += arr[idx];
	backtrack(idx + 1);
	sum -= arr[idx];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	backtrack(0);
	cout << cnt << '\n';
	return 0;

}
