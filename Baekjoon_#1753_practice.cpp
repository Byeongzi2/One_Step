#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000001
#define INF 97654321

struct Data {
	int node,weight;
	Data(){};
	Data(int node,int weight) {};
	bool operator<(const Data d) const {
		return weight>d.weight;
	}
};
int V,E,K,a,b;
bool visited[MAXN];
int cost[MAXN];
vector<Data> v[MAXN];
priority_queue<Data> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>V>>E>>K;
	for(int i=0;i<E;i++) {
		cin>>a>>b>>w;
		v[a].push_back(Data(b,w));
	}
	for(int i=1;i<=V;i++) cost[i] =INF;
	
	cost[K] = 0;
	pq.push(Data(K,0));
	
	Data curr,next;
	while(!pq.empty()) {
		curr = pq.top();
		pq.pop();
		
		if(visited[curr]) continue;
		visited[curr] = true;
		
		for(int i=0;i<v[curr.node].size();i++) {
			next = v[curr.node].at(i);
			cost[next.node] = min(cost[next.node],cost[curr.node]+next.weight);
			pq.push(Data(next.node,cost[next.node]));
		}
	}
	
	for(int i=1;i<=V;i++) {
		if(cost[i]==INF) cout<<"INF\n";
		else cout<<cost[i]<<'\n';
	}
	return 0;
}
