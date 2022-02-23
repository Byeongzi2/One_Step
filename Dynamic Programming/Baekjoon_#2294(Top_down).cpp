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
	//base�� : n�� ������ �������� K���� 0�� ���� �ʾҴٸ� ���� �� ���� ���̹Ƿ� INF�� ��ȯ
	// n�� ������ ���µ� K���� 0�̶�� ���� �� �ִ� ���̹Ƿ� count�س��� base ������ 0�� ��ȯ.


	if (dp[n][k] != -1) return dp[n][k]; // �̹� �տ��� ����ߴٸ� �̸� ���� ���� ��ȯ

	int result = coin(n + 1, k); // ���� ���� ������ ������� �ʰ� �ٸ� ������θ� ����ؼ� ������ �ּҰ�. (�ּ� ��� ���� ����)

	if (k >= cost[n]) result = min(result, coin(n, k - cost[n])+1);
	// ������ ����� result��(�ٸ� ������θ� �����ؼ� K���� ������� �� ����ϴ� �ּ� ��������)�� ���� ������ �ѹ� �Ἥ ���� �� �ִ� k-cost[n]���� ���� �ִ� �ּ� ���� ����+1 ���ؼ� �� ���� ���� result�� ����.
	//coin()�Լ� �ڿ� +1�ϴ� ���� : ���� ���� cost[n]�� �ѹ� ���� �����ϴ� �Ŵϱ� �ѹ� �� Ƚ�� ������� ��.
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
	int result = coin(0, K); //coin(0,K) : 0���������� ����ؼ�(���� ��� ���) K���� ���� ��, ���Ǵ� �ּ� ���� ����. �̴� �迭�� ����Ǿ� ����. �ᱹ dp[0][K]���� return �Ѵٰ� �����ϸ� ��.
	if (result == INF) cout << "-1\n";
	else cout << result << '\n';
	return 0;
}
