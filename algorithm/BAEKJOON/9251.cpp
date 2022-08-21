#include <iostream>
#include <vector>
#include <string>

// #9251 LCS

using namespace std;	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max_num = 0;
	vector<vector<int>> dp; // 이차원 배열로 lcs 저장
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i <= s1.size(); i++) {
		vector<int> temp;
		for (int j = 0; j <= s2.size(); j++) { // s1[i]와 s2[j] 비교
			if (!i)
				temp.push_back(0);
			else if (!j)
				temp.push_back(0);
			else if (s1[i - 1] == s2[j - 1]) {
				temp.push_back(dp[i - 1][j - 1] + 1); // 같을 경우 i, j위치보다 한칸 전의 최댓값 + 1
				if (dp[i - 1][j - 1] + 1 > max_num)
					max_num = dp[i - 1][j - 1] + 1;
			}
			else
				temp.push_back(max(dp[i - 1][j], temp[j - 1])); // 다를 경우 전에 나온 수열 중 가장 긴 값 저장
		}
		dp.push_back(temp);
	}
	cout << max_num << '\n';
	return 0;
}

//참고: https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence