#include <bits/stdc++.h>
using namespace std;
#define MAXN 301
#define INF 987654321

int t,l,sx,sy,tx,ty;
int dist[MAXN][MAXN];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[4] = {-2,-1,1,2};
 
struct Data {
   int x,y;
   Data(){};
   Data(int x, int y) : x(x),y(y) {};
};


int bfs(int x, int y) {
   queue<Data> q;
   dist[x][y] = 0;
   q.push(Data(x,y));
   Data curr;
   int nx,ny;
   while(!q.empty()) { 
   		curr = q.front();
		q.pop();
		if(curr.x==tx&&curr.y==ty) return dist[curr.x][curr.y];
		for(int i=0;i<8;i++) {
			nx = curr.x+dx[i];
			ny = curr.y+dy[i%4];
			if(nx<0||nx>=l||ny<0||ny>=l) continue;
			if(dist[nx][ny]!=INF) continue;
			dist[nx][ny] = dist[curr.x][curr.y]+1;
			//if(nx==tx&&ny==ty) return dist[nx][ny];
			q.push(Data(nx,ny));
		}
   }
}
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin>>t;
   
   while(t--) {
      cin>>l;
      for(int i=0;i<l;i++) {
         for(int j=0;j<l;j++) {
            dist[i][j] = INF;
         }
      }
      cin>>sx>>sy>>tx>>ty;
      cout<<bfs(sx,sy)<<'\n';
   }
   return 0;
}

