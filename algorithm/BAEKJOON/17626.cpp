#include <iostream>
#include <vector>

// #17626 Four Squares

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> v;
	int n;
	cin >> n;
	v.push_back(0);
	v.push_back(1);

	for (int i = 2; i <= n; i++) {
		int min = i;
		for (int j = 1; j*j <= i; j++) { // ������ = 1 + ������ dp
			if (j * j == i) { // �������� ���
				min = 1;
				break;
			}
			else if (min > v[j * j] + v[i - j * j]) // dp[n] = dp[i*i] + dp[n-i*i]
				min = v[j * j] + v[i - j * j]; // ��ȭ�� �� ���� ���� �� ã��
		}
		v.push_back(min);
	}
	cout << v[n] << '\n';
	return 0;
}