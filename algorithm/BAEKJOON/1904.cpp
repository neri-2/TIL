#include <iostream>
#include <vector>

using namespace std;

// #1904 01Ÿ��
// �Ǻ���ġ ������ ����

int main() {
	int N;
	vector<int> ans;
	cin >> N;
	ans.push_back(1);
	ans.push_back(2);
	for (int i = 2; i < N; i++) {
		ans.push_back(ans[i - 1] % 15746 + ans[i - 2] % 15746); // i-1�� 1�� ���̴� ����� �� + i-2�� 00�� ���̴� ����� ��
	}
	cout << ans[N - 1] % 15746 << '\n';
	return 0;
}