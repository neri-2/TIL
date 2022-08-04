#include <iostream>
#include <vector>

using namespace std;

// #1788 �Ǻ���ġ ���� Ȯ��

int fibonacci(int n) {
	vector<int> k;
	k.push_back(0);
	k.push_back(1);
	for (int i = 2; i <= n; i++) {
		k.push_back((k[i - 1] + k[i - 2]) % 1000000000);
	}
	return k[n];
}

int main() {
	int n;
	cin >> n;
	if (n > 0)
		cout << 1 << '\n';
	else if (n == 0) {
		cout << 0 << '\n';
	}
	else {
		if (n % 2 == 0) // �������� üũ ���� �κ�
			cout << -1 << '\n'; // f(n)�� n�� ���� ¦���� �� ����
		else
			cout << 1 << '\n'; // f(n)�� n�� ���� Ȧ���� �� ���
		n *= -1;
	}
	cout << fibonacci(n) % 1000000000 << '\n';
	return 0;
}