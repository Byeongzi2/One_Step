#include<bits/stdc++.h>
using namespace std;

int a,b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	a = s.size()/10;
	b = s.size()%10;
	
	for(int i=0;i<a;i++) {
		for(int j=i*10;j<(i+1)*10;j++) {
			cout<<s[j];
		}
		cout<<'\n';
	}
	for(int i=a*10;i<a*10+b;i++) {
		cout<<s[i];
	}
	cout<<'\n';
	
	return 0;
}
