#include <iostream>
#include <vector>

// #4673 ¼¿ÇÁ ³Ñ¹ö

using namespace std;

bool self[10001] = { 0, };

void cal(int num) {
	
	int s_num = num;
	while (num!=0) {
		s_num += num % 10;
		num /= 10;
	}
	if (s_num > 10000)
		return;
	self[s_num] = true;
	cal(s_num);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10000; i++) {
		if (!self[i])
			cal(i);
	}
	for (int i = 1; i <= 10000; i++) {
		if (!self[i])
			cout << i << '\n';
	}
	return 0;
}