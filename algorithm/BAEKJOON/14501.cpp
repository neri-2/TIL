#include <iostream>
#include <vector>

using namespace std;

// #14501 Επ»η

int main() {
	int N;
	vector<int> f;
	cin >> N;
	f.push_back(0);
	f.push_back(1);
	for (int i = 2; i <= N; i++) {
		f.push_back(f[i - 2] + f[i - 1]);
	}
	cout << f[N] << '\n';
	return 0;
}