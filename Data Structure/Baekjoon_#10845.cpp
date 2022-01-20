#include<bits/stdc++.h>
using namespace std;

int N,num;
queue<int> q;
string s;
bool flag;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	while(N--) {
		cin>>s;
		if(q.empty()) flag = true;
		else flag = false;
		
		if(s=="push") {
			cin>>num;
			q.push(num);
		}
		else if (s=="pop") {
			if(flag) {
				cout<<"-1\n";
				continue;
			}
			num = q.front();
			q.pop();
			cout<<num<<'\n';
		}
		else if(s=="size") cout<<q.size()<<'\n';
		else if (s=="empty") {
			if(flag) cout<<"1\n";
			else cout<<"0\n";
		}
		else if (s=="front"){
			if(flag) {
				cout<<"-1\n";
				continue;
			}
			num = q.front();
			cout<<num<<'\n';
		}
		else if (s=="back") {
			if(flag) {
				cout<<"-1\n";
				continue;
			}
			num = q.back();
			cout<<num<<'\n';
		}
	}
	return 0;
}
