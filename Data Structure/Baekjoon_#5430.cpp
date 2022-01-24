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
		//���� �ϳ��� �ȵ���ִٰ� ������ error�� �ƴ�
		// ���� ���µ� fun���� 'D'�϶��� error��!!!  
	
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
				if (flag % 2) { //�ڿ�������
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
