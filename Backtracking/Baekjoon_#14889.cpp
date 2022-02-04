#include<bits/stdc++.h>
using namespace std;
#define MAXN 21
#define INF 987654321

int N,sumA,sumB,MIN,cnt;
int arr[MAXN][MAXN];
bool isteamA[MAXN];

int makeSum(vector<int> v) {
	int sum=0;
	for(int i=0;i<v.size()-1;i++) {
		for(int j=i+1; j<v.size();j++) {
			sum+=arr[v[i]][v[j]];
			sum+=arr[v[j]][v[i]];
		}
	}
	return sum;
}

void check() {
	vector<int> teamA,teamB;
	for(int i=1;i<=N;i++) {
		if(isteamA[i]) teamA.push_back(i);
		else teamB.push_back(i);
	}
	sumA = makeSum(teamA);
	sumB = makeSum(teamB);
	
	int tmp = abs(sumA-sumB);
	if(tmp<MIN) MIN = tmp;	
}
void backtrack(int x) {
	if(x>N) return;
	if(cnt==N/2) {
		check();
		return;
	}
	isteamA[x] = true;
	cnt++;
	backtrack(x+1);
	isteamA[x] = false;
	cnt--;
	backtrack(x+1);
		
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	MIN = INF;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
		}
	}
	backtrack(1);
	cout<<MIN<<'\n';
	return 0;
}
