#include <iostream>
#include <vector>

// #2293 동전 1

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	vector<int> coin, dp;
	cin >> n >> k;

	// 동전의 가치와 가치의 합이 같을 경우 경우의 수 1 올리기 위해
	dp.push_back(1); 

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		coin.push_back(num);
	}

	for (int i = 1; i <= k; i++) {
		// dp 초기화
		dp.push_back(0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i])
				dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}

// 참고: https://debuglog.tistory.com/78