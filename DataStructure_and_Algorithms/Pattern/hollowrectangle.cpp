#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// start code from here
	//cout << "Hello";
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (i == 0 or i == n - 1) {
				cout << "*";
			}
			else {
				if (j == 0 or j == n - 2) {
					cout << "*";
				}
				else {
					cout << " ";
				}

			}

		}
		cout << endl;
	}


	return 0;
}
