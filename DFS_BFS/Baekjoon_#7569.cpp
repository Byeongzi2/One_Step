#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

struct Data {
	int z,x,y;
	Data(){};
	Data(int z, int x, int y) : z(z) , x(x), y(y) {};
};
int M,N,H,cnt,total,MAX;
int box[MAXN][MAXN][MAXN],day[MAXN][MAXN][MAXN];
queue<Data> q;
bool flag;
int dxyz[4] = {-1,1,0,0};


void bfs() {
	Data curr;
	int nz,nx,ny;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		nx = curr.x;
		ny = curr.y;
		for(int i=0;i<2;i++) {
			nz = curr.z + dxyz[i];
			if(nz<0||nz>=H) continue;
			if(box[nz][nx][ny]!=0) continue;
			box[nz][nx][ny] = 1;
			day[nz][nx][ny] = day[curr.z][nx][ny]+1;
			if(day[nz][nx][ny]>MAX) MAX = day[nz][nx][ny];
			q.push(Data(nz,nx,ny));
			cnt++;
			
		}
		nz = curr.z;
		for(int i=0;i<4;i++) {
			nx = curr.x+dxyz[i];
			ny = curr.y+dxyz[3-i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(box[nz][nx][ny]!=0) continue;
			box[nz][nx][ny] = 1;
			day[nz][nx][ny] = day[nz][curr.x][curr.y] +1;
			if(day[nz][nx][ny]>MAX) MAX = day[nz][nx][ny];
			q.push(Data(nz,nx,ny));
			cnt++;
		}
		
		
		
	}	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>M>>N>>H;
	
	for(int h=0;h<H;h++) {
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++) {
				cin>>box[h][i][j];
				if(box[h][i][j]==1) q.push(Data(h,i,j));
				if(box[h][i][j]==0) {
					flag = true;
					total++;
				}
			}
		}
	}	
	
	if(!flag) {
		cout<<"0";
		return 0;
	}
	bfs();
	if(cnt!=total) cout<<"-1";
	else cout<<MAX;
	
		
	
	return 0;
}
