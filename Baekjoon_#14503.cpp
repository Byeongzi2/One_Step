//돌리고 디버깅 필요
// 
#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int N,M,r,c,d,cnt;
int area[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct Data {
	int x,y,status;
	Data() {};
	Data(int x, int y, int status) : x(x), y(y), status(status) {};
	
};
void bfs(int x, int y, int s) {
	queue<Data> q;
	visited[x][y] = true;
	cnt++;
	q.push(Data(x,y,s));
	Data curr;
	int nx,ny,ns;
	
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		visited[curr.x][curr.y] = true;
		bool flag = false;
		for(int i=0;i<4;i++) {
			nx = curr.x+dx[i];
			ny = curr.y+dy[i];
			if(nx>=0||nx<N||ny>=0||ny<M) {
				if(!visited[nx][ny]&&area[nx][ny]==0) {
					flag = true;
					break;
				}
			}
		}
		if(!flag) {
			ns = (curr.status+2)%4;
			nx = curr.x+dx[ns];
			ny = curr.y+dy[ns];
			if(area[nx][ny]==1) break;
			else q.push(Data(nx,ny,curr.status));
			continue;
		}
		curr.status--;
		if(curr.status<0) curr.status+=4;
		nx = curr.x+dx[curr.status];
		ny = curr.y+dy[curr.status];
		
		if(nx>=0&&nx<N&&ny>=0&&ny<M) {
			if (!visited[nx][ny]&&area[nx][ny]==0) {
				q.push(Data(nx,ny,curr.status));
				cnt++;
				continue;
			}
		}
		q.push(Data(curr.x,curr.y,curr.status));
		
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	cin>>r>>c>>d;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) {
			cin>>area[i][j];
		}
	}
	bfs(r,c,d);
	return 0;
}
