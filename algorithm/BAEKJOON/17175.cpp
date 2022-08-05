#include <iostream>
#include <vector>

using namespace std;

// #17175 피보나치는 지겨웡~

int fibonacci(int n) {
	vector<int> k;
	k.push_back(1);
	k.push_back(1);
	for (int i = 2; i <= n; i++) {
		k.push_back((k[i - 1] + k[i - 2] + 1) % 1000000007);
	}
	return k[n];
}

int main() {
	int n;
	cin >> n;
	cout << fibonacci(n) % 1000000007 << '\n';
	return 0;
}