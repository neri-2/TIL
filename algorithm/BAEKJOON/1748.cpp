#include <iostream>

// #1748 �� �̾� ���� 1

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int check = 10, ans = 0, p = 1;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i == check) {
			p++; // �ڸ��� ũ��
			check *= 10; // ������ �ڸ��� ���� ����
		}
		ans += p; // �� �ڸ�����ŭ �����ֱ�
	}
	cout << ans << '\n';
	return 0;
}