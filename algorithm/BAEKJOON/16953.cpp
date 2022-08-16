#include <iostream>
#include <queue>

// #16953 A → B

using namespace std;

int a, b;

queue<pair<long long,int>> q; // 구조체로 구현했다가 pair로 변경

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long result = -1;
	cin >> a >> b;
	q.push(make_pair(a, 1));
	while (!q.empty()) {
		long long n = q.front().first; // 2 곱하거나 1을 추가하는 과정에서 int 범위 초과
		int check = q.front().second;
		q.pop();

		if (n == b) {
			result = check;
			break;
		}

		if (n * 2 <= b) {
			q.push(make_pair(n * 2, check + 1));
		}
		if (n * 10 + 1 <= b) {
			q.push(make_pair(n * 10 + 1, check + 1));
		}
	}
	cout << result << '\n';
	return 0;
}

// 범위 초과 주의