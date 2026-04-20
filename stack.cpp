#include "stack.h"

#include <stdexcept>

void init(Stack* s) {
	if (s == nullptr) {
		throw std::invalid_argument("stack pointer is null");
	}

	s->top = s->data - 1;
}

bool isEmpty(const Stack* s) {
	if (s == nullptr) {
		throw std::invalid_argument("stack pointer is null");
	}

	return s->top < s->data;
}

bool isFull(const Stack* s) {
	if (s == nullptr) {
		throw std::invalid_argument("stack pointer is null");
	}

	return s->top == (s->data + MAX - 1);
}

void push(Stack* s, int value) {
	if (s == nullptr) {
		throw std::invalid_argument("stack pointer is null");
	}
	if (isFull(s)) {
		throw std::overflow_error("stack overflow");
	}

	++(s->top);
	*(s->top) = value;
}

void pop(Stack* s) {
	if (s == nullptr) {
		throw std::invalid_argument("stack pointer is null");
	}
	if (isEmpty(s)) {
		throw std::underflow_error("stack underflow");
	}

	--(s->top);
}

int peek(const Stack* s) {
	if (s == nullptr) {
		throw std::invalid_argument("stack pointer is null");
	}
	if (isEmpty(s)) {
		throw std::underflow_error("stack is empty");
	}

	return *(s->top);
}
