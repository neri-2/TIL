#include <iostream>
#include <vector>
#include <algorithm>

// #2096 내려가기

using namespace std;

//dp 배열을 1차원 배열로 누적 합으로 해당 인덱스 값을 계속 갱신
vector<int> dp_min = { 0,0,0 };
vector<int> dp_max = { 0,0,0 };

// 0의 경우 0, 1 
// 1의 경우 0, 1, 2
// 2의 경우 1, 2
// 인덱스와 계산 가능

int min_c(int num, int j) {
	int min_num = 0;
	switch (j) {
	case 0:
		min_num = min(num + dp_min[j + 1], num + dp_min[j]);
		break;
	case 1:
		min_num = min({ num + dp_min[j - 1], num + dp_min[j], num + dp_min[j + 1] });
		break;
	case 2:
		min_num = min(num + dp_min[j - 1], num + dp_min[j]);
		break;
	}
	return min_num;
}

int max_c(int num, int j) {
	int max_num = 0;
	switch (j) {
	case 0:
		max_num = max(num + dp_max[j + 1], num + dp_max[j]);
		break;
	case 1:
		max_num = max({ num + dp_max[j - 1], num + dp_max[j], num + dp_max[j + 1] });
		break;
	case 2:
		max_num = max(num + dp_max[j - 1], num + dp_max[j]);
		break;
	}
	return max_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		vector<int> temp_min = { 0,0,0 };
		vector<int> temp_max = { 0,0,0 };
		for (int j = 0; j < 3; j++) {
			int num;
			cin >> num;
			// j 인덱스와 더한 j - 1 인덱스의 값들 중 최소, 최대 값을 dp j 인덱스에 저장
			temp_min[j] = min_c(num, j);
			temp_max[j] = max_c(num, j);
		}
		for (int j = 0; j < 3; j++) {
			dp_min[j] = temp_min[j];
			dp_max[j] = temp_max[j];
		}
	}
	// 마지막 인덱스의 3 숫자 중 최소, 최대값 구한 후 출력
	cout << max({ dp_max[0], dp_max[1], dp_max[2] }) << ' ' << min({ dp_min[0], dp_min[1], dp_min[2] }) << '\n';
	return 0;
}

// 참고: https://yhwan.tistory.com/14