#include<bits/stdc++.h>
#define MAXN 51
#define INF 987654321
using namespace std;

struct Data {
	int x, y;
	Data() {};
	Data(int x, int y) : x(x), y(y) {};
};
int R, C;
char c;
char forestMAP[MAXN][MAXN]; //�� ���� ����  
int path[MAXN][MAXN], water[MAXN][MAXN]; //path : ����ġ�� ��� , water : ���� ��� 
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int startX, startY, bx, by;
bool visited[MAXN][MAXN]; //�� ��� ���� �� �ʿ��� visit Ȯ�� ���� 
queue<Data> waterQ;


void bfs(int px, int py, int arr[MAXN][MAXN], int cnt) { //cnt==1 : �� ����  cnt==2 : ����ġ ����  
	bool flag = false;
	int nx, ny;
	queue<Data> q;
	q.push(Data(px, py));
	arr[px][py] = 0;
	if (cnt == 1) visited[px][py] = true;
	Data next;
	while (!q.empty()) {
		next = q.front(); q.pop();
		for (int g = 0; g < 4; g++) {
			nx = next.x + dx[g];
			ny = next.y + dy[g];

			if (0 <= nx && nx < R && 0 <= ny && ny < C) {
				if (cnt==2 && arr[nx][ny] != INF) continue; // ����ġ ������ INF�� �ɷ����� 
				if (cnt == 1 && visited[nx][ny]) continue; // �� ������ visited �迭�� �ɷ����� (���� ������ �����ؾ� �ؼ� INF�δ� ���ɷ���)
				 
				if (forestMAP[nx][ny] != 'D' && forestMAP[nx][ny] != 'X') {
					if ((arr[next.x][next.y] + 1) >= water[nx][ny]) continue;
					//if (cnt == 1 && arr[next.x][next.y] + 1 >= arr[nx][ny]) continue;
					q.push(Data(nx, ny));
					arr[nx][ny] = arr[next.x][next.y] + 1;
					if (cnt == 1) visited[nx][ny] = true;
				}
				if (cnt == 2 && forestMAP[nx][ny] == 'D') {
					arr[nx][ny] = arr[next.x][next.y] + 1;
					flag = true;
					break;
				}
			}
		}
		if (flag) break;
	}
	if (cnt == 2 && flag) cout << arr[bx][by] << '\n';
	if (cnt == 2 && !flag) cout << "KAKTUS\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> forestMAP[i][j];
			path[i][j] = INF;
			water[i][j] = INF;
			if (forestMAP[i][j] == '*') {
				waterQ.push(Data(i, j));
			}
			if (forestMAP[i][j] == 'S') {
				startX = i; startY = j;
			}
			if (forestMAP[i][j] == 'D') {
				bx = i; by = j;
			}
		}
	}

	Data now;
	while (!waterQ.empty()) {
		memset(visited, false, sizeof(visited));
		now = waterQ.front();	waterQ.pop();
		bfs(now.x, now.y, water, 1);
		
	}
	bfs(startX, startY, path, 2);

	return 0;
}

