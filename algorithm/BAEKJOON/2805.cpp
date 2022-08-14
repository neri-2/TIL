#include <iostream>
#include <vector>
#include <algorithm>

// #2805 ���� �ڸ���

using namespace std;

vector<int> v;
int n, m;

int b_s() { // �̺� Ž�� ����
	long long lo = 0, hi = v[n - 1]; // �ڸ� ���� �� ���� �� ����
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long tmp = 0;
		for (auto o : v) {
			if (o - mid > 0) // �ڸ� ���� - �߰����� 0���� Ŭ ��
				tmp += o - mid; // �� ���ϱ�
		}
		if (tmp >= m) // �ڸ� ������ �� ���̰� m���� ũ�ų� ���� ��
			lo = mid; // �ڸ��� ���̸� �ٿ��� ��
		else // ���� ��
			hi = mid; // �ݴ�
	}
	return lo;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		v.push_back(h);
	}
	sort(v.begin(), v.end());
	cout << b_s() << '\n';
	return 0;
}