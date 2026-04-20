#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

static bool isOperator(const string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

static int applyOperator(int left, int right, char op) {
	if (op == '+') return left + right;
	if (op == '-') return left - right;
	if (op == '*') return left * right;
	return left / right;
}

int main() {
	int n;
	cin >> n;

	Stack s;
	init(&s);

	for (int i = 0; i < n; ++i) {
		string token;
		cin >> token;

		if (isOperator(token)) {
			int right = peek(&s);
			pop(&s);
			int left = peek(&s);
			pop(&s);
			int result = applyOperator(left, right, token[0]);
			push(&s, result);
		} else {
			push(&s, stoi(token));
		}
	}

	cout << peek(&s) << '\n';
	return 0;
}
