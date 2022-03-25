#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define ll long long
#define INF 1e10+1
// 아... 소마 포폴쓰느라 업뎃못했다..........
struct Data {
	int node;
	ll weight;
	Data(){};
	Data(int node, ll weight) : node(node), weight(weight) {};
	bool operator<(const Data d) const {
		return weight>d.weight;
	}
};

int n,m;
vector<Data> v[MAXN];
priority_queue<Data> pq;
ll cost[MAXN];
int parent[MAXN];
vector<int> path;
void Dijkstra(int x) {
	cost[x] = 0;
	parent[x] = x;
	pq.push(Data(x,0));
	Data curr,next;
	while(!pq.empty()) {
		curr = pq.top();
		pq.pop();
		for(int i=0;i<v[curr.node].size();i++) {
			next = v[curr.node].at(i);
			if(cost[next.node]<=cost[curr.node]+next.weight) continue;
			parent[next.node] = curr.node;
			pq.push(Data(next.node,cost[next.node]));
			cost[next.node] = cost[curr.node]+next.weight;
		}
	}
} 
void route(int x) {
	while(parent[x]!=x) {
		path.push_back(x);
		x = parent[x];
	} 
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	int a,b;
	ll w;
	for(int i=0;i<=n;i++) {
		cost[i] = INF;
	}
	for(int i=0;i<m;i++) {
		cin>>a>>b>>w;
		v[a].push_back(Data(b,w));
	}
	cin>>a>>b;
	Dijkstra(a);
	route(b);
	cout<<cost[b]<<'\n'<<path.size()+1<<'\n';
	cout<<a<<" ";
	for(int i=path.size()-1;i>=0;i--) {
		cout<<path[i]<<" ";
	}
	return 0;
}
