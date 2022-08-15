#include <iostream>
#include <vector>

// #10844 ���� ��� ��

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> stair; // arr[i][j] = ���̰� j�� �� �� ���ڸ��� i�� ���� ����
	int n;
	long long result = 0;
	cin >> n;

	for (int i = 0; i <= 9; i++) { // 1�� �ڸ��� ��� �迭�� �Է�
		vector<int> temp;
		if (i == 0)
			temp.push_back(0);
		else
			temp.push_back(1);
		stair.push_back(temp);
	}

	for (int i = 1; i < n; i++) { // n�� �ڸ����� dp

		for (int j = 0; j <= 9; j++)
			stair[j].push_back(0);

		for (int j = 0; j <= 9; j++) {
			if (j == 0) { // ���� ���� 0�� ��� ���� ���̰� �þ �� ������ �� �ڸ��� 1 �ϳ��ۿ� ����
				stair[1][i] += stair[j][i - 1];
				stair[1][i] %= 1000000000;
			}
			else if (j == 9) { // ���� ���� 9�� ��� ���� ���̰� �þ �� ������ �� �ڸ��� 8 �ϳ��ۿ� ����
				stair[8][i] += stair[j][i - 1];
				stair[8][i] %= 1000000000;
			}
			else { // ������ ���ڸ��� �� �� ���� �þ �� �ֱ� ������ +2
				stair[j - 1][i] += stair[j][i - 1];
				stair[j - 1][i] %= 1000000000;
				stair[j + 1][i] += stair[j][i - 1];
				stair[j + 1][i] %= 1000000000;
			}

		}
	}
	for (int i = 0; i <= 9; i++) {	
			result += stair[i][n - 1] % 1000000000; // ������ ���̰� n�� ���� ���� ���ϱ�
			result %= 1000000000;
	}
	cout << result % 1000000000 << '\n';
	return 0;
}