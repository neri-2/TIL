#include <iostream>
#include <vector>

// #2003 수들의 합 2

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> v;

	int sum = 0, cnt = 0, left = 0, right = 0;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	while (1) {
		if (sum < M) {
			if (right > N - 1)
				break;
			else
				sum += v[right++];
		}
		else {
			if (left > N - 1)
				break;
			else {
				if (sum == M)
					cnt++;
				sum -= v[left++];
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
