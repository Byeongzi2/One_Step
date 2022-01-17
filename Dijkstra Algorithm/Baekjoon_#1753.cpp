#include<bits/stdc++.h>
using namespace std;
#define MAXN 20001
#define INF 987654321

struct Data {
	int node, weight;
	Data() {};
	Data(int node, int weight) : node(node), weight(weight) {};
	bool operator<(const Data d) const {
		return weight > d.weight; // ¿À¸§Â÷¼ø Á¤·Ä½Ã. 
	}
};

vector<Data> v[MAXN];
bool visited[MAXN];
int weight[MAXN];
priority_queue<Data> pq;

int V,E,K;
int a,b,w;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>V>>E>>K;
	
	for(int i=1;i<=V;i++) {
		weight[i] = INF;
	}
	
	for(int i=0; i<E; i++) {
		cin>>a>>b>>w;
		v[a].push_back(Data(b,w));
	}
	
	pq.push(Data(K,0));
	weight[K] = 0;
	
	Data curr,next;
	while(!pq.empty()) {
		curr = pq.top();
		pq.pop();
		
		if(visited[curr.node]) continue;
		visited[curr.node] = true;
		for(int i=0;i<v[curr.node].size(); i++) {
			next=v[curr.node].at(i);
			weight[next.node] = min(weight[next.node], weight[curr.node] + next.weight);
			pq.push(Data(next.node, weight[next.node]));
		}
	}
	
	for(int i=1; i<=V;i++) {
		if(weight[i] == INF) cout<<"INF\n";
		else cout<<weight[i]<<'\n';
	}
	return 0;
}
