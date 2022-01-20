#include<bits/stdc++.h>
using namespace std;

int N,num;
stack<int> st;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>s;
		if(s=="push") {
			cin>>num;
			st.push(num);	
		}
		else if (s=="pop") {
			if(st.size()==0) {
				cout<<"-1\n";
				continue;
			}
			num = st.top();
			cout<<num<<'\n';
			st.pop();
		}
		else if (s=="size") cout<<st.size()<<'\n';
		else if (s=="empty"){
			if(!st.size()) cout<<"1\n";
			else cout<<"0\n";
		}
		else if (s=="top") {
			if(!st.size()) cout<<"-1\n";
			else {
				num = st.top();
				cout<<num<<'\n';
			}
		}
	}
	
	return 0;
}
