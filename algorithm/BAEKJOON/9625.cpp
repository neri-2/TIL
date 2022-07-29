#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #9625 BABBA

int main() {
	int K;
	vector<int> a;
	vector<int> b;
	cin >> K;
	a.push_back(1);
	b.push_back(0);
	for (int i = 0; i < K; i++) {
		int t_a = 0, t_b = 0;
		t_a += b[i];
		t_b += a[i] + b[i];
		a.push_back(t_a);
		b.push_back(t_b);
	}
	cout << a[K] << ' ' << b[K] << '\n';
	return 0;
}