#include <iostream>
#include <vector>

// #9711 피보나치

using namespace std;

uint64_t fibonacci(int num, int q) { // 수 범위 초과 int -> uint64_t
	vector<uint64_t> v;
	v.push_back(1);
	v.push_back(1);
	for (int i = 2; i < num; i++)
		v.push_back((v[i - 2] + v[i - 1]) % q);
	return v[num - 1] % q;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int P, Q;
		cin >> P >> Q;
		cout << "Case #" << i << ": " << fibonacci(P, Q) << '\n';
	}
	return 0;
}