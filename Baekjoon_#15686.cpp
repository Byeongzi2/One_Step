#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
#define INF 987654321
int N,M,num,MIN = INF, cnt, ans;
int city[MAXN][MAXN];

struct Data {
	int x,y;
	Data(){};
	Data (int x, int y) : x(x), y(y) {};
};
vector<Data> house,chicken;

int calDist(int idx) {
	int x = chicken[idx].x;
	int y = chicken[idx].y;
	int sum=0;
	for(int i=0;i<house.size();i++) {
		sum+=(abs(house[i].x-x) + abs(house[i].y-y));
	}
	return sum;
}
void backtrack(int idx) {
	if(idx>=13) return;
	if(cnt==M) {
		if(ans<MIN) MIN = ans;
		return;
	}
	num = calDist(idx);
	ans +=num;
	cnt++;
	backtrack(idx+1);
	ans-=num;
	cnt--;
	backtrack(idx+1);
	
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	
	for(int i=0;i<N; i++) {
		for(int j=0; j<N; j++ ){
			cin>>num;
			if(num==1) house.push_back(Data(i,j));
			if(num==2) chicken.push_back(Data(i,j));
		}
	}
	backtrack(0);
	cout<<MIN;
	return 0;
}
