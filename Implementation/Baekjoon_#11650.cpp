#include<bits/stdc++.h>
using namespace std;

struct Data {
	int x, y;
	Data(){};
	Data(int x, int y) : x(x), y(y) {};
};
bool cmp(const Data &a, const Data &b) {
	if(a.x<b.x) return true;
	else if(a.x==b.x) {
		if(a.y<b.y) return true;
		else return false;
	}
	else return false;
}
int N, x,y;
vector<Data> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	while(N--) {
		cin>>x>>y;
		v.push_back(Data(x,y));
	}
	sort(v.begin(),v.end(),cmp);
	Data tmp;
	for(int i=0;i<v.size();i++) {
		tmp = v[i];
		cout<<tmp.x<<" "<<tmp.y<<'\n';
	}
	return 0;
} 
