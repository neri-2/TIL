#include <iostream>
#include <vector>

// #11660 ���� �� ���ϱ� 5

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> v;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int sum = 0;
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			sum += t;
			tmp.push_back(sum); // ���� ���� ���� ������ �Է�
		}
		v.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		int ans = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1 - 1; j <= x2 - 1; j++) {
			// (x1, y1)���� (x2, y2)�� ����
			// ���� �� �迭�� y2 - (y1 - 1)�� ���� x1 ~ x2��ŭ ����� ���� ����
			if (y1 == 1)
				ans += v[j][y2 - 1];
			else
				ans += v[j][y2 - 1] - v[j][y1 - 2];
		}
		cout << ans << '\n';
	}
	return 0;
}