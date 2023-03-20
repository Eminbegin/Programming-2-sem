#include <iostream>
#include <vector>
#include "CircularBuffer.h"
#include "algorithms.h"
#include <algorithm>

int BAZA = 228;

template<typename T>
bool lessSto(T t) {
    return t < 100;
}

template<typename T>
bool lessTen(T t) {
    return t < 10;
}

template<typename T>
bool eqFour(T t) {
    return t == 4;
}

template<typename T>
bool lessZero(T t) {
    return t < 0;
}

template<typename T>
bool equals(T t1, T t2) {
    return t1 == t2;
}

template<typename T>
void print(T t) {
    std::cout << t << std::endl;
}

int main() {
    CircularBuffer<int> buffer(3);
    buffer.push_back(1);
    buffer.push_front(2);
    buffer.push_back(3);
    buffer.push_front(4);
    buffer.push_front(4);
    buffer.resize(1000);
    buffer.pop_front();
    buffer.print(std::cout); std::cout << std::endl;
    buffer.push_front(4);

    buffer.print(std::cout); std::cout << std::endl;
    std::cout << buffer[BAZA - BAZA] << "\n";
    std::cout << "a " << en::all_of(buffer.begin(), buffer.end(), lessZero<int>) << std::endl;
    std::cout << en::partitioned(buffer.begin(), buffer.end(), eqFour<int>) << std::endl;
    return 0;
}