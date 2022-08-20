#include <iostream>
#include <vector>

// #13305 ������

// ���� ������ ���� ���� -> int > long long���� �ڷ��� ����

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> length;
	vector<long long> price;

	long long oil_price = 0; // �� ����
	long long N;

	cin >> N;

	for (long long i = 0; i < N - 1; i++) {
		long long num;
		cin >> num;
		length.push_back(num);
	} // ���� �迭 �Է�

	for (long long i = 0; i < N; i++) {
		long long num;
		cin >> num;
		price.push_back(num);
	} // ���� �迭 �Է�

	price.pop_back();
	for (long long i = 0; i < N - 1; i++) {
		long long cur_price = price[i];
		// �ش� ���� �⸧ ���� ����
		oil_price += cur_price * length[i];
		// �⸧�� 0�� ���� �ش� ���ÿ��� �⸧ ���� �ʼ�
		for (long long j = i + 1; j < N - 1; j++) {
			if (cur_price < price[j]) {
				// �ش� ���� �⸧ ���ݺ��� ���� ���� �⸧ ������ ��� ��
				oil_price += cur_price * length[j];
				// �ش� ���ÿ��� �ش� �Ÿ���ŭ �߰� ����
				i++;
				// ���� ���ÿ��� ���� X
			}
			else break;
		}
	}
	cout << oil_price << '\n';
	return 0;
}