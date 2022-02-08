#include<bits/stdc++.h>
using namespace std;
#define MAXN 26

struct Data{
	int x,y;
	Data() {};
	Data(int x, int y) : x(x), y(y) {};
};
int N,house,party;
int arr[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<Data> q;

void bfs(Data d) {
	int nx,ny;
	queue<Data> bfsQ;
	bfsQ.push(d);
	visited[d.x][d.y] = true;
	Data curr;
	while(!bfsQ.empty()) {
		curr = bfsQ.front();
		bfsQ.pop();
		house++;
		for(int i=0;i<4;i++) {
			nx = curr.x + dx[i];
			ny = curr.y + dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N||arr[nx][ny]==0) continue;
			if(!visited[nx][ny]) {
				visited[nx][ny] = true;
				bfsQ.push(Data(nx,ny)); 
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	vector<int> ans;
	string s;
	for(int i=0;i<N;i++) {
		cin>>s;
		for(int j=0;j<N;j++) {
			arr[i][j] = s[j]-'0';
			if(arr[i][j]==1) q.push(Data(i,j));
		}
	} 
	
	Data tmp;
	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		if(!visited[tmp.x][tmp.y]) {
			bfs(tmp);
			party++;
			ans.push_back(house);
			house=0;
		}
	}
	cout<<party<<'\n';
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<'\n';
	}
	return 0;
}
