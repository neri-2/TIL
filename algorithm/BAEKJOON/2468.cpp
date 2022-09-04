#include <iostream>
#include <vector>

// #2468 안전 영역

using namespace std;

const int WAY[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int n;
int result = 1;
vector<vector<int>> map;
vector<vector<bool>> check;

void dfs(int i, int j, int h) {
	check[i][j] = true;
	for (int w = 0; w < 4; w++) {
		int t_i, t_j;
		t_i = i + WAY[w][0];
		t_j = j + WAY[w][1];
		if (t_i < 0 || t_i >= n || t_j < 0 || t_j >= n) continue;
		else if (!check[t_i][t_j] && map[t_i][t_j] > h)
			dfs(t_i, t_j, h);
	}
}

void check_init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int max_num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> t_m;
		vector<bool> t_c;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (num > max_num)
				max_num = num;
			t_m.push_back(num);
			t_c.push_back(false);
		}
		map.push_back(t_m);
		check.push_back(t_c);
	}
	for (int h = 1; h <= max_num; h++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j] && map[i][j] > h) {
					dfs(i, j, h);
					cnt++;
				}
			}
		}
		if (cnt > result)
			result = cnt;
		check_init();
	}
	cout << result << '\n';
	return 0;
}