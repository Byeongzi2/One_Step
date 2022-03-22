#include<bits/stdc++.h>
using namespace std;
#define MAXN 50001
#define INF 987654321
// 다익스트라 복습
struct Data {
	int node,weight;
	Data(){};
	Data(int node, int weight) : node(node), weight(weight) {};
	bool operator<(const Data d) const {
		return weight>d.weight;
	}
};

int N,M,A,B,C;
vector<Data> v[MAXN];
int weight[MAXN];
bool visited[MAXN];
void Dijkstra(int start) {
	priority_queue<Data> pq;
	pq.push(Data(start,0));
	weight[start] = 0;
	
	Data curr;
	while(!pq.empty()) {
		curr = pq.top();
		pq.pop();
		if(visited[curr.node]) continue;
		visited[curr.node] = true;
		Data next;
		for(int i=0;i<v[curr.node].size();i++) {
			next = v[curr.node].at(i);
			weight[next.node] = min(weight[next.node] , weight[curr.node]+next.weight);
			pq.push(Data(next.node,weight[next.node]));
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B>>C;
		v[A].push_back(Data(B,C));
		v[B].push_back(Data(A,C));
	}
	for(int i=0;i<=N;i++) weight[i] = INF;
	Dijkstra(1);
	cout<<weight[N];
	return 0;
}

