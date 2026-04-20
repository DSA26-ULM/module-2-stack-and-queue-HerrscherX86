#include "stack.h"
#include <stdexcept>

void init(Stack* s) {
    if (s == nullptr) {
        throw std::invalid_argument("Stack pointer tidak boleh null");
    }
    s->top = s->data - 1; 
}

bool isEmpty(const Stack* s) {
    if (s == nullptr) {
        throw std::invalid_argument("Stack pointer tidak boleh null");
    }
    return s->top < s->data;
}

bool isFull(const Stack* s) {
    if (s == nullptr) {
        throw std::invalid_argument("Stack pointer tidak boleh null");
    }
    return s->top == s->data + MAX - 1;
}

void push(Stack* s, int value) {
    if (s == nullptr) {
        throw std::invalid_argument("Stack pointer tidak boleh null");
    }
    
    if (isFull(s)) {
        throw std::overflow_error("Stack penuh, tidak dapat menambah elemen");
    }

    s->top++;

    *s->top = value;
}

void pop(Stack* s) {
    if (s == nullptr) {
        throw std::invalid_argument("Stack pointer tidak boleh null");
    }
    
    if (isEmpty(s)) {
        throw std::underflow_error("Stack kosong, tidak dapat menghapus elemen");
    }

    s->top--;
}

int peek(const Stack* s) {
    if (s == nullptr) {
        throw std::invalid_argument("Stack pointer tidak boleh null");
    }
    
    if (isEmpty(s)) {
        throw std::underflow_error("Stack kosong, tidak dapat melihat elemen");
    }

    return *s->top;
}
