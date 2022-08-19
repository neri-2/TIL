#include <iostream>
#include <vector>
#include <algorithm>

// #2096 ��������

using namespace std;

//dp �迭�� 1���� �迭�� ���� ������ �ش� �ε��� ���� ��� ����
vector<int> dp_min = { 0,0,0 };
vector<int> dp_max = { 0,0,0 };

// 0�� ��� 0, 1 
// 1�� ��� 0, 1, 2
// 2�� ��� 1, 2
// �ε����� ��� ����

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
			// j �ε����� ���� j - 1 �ε����� ���� �� �ּ�, �ִ� ���� dp j �ε����� ����
			temp_min[j] = min_c(num, j);
			temp_max[j] = max_c(num, j);
		}
		for (int j = 0; j < 3; j++) {
			dp_min[j] = temp_min[j];
			dp_max[j] = temp_max[j];
		}
	}
	// ������ �ε����� 3 ���� �� �ּ�, �ִ밪 ���� �� ���
	cout << max({ dp_max[0], dp_max[1], dp_max[2] }) << ' ' << min({ dp_min[0], dp_min[1], dp_min[2] }) << '\n';
	return 0;
}

// ����: https://yhwan.tistory.com/14