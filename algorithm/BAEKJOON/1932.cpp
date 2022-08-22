#include <iostream>
#include <vector>
#include <algorithm>

// #1932 정수 삼각형

using namespace std;	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dp[501] = { 0, };
	vector<vector<int>> tri;
	int n;
	cin >> n;

	// 삼각형 수 배열 저장
	for (int i = 0; i <= n; i++) {
		vector<int> temp;
		temp.push_back(0);
		if (!i) {
			tri.push_back(temp);
			continue;
		}
		for (int j = 1; j <= i; j++) {
			int t;
			cin >> t;
			temp.push_back(t);
		}
		tri.push_back(temp);
	}

	// DP 계산 구현
	for (int i = 1; i <= n; i++) {
		vector<int> tmp;
		for (int j = 1; j < tri[i].size(); j++) {
			if (j == 1) {
				// 가장 왼쪽의 수는 오른쪽 대각선 하나의 수만 더할 수 있음
				tmp.push_back(tri[i][j] + dp[j - 1]);
			}
			else if (j == tri[i].size() - 1) {
				// 가장 왼쪽의 수는 왼쪽 대각선 하나의 수만 더할 수 있음
				tmp.push_back(tri[i][j] + dp[j - 2]);
			}
			else {
				// 전의 대각선 수 중 큰 수의 합 저장
				tmp.push_back(tri[i][j] + max(dp[j - 2], dp[j - 1]));
			}
		}
		for (int i = 0; i < tmp.size(); i++) {
			dp[i] = tmp[i]; // 계산값 DP 저장
		}
	}
	sort(dp, dp + n, greater<>());
	cout << dp[0] << '\n';
	return 0;
}