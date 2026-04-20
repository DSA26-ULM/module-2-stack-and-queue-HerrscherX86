#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
	if (q == nullptr) {
		throw std::invalid_argument("queue pointer is null");
	}

	q->front = q->data - 1;
	q->rear = q->data - 1;
}

bool isEmpty(const Queue* q) {
	if (q == nullptr) {
		throw std::invalid_argument("queue pointer is null");
	}

	return q->front == (q->data - 1);
}

bool isFull(const Queue* q) {
	if (q == nullptr) {
		throw std::invalid_argument("queue pointer is null");
	}
	if (isEmpty(q)) {
		return false;
	}

	const int* nextRear = (q->rear == (q->data + MAX - 1)) ? q->data : (q->rear + 1);
	return nextRear == q->front;
}

void enqueue(Queue* q, int value) {
	if (q == nullptr) {
		throw std::invalid_argument("queue pointer is null");
	}
	if (isFull(q)) {
		throw std::overflow_error("queue overflow");
	}

	if (isEmpty(q)) {
		q->front = q->data;
		q->rear = q->data;
		*(q->rear) = value;
		return;
	}

	q->rear = (q->rear == (q->data + MAX - 1)) ? q->data : (q->rear + 1);
	*(q->rear) = value;
}

void dequeue(Queue* q) {
	if (q == nullptr) {
		throw std::invalid_argument("queue pointer is null");
	}
	if (isEmpty(q)) {
		throw std::underflow_error("queue underflow");
	}

	if (q->front == q->rear) {
		q->front = q->data - 1;
		q->rear = q->data - 1;
		return;
	}

	q->front = (q->front == (q->data + MAX - 1)) ? q->data : (q->front + 1);
}

int front(const Queue* q) {
	if (q == nullptr) {
		throw std::invalid_argument("queue pointer is null");
	}
	if (isEmpty(q)) {
		throw std::underflow_error("queue is empty");
	}

	return *(q->front);
}

int back(const Queue* q) {
	if (q == nullptr) {
		throw std::invalid_argument("queue pointer is null");
	}
	if (isEmpty(q)) {
		throw std::underflow_error("queue is empty");
	}

	return *(q->rear);
}