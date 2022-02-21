#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define INF 987654321
struct Data {
	int x, y;
	Data() {};
	Data(int x, int y) : x(x), y(y) {};
};
int M, N, ans;
int box[MAXN][MAXN], day[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<Data> v;
bool flag;
queue<Data> q;

void bfs() {
	
	int nx, ny;
	Data curr;
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		visited[curr.x][curr.y] = true;
		for (int i = 0; i < 4; i++) {
			nx = curr.x + dx[i];
			ny = curr.y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (box[nx][ny] == -1 || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			day[nx][ny] = min(day[nx][ny], day[curr.x][curr.y] + 1);
			ans = max(ans, day[nx][ny]);
			q.push(Data(nx, ny));
		}
	}
}
void check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0 && !visited[i][j]) {
				ans = -1; break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			day[i][j] = INF;
			if (box[i][j] == 1) { 
				q.push(Data(i, j)); 
				day[i][j] = 0;
			}
			if (!flag && box[i][j] == 0) flag = true;
		}
	}
	if (!flag) {
		cout << "0";
		return 0;
	}


	bfs();
	check();
	cout << ans;

	return 0;
}
