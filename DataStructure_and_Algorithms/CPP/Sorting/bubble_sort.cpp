#include <bits/stdc++.h>
using namespace std;


void bubblesort(int a[], int n, int i) { 
	if (i == n - 1) {
		return;
	}

	for (int j = 0; j <= n - 2; j++) {
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}
}

void bubble_sort1(int *a, int n) {
	//base
	if (n == 1 or n == 0) {
		return;
	}

	//rec case
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
	bubble_sort1(a, n - 1);

}
void bubble_sort2(int *a, int i, int n) {
	//base
	if (n == 1 or n == 0) {
		return;
	}

	if (i == n - 1) {
		bubble_sort2(a, 0, n - 1);
		return;
	}

	//rec case
	if (a[i] > a[i + 1]) {
		swap(a[i], a[i + 1]);
	}
	bubble_sort2(a, i + 1, n);
}




int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// start code from here
	//cout << "Hello";

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bubblesort(a, n, 0);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}



	return 0;
}
