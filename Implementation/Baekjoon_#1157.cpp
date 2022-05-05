#include<bits/stdc++.h>
using namespace std;
#define MAXN 30

int alpha[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	int maxcnt=0;
	int maxindex;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if(s[i]>90) {
			alpha[s[i]-'a']++;
		}
		else alpha[s[i]-'A']++;
	}
	for(int i=0;i<26;i++) {
		if(alpha[i]>maxcnt) {
			maxcnt=alpha[i];
			maxindex=i;
			v.clear();
			v.push_back(i);
		}
		else if (alpha[i]==maxcnt) {
			v.push_back(i);
		}
	}
	if(v.size()>1) {
		cout<<'?';
	}
	else cout<<char(maxindex+'A');
	return 0;
}
