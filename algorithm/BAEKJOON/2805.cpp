#include <iostream>
#include <vector>
#include <algorithm>

// #2805 나무 자르기

using namespace std;

vector<int> v;
int n, m;

int b_s() { // 이분 탐색 구현
	long long lo = 0, hi = v[n - 1]; // 자를 나무 중 가장 긴 나무
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long tmp = 0;
		for (auto o : v) {
			if (o - mid > 0) // 자를 나무 - 중간값이 0보다 클 때
				tmp += o - mid; // 합 구하기
		}
		if (tmp >= m) // 자른 나무의 총 길이가 m보다 크거나 같을 때
			lo = mid; // 자르는 길이를 줄여야 함
		else // 작을 때
			hi = mid; // 반대
	}
	return lo;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		v.push_back(h);
	}
	sort(v.begin(), v.end());
	cout << b_s() << '\n';
	return 0;
}