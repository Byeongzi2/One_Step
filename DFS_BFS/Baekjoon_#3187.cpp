#include<bits/stdc++.h>
using namespace std;
#define MAXN 251

struct Data {
	int x,y;
	Data(){};
	Data(int x,int y) : x(x), y(y){};
};
int R,C,Ssum,totalwolf;
bool visited[MAXN][MAXN];
char town[MAXN][MAXN];
queue<Data> q;
int dxy[4] = {-1,1,0,0};
Data bfs(Data d) {
	visited[d.x][d.y] = true;
	queue<Data> q;
	q.push(Data(d.x,d.y));
	int wolf = 0; int sheep = 1;
	Data curr;
	int nx,ny;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			nx = curr.x+dxy[i];
			ny = curr.y+dxy[3-i];
			if(nx<0||nx>=R||ny<0||ny>=C) continue;
			if(visited[nx][ny]||town[nx][ny]=='#') continue;
			visited[nx][ny] = true;
			if(town[nx][ny]=='v') wolf++;
			if(town[nx][ny]=='k') sheep++;
			q.push(Data(nx,ny));
		}
		
	}
	if(sheep>wolf) return Data(sheep,wolf);
	else return Data(0,0);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<Data> v;
	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++) {
			cin>>town[i][j];
			if(town[i][j]=='k') v.push_back(Data(i,j));	
			if(town[i][j]=='v') totalwolf++;
		}
	}
	Data tmp;
	for(int i=0;i<v.size();i++){
		if(!visited[v[i].x][v[i].y]){
			tmp = bfs(v[i]);
			totalwolf-=tmp.y;
			Ssum+=tmp.x;
		}
	}
	cout<<Ssum<<" "<<totalwolf;
	return 0;
}
