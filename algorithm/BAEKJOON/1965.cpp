#include <iostream>
#include <vector>
#include <algorithm>

// #1965 ���ڳֱ�

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> v; // ���� ũ�� �迭
	vector<int> dp; // ���� ���� ���� �迭
	dp.push_back(1); // ù ���� ���� 1��

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i < n; i++) {
		int max = 0; // �ִ��� ���� ����
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) { // ������ ������ ũ�Ⱑ ���� ������ ũ�⺸�� ���� ���
				if (max < dp[j]) // �ڽź��� ���� ũ�� �� �ȿ� ����ִ� ������ ���� ���� ���� ã��
					max = dp[j];
			}
		}
		dp.push_back(max + 1); // ���� ���� ���� + 1 ���ֱ�
	}

	sort(dp.rbegin(), dp.rend()); // ���� ū �� ã�� ���� ����

	cout << dp[0] << '\n';

	return 0;
}