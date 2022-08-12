#include <iostream>
#include <string>

// #2941 크로아티아 알파벳

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (i != 0 && s[i] == '=') {
			if (s[i - 1] == 'c' || s[i - 1] == 's') {
				cnt++;
				i--;
			}
			else if (s[i - 1] == 'z') {
				if (i - 1 != 0 && s[i - 2] == 'd') {
					cnt++;
					i -= 2;
				}
				else {
					cnt++;
					i--;
				}
			}
			else
				continue;
		}
		else if (i != 0 && s[i] == '-')
			if (s[i - 1] == 'c' || s[i - 1] == 'd') {
				cnt++;
				i--;
			}
			else
				continue;
		else if (i != 0 && s[i] == 'j')
			if (s[i - 1] == 'l' || s[i - 1] == 'n') {
				cnt++;
				i--;
			}
			else
				cnt++;
		else
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}