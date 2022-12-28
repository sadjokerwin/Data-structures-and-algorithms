#pragma once
#include <queue>
#include <iostream>
using namespace std;
template <typename T>
void printAll(queue<T> Q);

template <typename T>
void printSome(queue<T> Q, size_t numOfPrintedElems);

template <typename T>
void clear(queue<T> &Q);