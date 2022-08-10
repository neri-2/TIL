#include <iostream>

// #1748 수 이어 쓰기 1

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int check = 10, ans = 0, p = 1;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i == check) {
			p++; // 자리수 크기
			check *= 10; // 다음번 자리수 증가 숫자
		}
		ans += p; // 수 자리수만큼 더해주기
	}
	cout << ans << '\n';
	return 0;
}