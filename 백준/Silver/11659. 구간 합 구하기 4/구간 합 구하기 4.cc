#include <iostream>
#include <vector>


using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v(100000);
	int N, M;
	cin >> N >> M;
	int num;
	cin >> num;
	v[0] = num;
	for (int i = 1; i < N; i++) {
		int num;
		cin >> num;
		v[i] = v[i - 1] + num; // 합을 배열에 입력
	}
	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		if (i == 1) {
			cout << v[j - 1] << '\n';
			continue;
		}
		cout << v[j - 1] - v[i - 2] << '\n';
	}
	return 0;
} // push_back 시간초과?