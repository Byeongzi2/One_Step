#include<bits/stdc++.h>
using namespace std;

int N,num;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	while(N--) {
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()), v.end());
	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<" ";
	}
	return 0;
}
