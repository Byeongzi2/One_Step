#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

struct Data {
	int x,y;
	Data(){};
	Data(int x, int y) :x(x), y(y) {};
};

int M,N,K,num;
int paper[MAXN][MAXN],visited[MAXN][MAXN];
vector<int> v;
int dxy[4] = {-1,1,0,0};
int bfs(int x, int y) {
	int cnt=0;
	queue<Data> q;
	visited[x][y] = true;
	cnt++;
	q.push(Data(x,y));
	Data curr;
	int nx,ny;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		for(int i=0;i<4;i++) {
			nx = curr.x+dxy[i];
			ny = curr.y+dxy[3-i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(visited[nx][ny]||paper[nx][ny]==1) continue;
			visited[nx][ny] = true;
			cnt++;
			q.push(Data(nx,ny));
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>M>>N>>K;
	int x1,y1,x2,y2;
	for(int i=0;i<K;i++) {
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<x2;j++){
			for(int h=y1;h<y2;h++) {
				paper[j][h] = 1;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) {
			if(paper[i][j]==0&&!visited[i][j]) {
				num = bfs(i,j);
				v.push_back(num);
			}
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<'\n';
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
