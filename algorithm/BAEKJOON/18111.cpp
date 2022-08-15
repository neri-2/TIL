#include <iostream>
#include <vector>

// #18111 마인크래프트

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
	for (int h = min; h <= max; h++) { // 가장 낮은 땅의 높이부터 가장 높은 땅의 높이까지
		int t_b = b; // 인벤토리 가지고 있는 블럭 수 임시 저장
		int time = 0; // 이번 높이에서의 소요 시간
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (block[i][j] > h) { // 블럭 제거 후 인벤토리 저장
					time += (block[i][j] - h) * 2; // 제거는 2초
					t_b += block[i][j] - h; // 갯수 체크
				}
				if (block[i][j] < h) { // 블럭 설치 후 인벤토리 제거
					time += h - block[i][j]; // 설치는 1초
					t_b -= h - block[i][j]; // 갯수 체크
				}
			}
		}
		if (t_b < 0) { // 작업 완료 후 인벤토리 블럭 수가 부족할 때 = 0개 미만일 때
			continue; // 불가능하기 때문에 넘기기
		}
		else if (time <= result_time) {
			result_time = time; // 가장 적게 걸린 시간 구하기
			if (h > result_height)
				result_height = h; // 그 중 가장 높은 높이 구하기
		}
	}
	cout << result_time << ' ' << result_height << '\n';
	return 0;
}

// 틀린 이유
// 블럭 제거, 설치 시 보유 중인 블럭 수 변경을 고려하지 못함
// -> 제거, 설치 작업 순서가 없기 때문에 모든 작업 완료 후 인벤토리의 갯수 비교하여 가능한지 유무 파악해야 함