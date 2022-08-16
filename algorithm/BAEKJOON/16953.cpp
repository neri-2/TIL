#include <iostream>
#include <queue>

// #16953 A �� B

using namespace std;

int a, b;

queue<pair<long long,int>> q; // ����ü�� �����ߴٰ� pair�� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long result = -1;
	cin >> a >> b;
	q.push(make_pair(a, 1));
	while (!q.empty()) {
		long long n = q.front().first; // 2 ���ϰų� 1�� �߰��ϴ� �������� int ���� �ʰ�
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

// ���� �ʰ� ����