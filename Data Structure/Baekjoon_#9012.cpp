#include<bits/stdc++.h>
using namespace std;

int T;
stack<char> s;
string c;
bool flag;

void init() {
	flag = false;
	if (s.empty()) return;
	while (!s.empty()) s.pop();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		init();
		cin >> c;
		for (int i = 0; i < c.size(); i++) {
			if (c[i] == '(') s.push('(');
			else if (c[i] == ')') {
				if (s.empty()) {
					flag = true;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) flag = true;
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}

