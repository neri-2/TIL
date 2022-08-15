#include <iostream>
#include <vector>

// #18111 ����ũ����Ʈ

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, b;
	int min = 256, max = 0;
	int result_time = 2147483647, result_height = 0;
	vector<vector<int>> block;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			if (t < min)
				min = t;
			if (t > max)
				max = t;
			tmp.push_back(t);
		}
		block.push_back(tmp);
	}
	for (int h = min; h <= max; h++) { // ���� ���� ���� ���̺��� ���� ���� ���� ���̱���
		int t_b = b; // �κ��丮 ������ �ִ� �� �� �ӽ� ����
		int time = 0; // �̹� ���̿����� �ҿ� �ð�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (block[i][j] > h) { // �� ���� �� �κ��丮 ����
					time += (block[i][j] - h) * 2; // ���Ŵ� 2��
					t_b += block[i][j] - h; // ���� üũ
				}
				if (block[i][j] < h) { // �� ��ġ �� �κ��丮 ����
					time += h - block[i][j]; // ��ġ�� 1��
					t_b -= h - block[i][j]; // ���� üũ
				}
			}
		}
		if (t_b < 0) { // �۾� �Ϸ� �� �κ��丮 �� ���� ������ �� = 0�� �̸��� ��
			continue; // �Ұ����ϱ� ������ �ѱ��
		}
		else if (time <= result_time) {
			result_time = time; // ���� ���� �ɸ� �ð� ���ϱ�
			if (h > result_height)
				result_height = h; // �� �� ���� ���� ���� ���ϱ�
		}
	}
	cout << result_time << ' ' << result_height << '\n';
	return 0;
}

// Ʋ�� ����
// �� ����, ��ġ �� ���� ���� �� �� ������ ������� ����
// -> ����, ��ġ �۾� ������ ���� ������ ��� �۾� �Ϸ� �� �κ��丮�� ���� ���Ͽ� �������� ���� �ľ��ؾ� ��