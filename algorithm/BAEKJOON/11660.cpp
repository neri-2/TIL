#include <iostream>
#include <vector>

// #11660 구간 합 구하기 5

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
			tmp.push_back(sum); // 행의 값을 누적 합으로 입력
		}
		v.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		int ans = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1 - 1; j <= x2 - 1; j++) {
			// (x1, y1)부터 (x2, y2)의 합은
			// 누적 합 배열의 y2 - (y1 - 1)의 값을 x1 ~ x2만큼 계산한 값과 같다
			if (y1 == 1)
				ans += v[j][y2 - 1];
			else
				ans += v[j][y2 - 1] - v[j][y1 - 2];
		}
		cout << ans << '\n';
	}
	return 0;
}