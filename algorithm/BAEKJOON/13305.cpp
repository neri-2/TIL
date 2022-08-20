#include <iostream>
#include <vector>

// #13305 주유소

// 정수 범위로 인해 감점 -> int > long long으로 자료형 변경

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> length;
	vector<long long> price;

	long long oil_price = 0; // 총 가격
	long long N;

	cin >> N;

	for (long long i = 0; i < N - 1; i++) {
		long long num;
		cin >> num;
		length.push_back(num);
	} // 길이 배열 입력

	for (long long i = 0; i < N; i++) {
		long long num;
		cin >> num;
		price.push_back(num);
	} // 가격 배열 입력

	price.pop_back();
	for (long long i = 0; i < N - 1; i++) {
		long long cur_price = price[i];
		// 해당 도시 기름 가격 저장
		oil_price += cur_price * length[i];
		// 기름이 0일 때는 해당 도시에서 기름 충전 필수
		for (long long j = i + 1; j < N - 1; j++) {
			if (cur_price < price[j]) {
				// 해당 도시 기름 가격보다 이후 도시 기름 가격이 비쌀 때
				oil_price += cur_price * length[j];
				// 해당 도시에서 해당 거리만큼 추가 충전
				i++;
				// 다음 도시에서 충전 X
			}
			else break;
		}
	}
	cout << oil_price << '\n';
	return 0;
}