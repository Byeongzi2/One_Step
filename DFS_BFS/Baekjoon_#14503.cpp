#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int N,M,r,c,d,cnt;
int area[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct Data {
	int x,y,status,cnt;
	Data() {};
	Data(int x, int y, int status,int cnt) : x(x), y(y), status(status), cnt(cnt) {};
	
};

void bfs(int x, int y, int s) {
	queue<Data> q;
	cnt++;
	q.push(Data(x,y,s,0));
	Data curr;
	int nx,ny,ns;
	
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		if(curr.cnt==4) {
			ns = (curr.status+2)%4;
			nx = curr.x+dx[ns];
			ny = curr.y+dy[ns];
			if(area[nx][ny]==1) break;
			else q.push(Data(nx,ny,curr.status,0));
			continue;
		}
		visited[curr.x][curr.y] = true;
		ns = curr.status;
		ns--;
		if(ns<0) ns+=4;
		nx = curr.x+dx[ns];
		ny = curr.y+dy[ns];
		
		if(!visited[nx][ny]&&area[nx][ny]==0) {
			q.push(Data(nx,ny,ns,0));
			cnt++;
		}
		else q.push(Data(curr.x,curr.y,ns,curr.cnt+1));
		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	cin>>r>>c>>d;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) {
			cin>>area[i][j];
		}
	}
	bfs(r,c,d);
	cout<<cnt;
	return 0;
}
