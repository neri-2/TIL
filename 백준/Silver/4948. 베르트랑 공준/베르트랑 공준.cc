#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<bool> v(300000);
	while (1) {
		int n;
		int cnt = 0;
		cin >> n;
		if (!n)
			break;
		for (int i = 2; i <= n; i++) {
			if (!v[i]) {
				for (int j = 2; i * j <= n * 2; j++) {
					v[i * j] = true;
				}
			}
		}
		for (int i = n + 1; i <= n * 2; i++) {
			if (v[i] == false) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}