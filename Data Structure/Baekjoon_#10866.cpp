#include<bits/stdc++.h>
using namespace std;

int N,num;
deque<int> d;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	while(N--) {
		cin>>s;
		if(s=="push_front"){
			cin>>num;
			d.push_front(num);
		}
		else if (s=="push_back"){
			cin>>num;
			d.push_back(num);
		}
		else if (s=="pop_front") {
			if(d.empty()) {
				cout<<"-1\n";
				continue;
			}
			num = d.front();
			d.pop_front();
			cout<<num<<'\n';
		}
		else if (s=="pop_back") {
			if(d.empty()) {
				cout<<"-1\n";
				continue;
			}
			num=d.back();
			d.pop_back();
			cout<<num<<'\n';
		}
		else if (s=="size") {
			cout<<d.size()<<'\n';
		}
		else if (s=="empty") {
			if(d.empty()) cout<<"1\n";
			else cout <<"0\n";
		}
		else if (s=="front") {
			if(d.empty()) {
				cout<<"-1\n";
				continue;
			}
			num=d.front();
			cout<<num<<'\n';
		}
		else if (s=="back") {
			if(d.empty()) {
				cout<<"-1\n";
				continue;
			}
			num = d.back();
			cout<<num<<'\n';
		}
	}
	return 0;
}
