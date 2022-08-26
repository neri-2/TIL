#include <iostream>
#include <vector>

// #2293 ���� 1

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	vector<int> coin, dp;
	cin >> n >> k;

	// ������ ��ġ�� ��ġ�� ���� ���� ��� ����� �� 1 �ø��� ����
	dp.push_back(1); 

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		coin.push_back(num);
	}

	for (int i = 1; i <= k; i++) {
		// dp �ʱ�ȭ
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

// ����: https://debuglog.tistory.com/78