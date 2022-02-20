#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

struct Data {
	int x,y;
	Data(){};
	Data(int x, int y) : x(x), y(y) {};
};

int w,h,Island,nx,ny;
int mapp[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<Data> v;
int dx[8] = {-1,1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};

void bfs(int x, int y) {
	queue<Data> q;
	q.push(Data(x,y));
	visited[x][y] = true;
	Data curr;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		for(int i=0;i<8;i++) {
			nx = curr.x+dx[i];
			ny = curr.y+dy[i];
			if(nx<0||nx>=h||ny<0||ny>=w) continue;
			if(visited[nx][ny]||mapp[nx][ny]==0) continue;
			visited[nx][ny] = true;
			q.push(Data(nx,ny));
		}
	
	}
}

void init() {
	v.clear();
	Island = 0;
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			visited[i][j] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1) {
		cin>>w>>h;
		if(w==0&&h==0) break;
		
		init();
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++) {
				cin>>mapp[i][j];
				if(mapp[i][j]==1) v.push_back(Data(i,j));
			}
		}
		for(int i=0;i<v.size();i++) {
			if(!visited[v[i].x][v[i].y]) {
				bfs(v[i].x,v[i].y);
				Island++;
			}
		}
		cout<<Island<<'\n';
		
	}
	return 0;
}
