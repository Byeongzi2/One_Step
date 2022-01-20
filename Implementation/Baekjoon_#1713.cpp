#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

struct Data {
	int num, vote, time;
	Data() {};
	Data(int num, int vote, int time) : num(num), vote(vote), time(time) {};
	bool operator<(const Data d) const {
		if(vote==d.vote) return time>d.time;
		return vote > d.vote;
	}
};

Data arr[MAXN];
bool nominated[MAXN];
int N,total,student;
priority_queue<Data> pq;

void init() {
	int Qsize = pq.size();
	while(!pq.empty()) pq.pop();
	int cnt =0;
	for(int i=1; i<101; i++) {
		if(cnt==N) break;
		if(nominated[i]) {
			pq.push(arr[i]);
			cnt++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*
	pq.push(Data(2,1,0));
	pq.push(Data(1,3,1));
	pq.push(Data(4,1,2));
	Data curr;
	while(!pq.empty()) {
		curr=pq.top();
		cout<<"num: "<<curr.num<<"/ vote: "<<curr.vote<<"/ time: "<<curr.time<<'\n';
		pq.pop();
	}
	*/
	
	cin>>N>>total;
	int tmp,cnt=0;
	Data curr;
	for(int i=0;i<total;i++) {
		cin>>tmp;
		arr[tmp].num = tmp;
		arr[tmp].vote++;
		if(!nominated[tmp]) arr[tmp].time = i;
		
		if(nominated[tmp]) {
			init();
			continue;
		}
		
		if(pq.size()<N) {
			pq.push(arr[tmp]);
			nominated[tmp] = true;
		} 
		else {
			curr = pq.top();
			pq.pop();
			arr[curr.num].time = 0;
			arr[curr.num].vote = 0;
			nominated[curr.num] = false;
			nominated[tmp] = true;
			pq.push(arr[tmp]);
		}
	}	
	for(int i=1;i<101;i++) {
		if(nominated[i]) cout<<i<<' ';
	}
	
	return 0;
}
