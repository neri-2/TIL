#include <iostream>
#include <vector>
#include <algorithm>

// #10815 숫자 카드

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	vector<int> p, q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p.push_back(num);
	}
	sort(p.begin(), p.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		q.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		cout << binary_search(p.begin(), p.end(), q[i]) << ' ';
	}
	cout << '\n';
	return 0;
}