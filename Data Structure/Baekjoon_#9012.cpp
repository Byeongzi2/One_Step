#include<bits/stdc++.h>
using namespace std;

int T;
stack<char> s;
string c;
bool flag;
int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>T;
	while(T--) {
		cin>>c;
		for(int i=0;i<c.size();i++) {
			if(c[i]=='(') s.push(c[i]);
			else if(c[i]==')') {
				if(s.empty()) {
					flag = true;
					break;
				}
				s.pop();
			}
		}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";	
	}
	return 0;
}

