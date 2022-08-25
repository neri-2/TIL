#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> v;
	vector<int> dp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	dp.push_back(v[0]);
	if (n >= 2)
		dp.push_back(v[0] + v[1]);
	for (int i = 2; i < n; i++) {
		if (i == 2)
			dp.push_back(max({ dp[i - 1], dp[i - 2] + v[i], v[i - 1] + v[i] }));
		else
			dp.push_back(max({ dp[i - 1], dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i] }));
	}
	cout << dp[n - 1] << '\n';
	return 0;
}