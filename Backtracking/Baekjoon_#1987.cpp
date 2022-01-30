#include<iostream>
using namespace std;
#define MAXN 21
int R, C, ans, nx, ny, MAX;
char arr[MAXN][MAXN];
bool alpha[26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void backtrack(int x, int y) {
	if (alpha[arr[x][y] - 'A']) return;
	alpha[arr[x][y] - 'A'] = true;
	ans++;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		backtrack(nx, ny);
	}
	alpha[arr[x][y] - 'A'] = false;
	if (ans > MAX) MAX = ans;
	ans--;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	backtrack(0, 0);
	cout << MAX;
	return 0;
}
