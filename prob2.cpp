#include "queue.h"
#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	if (k <= 0 || k > n) {
		cout << '\n';
		return 0;
	}

	Queue q;
	init(&q);

	long long windowSum = 0;
	int windowCount = 0;
	bool firstPrinted = false;

	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;

		enqueue(&q, value);
		windowSum += value;
		++windowCount;

		if (windowCount > k) {
			windowSum -= front(&q);
			dequeue(&q);
			--windowCount;
		}

		if (windowCount == k) {
			if (firstPrinted) {
				cout << ' ';
			}
			cout << windowSum;
			firstPrinted = true;
		}
	}

	cout << '\n';
	return 0;
}
