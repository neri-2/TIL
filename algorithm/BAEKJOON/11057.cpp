#include <iostream>
#include <vector>

// #11057 오르막 수

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<vector<int>> dp;
	int N;
	int result = 10;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < 9; i++) {
		v.push_back(1);
	}
	dp.push_back(v);
	for (int i = 1; i < N; i++) {
		vector<int> v;
		int sum = 0;
		for (int j = 0; j < 9; j++) {
			sum += dp[i - 1][j] % 10007;
		}
		v.push_back(sum % 10007);
		result += sum % 10007;
		for (int j = 0; j < 8; j++) {
			sum -= dp[i - 1][j] % 10007;
			v.push_back(sum % 10007);
			result += sum % 10007;
		}
		dp.push_back(v);
	}
	cout << result % 10007 << '\n';
	return 0;
}