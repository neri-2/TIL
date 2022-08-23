#include <iostream>
#include <vector>

// #4963 ���� ����

using namespace std;

// 8���� �̵� �迭
const int WAY[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 }, { 1, 1 } };

void dfs(int w, int h, int y, int x, vector<vector<bool>> m, vector<vector<bool>> &c) { // ������ �� üũ
	c[y][x] = true; // �湮 üũ
	for (int i = 0; i < 8; i++) { // 8���� �̵�
		int t_y, t_x;
		// �迭 �������� ����� ������ �̵�
		if (y + WAY[i][0] >= 0 && y + WAY[i][0] < h)
			t_y = y + WAY[i][0];
		else continue;
		if (x + WAY[i][1] >= 0 && x + WAY[i][1] < w)
			t_x = x + WAY[i][1];
		else continue;
		// ������ �湮���� ���� ���̸�
		if (m[t_y][t_x] == true && !c[t_y][t_x])
			dfs(w, h, t_y, t_x, m, c); // ���
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w, h;
	
	while (1) {
		int cnt = 0;
		vector<vector<bool>> Map;
		vector<vector<bool>> check;

		cin >> w >> h;

		if (!w && !h)
			break;

		for (int i = 0; i < h; i++) {
			vector<bool> tmp;
			vector<bool> z;

			for (int j = 0; j < w; j++) {
				bool num;
				cin >> num;
				tmp.push_back(num);
				z.push_back(0);				
			}

			Map.push_back(tmp);
			check.push_back(z);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				// ������ �湮���� ���� ���̸�
				if (Map[i][j] == true && !check[i][j]) {
					dfs(w, h, i, j, Map, check);
					cnt++; // ��� �Լ� ����Ǹ� �Ѱ��� �̾��� �� ī��Ʈ
				}
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}