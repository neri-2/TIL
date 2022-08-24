#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> card;
	vector<int> dp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		card.push_back(p);
	}
	for (int i = 0; i < n; i++) {
		int max = card[i];
		for (int j = 0; j < i; j++) {
			if (dp[j] + dp[i - j - 1] > max)
				max = dp[j] + dp[i - j - 1];
		}
		dp.push_back(max);
	}
	cout << dp[n - 1] << '\n';
	return 0;
}