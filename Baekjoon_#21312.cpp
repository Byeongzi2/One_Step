#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> a,b;
	int x;
	for(int i=0;i<3;i++) {
		cin>>x;
		if(x%2) b.push_back(x);
		else a.push_back(x);
	}
	int sum=1;
	if(b.empty()) {
		for(int i=0;i<3;i++) sum*=a[i];
	}
	else {
		for(int i=0;i<b.size();i++) sum*=b[i];
	}
	cout<<sum;
	return 0;
}
