#include <iostream>
#include <vector>

// #10844 쉬운 계단 수

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> stair; // arr[i][j] = 길이가 j인 수 중 끝자리가 i인 수의 갯수
	int n;
	long long result = 0;
	cin >> n;

	for (int i = 0; i <= 9; i++) { // 1의 자리인 경우 배열에 입력
		vector<int> temp;
		if (i == 0)
			temp.push_back(0);
		else
			temp.push_back(1);
		stair.push_back(temp);
	}

	for (int i = 1; i < n; i++) { // n의 자리까지 dp

		for (int j = 0; j <= 9; j++)
			stair[j].push_back(0);

		for (int j = 0; j <= 9; j++) {
			if (j == 0) { // 수의 끝이 0인 경우 수의 길이가 늘어날 때 가능한 끝 자리가 1 하나밖에 없음
				stair[1][i] += stair[j][i - 1];
				stair[1][i] %= 1000000000;
			}
			else if (j == 9) { // 수의 끝이 9인 경우 수의 길이가 늘어날 때 가능한 끝 자리가 8 하나밖에 없음
				stair[8][i] += stair[j][i - 1];
				stair[8][i] %= 1000000000;
			}
			else { // 나머지 끝자리는 양 옆 수로 늘어날 수 있기 때문에 +2
				stair[j - 1][i] += stair[j][i - 1];
				stair[j - 1][i] %= 1000000000;
				stair[j + 1][i] += stair[j][i - 1];
				stair[j + 1][i] %= 1000000000;
			}

		}
	}
	for (int i = 0; i <= 9; i++) {	
			result += stair[i][n - 1] % 1000000000; // 마지막 길이가 n인 수의 갯수 더하기
			result %= 1000000000;
	}
	cout << result % 1000000000 << '\n';
	return 0;
}