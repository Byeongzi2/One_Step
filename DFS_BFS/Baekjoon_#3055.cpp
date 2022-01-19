#include<bits/stdc++.h>
#define MAXN 51
#define INF 987654321
using namespace std;

int R,C;
char c;
char forestMAP[MAXN][MAXN];
int path[MAXN][MAXN];
int water[MAXN][MAXN];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int tx,ty,startX, startY,bx,by;
struct Data {
	int x, y;
	Data() {};
	Data(int x, int y) : x(x), y(y) {};
};

void bfs(int px, int py, int arr[MAXN][MAXN],int cnt) {
	bool flag = false;
	int nx, ny;
	queue<Data> q;
	q.push(Data(px,py));
	arr[px][py] = 0;
	Data next;
	while(!q.empty()) {
		next = q.front(); q.pop();
		for(int g=0; g<4; g++) {
			nx = next.x+dx[g];
			ny = next.y+dy[g];
		
			if(0<=nx&&nx<R&&0<=ny&&ny<C) {
				if(arr[nx][ny]!=INF) continue; 
				if(forestMAP[nx][ny]!='D' || forestMAP[nx][ny] != 'X') {
					if(cnt==2&&(arr[next.x][next.y]+1)>=water[nx][ny]) continue;
					q.push(Data(nx,ny));
					arr[nx][ny] = arr[next.x][next.y]+1;
				}
				if(cnt==2&&forestMAP[nx][ny]=='D') {
					arr[nx][ny] = arr[next.x][next.y]+1;
					flag = true;
					break;
				}
			}
		}
		if(flag) break;
	}
	if(cnt==2&&flag) cout<<arr[bx][by]<<'\n';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>R>>C;

	for(int i=0;i<R;i++){
		for(int j=0; j<C; j++) {
			cin>>forestMAP[i][j];
			path[i][j] = INF;
			water[i][j] = INF;
			if(forestMAP[i][j]=='*') {
				tx = i; ty = j;
			}
			if(forestMAP[i][j]=='S') {
				startX = i; startY = j;
			}
			if(forestMAP[i][j]=='D') {
				bx=i; by=j;
			}
		}
	}
	bfs(tx,ty,water,1);
	bfs(startX,startY,path,2);
	
	for(int i=0;i<R;i++){
		for(int j=0; j<C; j++) {
			if(path[i][j]==INF) cout<<"0 ";
			else cout<<path[i][j]<<' ';
		}
		cout<<'\n';
	}
	
	
	return 0;
}
