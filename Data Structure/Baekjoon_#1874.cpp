#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int n,cnt,p;
stack<int> st;
int arr[MAXN];
bool flag;
vector<char> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cnt = 1;
	p = 1;
	

	while (cnt <= n || p<= n) {
		if (cnt<=n&&st.empty()) {
			st.push(cnt++);
			v.push_back('+');
			continue;
		}
	
		if (cnt > n && (st.top() != arr[p] || p>n)) {
			flag = true;
			break;
		}

		if (cnt <= n && st.top() != arr[p]) {
			st.push(cnt++);
			v.push_back('+');
			continue;
		}
		if (st.top() == arr[p]) {
			v.push_back('-');
			st.pop();
			p++;
		}
	}
	if (flag) cout << "NO\n";
	else {
		for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	}

	return 0;
}
