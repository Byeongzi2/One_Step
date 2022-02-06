#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct Data {
	int x, y;
	Data() {};
	Data(int x, int y) : x(x), y(y) {};

};
int sdoku[9][9];

vector<Data> blank;
bool rownum[10], colnum[10], num[10];
bool flag;
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

	for (int i = (x-x%3); i <= (x-x%3+2) ; i++) {
		for (int j = (y-y%3); j <= (y-y%3+2); j++) {
			if (sdoku[i][j] == 0) continue;
			if (!num[sdoku[i][j]]) num[sdoku[i][j]] = true;
			else return false;
		}
	}
	return true;
}
void backtrack(int idx, int nx, int ny) {
	if (idx == blank.size()) {
		flag = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (flag) return;
		sdoku[nx][ny] = i;
		if (check(nx, ny)) { 
			if (idx + 1 == blank.size()) backtrack(idx + 1, 0, 0);
			else backtrack(idx + 1, blank[idx + 1].x, blank[idx + 1].y);
		}
	}
	if (!flag) sdoku[nx][ny] = 0;
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
	backtrack(0,blank[0].x,blank[0].y);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sdoku[i][j] << ' ';
		}
		cout << '\n';
	}
	/*for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sdoku[i][j] << ' ';
			if (j % 3 == 2) cout << '|';
		}
		if (i % 3 == 2) {
			cout << '\n';
			cout << "--------------------";
		}
		
		cout << '\n';
	}*/
	return 0;
}