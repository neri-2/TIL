#include <iostream>
#include <vector>
#include <algorithm>

// #1654 랜선 자르기

using namespace std;
int k, n;

long int calculate(vector<int>& v, int n) {
	long int sum = 0;
	for (auto o : v)
		sum += o / n;
	return sum;
}

int binary_search(vector<int>& v, int N) {
	long int low = 1, high = v[k - 1];
	while (low <= high) {
		long int mid = (low + high) / 2;
		long int mid_c = calculate(v, mid);
		if (N > mid_c)
			high = mid - 1;
		else if (N <= mid_c)
			low = mid + 1;
	}
	return high;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int max = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	cout << binary_search(v, n) << '\n';
	return 0;
}