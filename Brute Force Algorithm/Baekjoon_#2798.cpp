#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define INF 987654321

int N,M;
int card[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>card[i];
	
	int MIN = INF;
	for(int i=0;i<N-2;i++){
		for(int j=i+1;j<N-1;j++){
			for(int h=j+1;h<N;h++) {
				int sum = card[i]+card[j]+card[h];
				if(sum<=M) {
					if(M-sum<MIN) MIN = M-sum;
				}
			}
		}
	}
	cout<<M-MIN;
	
	return 0;
}
