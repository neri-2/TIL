#include <iostream>
#include <vector>
#include <algorithm>

// #1932 ���� �ﰢ��

using namespace std;	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dp[501] = { 0, };
	vector<vector<int>> tri;
	int n;
	cin >> n;

	// �ﰢ�� �� �迭 ����
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

	// DP ��� ����
	for (int i = 1; i <= n; i++) {
		vector<int> tmp;
		for (int j = 1; j < tri[i].size(); j++) {
			if (j == 1) {
				// ���� ������ ���� ������ �밢�� �ϳ��� ���� ���� �� ����
				tmp.push_back(tri[i][j] + dp[j - 1]);
			}
			else if (j == tri[i].size() - 1) {
				// ���� ������ ���� ���� �밢�� �ϳ��� ���� ���� �� ����
				tmp.push_back(tri[i][j] + dp[j - 2]);
			}
			else {
				// ���� �밢�� �� �� ū ���� �� ����
				tmp.push_back(tri[i][j] + max(dp[j - 2], dp[j - 1]));
			}
		}
		for (int i = 0; i < tmp.size(); i++) {
			dp[i] = tmp[i]; // ��갪 DP ����
		}
	}
	sort(dp, dp + n, greater<>());
	cout << dp[0] << '\n';
	return 0;
}