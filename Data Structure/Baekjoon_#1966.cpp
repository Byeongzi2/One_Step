#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

struct Data {
	int idx, priority;
	Data() {};
	Data(int idx, int priority) : idx(idx), priority(priority) {};
};

int T, N, M;
queue<Data> q;
int arr[MAXN];
int tmp, cnt, p;
Data curr;

void init() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < N; i++) arr[i] = 0;
	cnt = 0; p = 0;
}

bool cmp(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		if (N == 1) {
			cin >> tmp;
			cout << "1\n";
			continue;
		}
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			arr[i] = tmp;
			q.push(Data(i, tmp));
		}
		sort(arr, arr + N, cmp);
		while (1) {
			curr = q.front();
			if (curr.priority < arr[p]) {
				q.push(curr);
				q.pop();
			}
			else {
				if (curr.idx == M) {
					cout << ++cnt << '\n';
					break;
				}
				q.pop();
				p++;
				cnt++;
			}
		}
		init();

	}
	return 0;
}
