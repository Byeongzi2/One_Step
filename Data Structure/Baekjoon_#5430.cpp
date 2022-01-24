#include<bits/stdc++.h>
using namespace std;

int T, n, num, flag;
bool fin;
string func, s;
char c;
deque<int> dq;

void init() {
	flag = 0;
	fin = false;
	while(!dq.empty()) dq.pop_front();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		init();
		cin >> func;
		cin >> n;
		//값이 하나도 안들어있다고 무조건 error가 아님
		// 값이 없는데 fun값이 'D'일때가 error임!!!  
	
		cin >> c;
		for (int i = 0; i < n - 1; i++) {
			cin >> num >> c;
			dq.push_back(num);
		}
		if(n!=0) {
			cin >> num;
			dq.push_back(num);
		}

		cin >> c;
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') flag++;
			else if (func[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					fin = true;
					break;
				}
				if (flag % 2) { //뒤에서부터
					dq.pop_back();
				}
				else dq.pop_front();
			}
		}
		if (fin) {
			continue;
		}

		cout << '[';
		if (flag % 2) {
			while (!dq.empty()) {
				num = dq.back();
				if (dq.size() > 1) cout << num << ',';
				else cout << num;
				dq.pop_back();
			}
		}
		else {
			while (!dq.empty()) {
				num = dq.front();
				if (dq.size() > 1) cout << num << ',';
				else cout << num;
				dq.pop_front();
			}
		}
		cout << "]\n";
	}


	return 0;
}
