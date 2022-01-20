#include<bits/stdc++.h>
using namespace std;

int N, sum;
priority_queue<int> A;
priority_queue<int, vector<int> ,greater<int>> B;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int num;
	for (int g = 0; g < 2; g++) {
		for (int i = 0; i < N; i++) {
			cin >> num;
			if (g == 0) A.push(num);
			else B.push(num);
		}
	}
	int a, b;
	while (!A.empty()) {
		a = A.top(); A.pop();
		b = B.top(); B.pop();
		sum += (a*b);
	}
	cout << sum;
	return 0;
}
