#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int arr[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	string s;
	
	// 어짜피 공백은 세지 않으니 단어 별로 입력받아도 됨.
	// = 굳이 getline 함수 쓸 필요 없음.
	// 콘솔창에서 입력을 종료할 때에는 ctrl+Z 해서 따로 종료시켜야 while문 이하 정상작동. 
	while(cin>>s) {
		for(int i=0;i<s.size();i++) {
			if(s[i]>='a'&&s[i]<='z') {
				arr[s[i]-'a']++;
			}
		}
		s.clear();
	}
	int MAX = -1;
	for(int i=0;i<26;i++) {
		if(arr[i]>MAX) {
			v.clear();
			v.push_back(i);
			MAX = arr[i];
		}
		else if (arr[i]==MAX) {
			v.push_back(i);
		}
	}
	for(int i=0;i<v.size();i++) {
		cout<<char(v[i]+'a');
	}
	

	return 0;
}
