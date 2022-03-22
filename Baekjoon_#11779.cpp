#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define ll long long
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
bool visited[MAXN];
int cost[MAXN];

void Dijkstra(int x) {
	cost[x] = 0;
	pq.push(Data(x,0));
	Data curr,next;
	while(!pq.empty()) {
		curr = pq.front();
		pq.pop();
		if(visited[curr.node]) continue;
		visited[curr.node] = true;
		for(int i=0;i<v[curr.node].size();i++) {
			next = v[curr.node].at(i);
			pq.push(Data(next.node,cost[next.node]));
			cost[next.node] = min(cost[next.node],cost[curr.node]+next.weight);
		}
	}
} 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	int a,b;
	ll w;
	for(int i=0;i<m;i++) {
		cin>>a>>b>>w;
		v[a].push_back(Data(b,w));
	}
	cin>>a>>b;
	Dijkstra(a);
	
	return 0;
}
