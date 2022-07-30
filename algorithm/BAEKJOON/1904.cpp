#include <iostream>
#include <vector>

using namespace std;

// #1904 01타일
// 피보나치 수열과 같음

int main() {
	int N;
	vector<int> ans;
	cin >> N;
	ans.push_back(1);
	ans.push_back(2);
	for (int i = 2; i < N; i++) {
		ans.push_back(ans[i - 1] % 15746 + ans[i - 2] % 15746); // i-1에 1을 붙이는 경우의 수 + i-2에 00을 붙이는 경우의 수
	}
	cout << ans[N - 1] % 15746 << '\n';
	return 0;
}