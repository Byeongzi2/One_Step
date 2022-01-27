#include<bits/stdc++.h>
using namespace std;

int x,y;
int sum;
string today[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
int check(int month) {
	if(month==4||month==6||month==9||month==11) {
		return 30;
	}
	else if (month==2) {
		return 28;
	}
	else return 31;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>x>>y;
	int tmp;
	for(int i=1;i<x;i++) {
		tmp = check(i);
		sum+=tmp;
	}
	sum+=y;
	cout<<today[sum%7]<<'\n';
	
	return 0;
}
