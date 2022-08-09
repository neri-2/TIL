#include <iostream>
#include <vector>
#include <algorithm>

// #1965 상자넣기

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> v; // 상자 크기 배열
	vector<int> dp; // 넣은 상자 개수 배열
	dp.push_back(1); // 첫 상자 개수 1개

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i < n; i++) {
		int max = 0; // 최대의 상자 개수
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) { // 이전의 상자의 크기가 현재 상자의 크기보다 작을 경우
				if (max < dp[j]) // 자신보다 작은 크기 중 안에 들어있는 개수가 가장 많은 상자 찾기
					max = dp[j];
			}
		}
		dp.push_back(max + 1); // 가장 많은 상자 + 1 해주기
	}

	sort(dp.rbegin(), dp.rend()); // 가장 큰 수 찾기 위해 정렬

	cout << dp[0] << '\n';

	return 0;
}