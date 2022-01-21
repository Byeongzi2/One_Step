#include<bits/stdc++.h>
using namespace std;

list<char> sen;
int M;
string s;
char c,add;
list<char>::iterator iter;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>s;
	cin>>M;
	
	for(int i=0;i<s.size();i++) {
		sen.push_back(s[i]);
	}
	iter = sen.end();
	
	for(int i=0;i<M;i++) {
		cin>>c;
		if(c=='L') {
			if(iter==sen.begin()) continue;
			iter--;
		} 
		if(c=='D') {
			if(iter==sen.end()) continue;
			iter++;
		}
		if(c=='B') {
			if(iter==sen.begin()) continue;
			iter = sen.erase(--iter);
		}
		if(c=='P') {
			cin>>add;
			sen.insert(iter,add);
		}
	}
	for(iter = sen.begin();iter!=sen.end();iter++) {
		cout<<*iter;
	}
	return 0;
}
