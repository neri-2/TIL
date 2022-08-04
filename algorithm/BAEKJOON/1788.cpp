#include <iostream>
#include <vector>

using namespace std;

// #1788 피보나치 수의 확장

int fibonacci(int n) {
	vector<int> k;
	k.push_back(0);
	k.push_back(1);
	for (int i = 2; i <= n; i++) {
		k.push_back((k[i - 1] + k[i - 2]) % 1000000000);
	}
	return k[n];
}

int main() {
	int n;
	cin >> n;
	if (n > 0)
		cout << 1 << '\n';
	else if (n == 0) {
		cout << 0 << '\n';
	}
	else {
		if (n % 2 == 0) // 문제에서 체크 못한 부분
			cout << -1 << '\n'; // f(n)은 n이 음수 짝수일 때 음수
		else
			cout << 1 << '\n'; // f(n)은 n이 음수 홀수일 때 양수
		n *= -1;
	}
	cout << fibonacci(n) % 1000000000 << '\n';
	return 0;
}