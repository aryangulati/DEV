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

	for (int i = 0; i <= n; i++) {
		//write your code here
		for (int j = 0; j  <= n; j++) {
			if (j <= n - i) {
				cout << " ";
			}
			else {
				cout << "*";
			}


		}
		cout << endl;
	}

	return 0;
}

