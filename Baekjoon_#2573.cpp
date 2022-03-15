#include<bits/stdc++.h>
using namespace std;
#define MAXN 301

int N,M;
int north[MAXN][MAXN];
int dxy[4] = {-1,1,0,0};
bool visited[MAXN][MAXN];
struct Data {
	int x,y,h;
	Data(){};
	Data(int x, int y, int h) : x(x), y(y), h(h) {};
};

vector<Data> v;

bool cmp (Data a, Data b){
	return a.h>b.h;
}

void setting() {
	int nx,ny;
	
	for(int i=0;i<v.size();i++){
		if(v[i].h==0) break;
		int cnt = 0;
		for(int j=0;j<4;j++) {
			nx = v[i].x+dxy[j];
			ny = v[i].y+dxy[3-j];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(north[nx][ny]==0) cnt++;
		}
		v[i].h = max(0,v[i].h-cnt);
	}
}
void init() {
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			visited[i][j] = false;
		}
	}
}
int bfs(Data d) {
	int cnt = 1;
	queue<Data> q;
	visited[d.x][d.y] = true;
	q.push(d);
	Data curr;
	int nx,ny;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		for(int i=0;i<4;i++) {
			nx = curr.x+dxy[i];
			ny = curr.y+dxy[3-i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(north[nx][ny]!=0&&!visited[nx][ny]) {
				visited[nx][ny] = true;
				cnt++;
				q.push(Data(nx,ny,north[nx][ny]));
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int MAX = 0;
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>north[i][j];
			if(north[i][j]!=0) v.push_back(Data(i,j,north[i][j]));
			if(north[i][j]>MAX) MAX = north[i][j];
		}
	}
	bool flag = false;
	int tmp = bfs(v[0]);
	if(tmp!=v.size()) {
		cout<<0;
		return 0;
	}
	else {
		for(int i=1;i<=MAX;i++) {
			init();
			sort(v.begin(),v.end(),cmp);
			if(v[0].h==0) break;
			setting();
			tmp = bfs(v[0]);
			if(tmp!=v.size()) {
				cout<<i;
				flag = true;
				break;
			}
		}
	}
	
	if(!flag) cout<<0;
	return 0;
}
