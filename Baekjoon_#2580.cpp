#include<iostream>
#include<vector>
using namespace std;

struct Data {
	int x, y;
	Data() {};
	Data(int x, int y) : x(x), y(y) {};

};
int sdoku[9][9];
int nx, ny;
vector<Data> blank;
bool rownum[10], colnum[10], num[10];

void init() {
	memset(rownum, false, sizeof(rownum));
	memset(colnum, false, sizeof(colnum));
	memset(num, false, sizeof(num));
}
bool check(int x, int y) {
	init();
	for (int i = 0; i < 9; i++) {
		if (sdoku[i][y] != 0) {
			if (!rownum[sdoku[i][y]]) rownum[sdoku[i][y]] = true;
			else return false;
		}
		if (sdoku[x][i] != 0) {
			if (!colnum[sdoku[x][i]]) colnum[sdoku[x][i]] = true;
			else return false;
		}
		
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sdoku[x + i][y + j] == 0) continue;
			if (!num[sdoku[x + i][y + j]]) num[sdoku[x + i][y + j]] = true;
			else return false;
		}
	}
	return true;
}
void backtrack(int idx) {
	if (idx == blank.size()) return;
	
	nx = blank[idx].x;
	ny = blank[idx].y;

	for (int i = 1; i <= 9; i++) {
		sdoku[nx][ny] = i;
		if (check(nx, ny)) backtrack(idx + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdoku[i][j];
			if (sdoku[i][j] == 0) blank.push_back(Data(i, j));
		}
	}
	backtrack(0);
	cout << "\n=============================================================\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sdoku[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}