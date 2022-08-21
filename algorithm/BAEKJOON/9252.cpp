#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #9251 LCS

using namespace std;	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max_num = 0;
	int max_i, max_j = 0;
	vector<char> ans;
	vector<vector<int>> dp;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i <= s1.size(); i++) {
		vector<int> temp;
		for (int j = 0; j <= s2.size(); j++) {
			if (!i)
				temp.push_back(0);
			else if (!j)
				temp.push_back(0);
			else if (s1[i - 1] == s2[j - 1]) {
				temp.push_back(dp[i - 1][j - 1] + 1);
				if (dp[i - 1][j - 1] + 1 > max_num) {
					max_num = dp[i - 1][j - 1] + 1;
					max_i = i;
					max_j = j;
					// �ִ밪 ��ǥ ����
				}
			}
			else
				temp.push_back(max(dp[i - 1][j], temp[j - 1]));
		}
		dp.push_back(temp);
	}
	cout << max_num << '\n';
	while (max_num > 0) {		
		if (dp[max_i - 1][max_j] == max_num) { // ��ĭ ���� �迭�� ���� ���̶��
			max_i--;
		}
		else if (dp[max_i][max_j - 1] == max_num) { // ��ĭ ���� �迭�� ���� ���̶��
			max_j--;
		}
		else if (dp[max_i - 1][max_j - 1] == max_num - 1) { // �� ���ڿ��� ���ڰ� ���� ��� ���� �迭�� ���� �� ��ǥ ������ ��ġ ����
			ans.push_back(s1[max_i - 1]);
			max_i--;
			max_j--;
			max_num--;
		}
	}
	reverse(ans.begin(), ans.end()); // ����
	for (auto o : ans)
		cout << o;
	return 0;
}