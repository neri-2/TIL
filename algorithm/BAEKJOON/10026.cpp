#include <iostream>
#include <vector>
#include <algorithm>

// #10026 적록색약

using namespace std;

vector<vector<char>> rgb;
vector<vector<bool>> check;
int N;
int cnt = 0, cnt_g = 0;
const int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void dfs(int i, int j, char c) {
	check[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int y = i, x = j;
		y += dir[k][0];
		x += dir[k][1];
		if (y < 0 || y >= N || x < 0 || x >= N)
			continue;
		if (!check[y][x] && rgb[y][x] == c)
			dfs(y, x, c);
	}
}

void dfs_g(int i, int j, char c) {
	check[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int y = i, x = j;
		y += dir[k][0];
		x += dir[k][1];
		if (y < 0 || y >= N || x < 0 || x >= N)
			continue;
		if (!check[y][x]) {
			if (c == 'B') {
				if(rgb[y][x] == 'B')
					dfs_g(y, x, c);
			}
			else {
				if(rgb[y][x] != 'B')
					dfs_g(y, x, c);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<char> t_c;
		vector<bool> t_b;
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			t_c.push_back(c);
			t_b.push_back(false);
		}
		rgb.push_back(t_c);
		check.push_back(t_b);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				dfs(i, j, rgb[i][j]);
				cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				dfs_g(i, j, rgb[i][j]);
				cnt_g++;
			}
		}
	}
	cout << cnt << ' ' << cnt_g << '\n';
	return 0;
}
