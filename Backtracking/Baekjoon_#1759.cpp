#include<bits/stdc++.h>
using namespace std;
#define MAXN 16
int L,C;
char arr[MAXN],key[MAXN];
int cnt;

set<char> s = {'a','e','i','o','u'};
bool cmp(const char &a, const char &b) {
	return a<b;
}
bool check() {
	int x=0,y=0;
	for(int i=0;i<L;i++) {
		if(s.find(key[i])==s.end()) y++;
		else x++;
	}
	if(x>=1 && y>=2) return true;
	else return false;
}
void printKey() {
	char tmp;
	for(int i=0;i<L;i++) {
		cout<<key[i];
	}
	cout<<'\n';
}
void dfs(int idx) {
	if(cnt==L || idx==C) return;
	
	key[cnt] = arr[idx];
	cnt++;
	dfs(idx+1);
	if(cnt==L&&check()) printKey();
	cnt--;
	key[cnt]=' ';	
	
	dfs(idx+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>L>>C;
	for(int i=0;i<C;i++) {
		cin>>arr[i];
	}
	sort(arr,arr+C,cmp);
	dfs(0);
	return 0;
}
