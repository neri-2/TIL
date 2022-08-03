#include <iostream>
#include <vector>

using namespace std;

// #9507 Generations of Tribbles

uint64_t koong(int n) {
	vector<uint64_t> k;
	k.push_back(1);
	k.push_back(1);
	k.push_back(2);
	k.push_back(4);
	for (int i = 4; i <= n; i++) {
		k.push_back(k[i - 4] + k[i - 3] + k[i - 2] + k[i - 1]);
	}
	return k[n];
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << koong(n) << '\n';
	}
	return 0;
}