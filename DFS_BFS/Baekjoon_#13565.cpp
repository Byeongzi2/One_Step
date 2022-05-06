#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

struct Data {
	int x,y;
	Data(){};
	Data(int x, int y) : x(x), y(y) {};
};
int M,N;
string s;
int mapp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dxy[4] = {-1,1,0,0};
bool flag;
void dfs(int x, int y) {
	visited[x][y] = true;
	if(x==M-1) {
		flag=true;
		return;
	}
	int nx,ny;
	for(int i=0;i<4;i++) {
		nx = x+dxy[i];
		ny = y+dxy[3-i];
		if(nx<0||nx>=M||ny<0||ny>=N) continue;
		if(visited[nx][ny]||mapp[nx][ny]) continue;
		dfs(nx,ny);
		if(flag) return;
	}
}



/*
bool bfs(int x, int y) {
	queue<Data> q;
	q.push(Data(x,y));
	visited[x][y]= true;
	Data curr;
	int nx,ny;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		for(int i=0;i<4;i++) {
			nx = curr.x+dxy[i];
			ny = curr.y+dxy[3-i];
			if(nx<0||nx>=M||ny<0||ny>=N) continue;
			if(visited[nx][ny]||mapp[nx][ny]) continue;
			visited[nx][ny] = true;
			if(nx==M-1) return true;
			q.push(Data(nx,ny));
		}
	}
	return false;
}
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>M>>N;
	cin>>s;
	vector<Data> target;
	for(int i=0;i<N;i++) {
		mapp[0][i] = s[i]-'0';
		if(mapp[0][i]==0) target.push_back(Data(0,i));
	}
	for(int i=1;i<M;i++) {
		cin>>s;
		for(int j=0;j<N;j++) {
			mapp[i][j] = s[i]-'0';
		}
	}

	for(int i=0;i<target.size();i++) {
		dfs(target[i].x, target[i].y);
		if(flag) {
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
