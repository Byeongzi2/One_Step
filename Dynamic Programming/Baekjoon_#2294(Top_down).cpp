#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 101
#define MAXK 10001
#define INF 97654321

int N, K, cost[MAXN], dp[MAXN][MAXK];

int coin(int n, int k) {
	if (n == N) return (k == 0 ? 0 : INF); 
	//base문 : n이 끝까지 갔음에도 K값이 0이 되지 않았다면 만들 수 없는 값이므로 INF를 반환
	// n이 끝까지 갔는데 K값이 0이라면 만들 수 있는 값이므로 count해나갈 base 조건인 0을 반환.


	if (dp[n][k] != -1) return dp[n][k]; // 이미 앞에서 계산했다면 미리 계산된 값을 반환

	int result = coin(n + 1, k); // 먼저 지금 동전을 사용하지 않고 다른 동전들로만 사용해서 나오는 최소값. (최소 사용 동전 갯수)

	if (k >= cost[n]) result = min(result, coin(n, k - cost[n])+1);
	// 위에서 계산한 result값(다른 동전들로만 구성해서 K원을 만들었을 때 사용하는 최소 동전갯수)과 현재 동전을 한번 써서 만들 수 있는 k-cost[n]값을 만들 있는 최소 동전 갯수+1 비교해서 더 작은 값을 result에 저장.
	//coin()함수 뒤에 +1하는 이유 : 현재 동전 cost[n]을 한번 빼고 시작하는 거니까 한번 뺀 횟수 더해줘야 함.
	dp[n][k] = result;
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> cost[i];

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) dp[i][j] = -1;
	}
	int result = coin(0, K); //coin(0,K) : 0번동전까지 사용해서(동전 모두 사용) K원을 만들 때, 사용되는 최소 동전 갯수. 이는 배열에 저장되어 있음. 결국 dp[0][K]값을 return 한다고 생각하면 됨.
	if (result == INF) cout << "-1\n";
	else cout << result << '\n';
	return 0;
}
