#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
#define INF 987654321
struct Data {
	int idx,v;
	Data(){};
	Data(int idx, int v) : idx(idx), v(v) {};
	bool operator<(const Data d) const {
		return v<d.v;
	} 
};
int height[MAXN],weight[MAXN],ans[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<Data> pqh;
	priority_queue<Data> pqw;
	int N,w,h;
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>w>>h;
		pqw.push(Data(i,w));
		pqh.push(Data(i,h));
	}
	Data x,y;
	int cnt = 1;
	while(!pqw.empty()) {
		x = pqw.top();
		y = pqh.top();
		weight[x.idx] = cnt;
		height[y.idx] = cnt;
		cnt++;
	}	
	int MAX = -1;
	for(int i=1;i<=N;i++) {
		if (weight[i]==height[i]) {
			ans[i] = weight[i];
			if(weight[i]>MAX) MAX = weight[i];
		}
		else ans[i] = INF;
	}
	return 0;
}
