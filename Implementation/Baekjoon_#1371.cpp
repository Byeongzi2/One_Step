#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int arr[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	string s;
	
	// ��¥�� ������ ���� ������ �ܾ� ���� �Է¹޾Ƶ� ��.
	// = ���� getline �Լ� �� �ʿ� ����.
	// �ܼ�â���� �Է��� ������ ������ ctrl+Z �ؼ� ���� ������Ѿ� while�� ���� �����۵�. 
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
