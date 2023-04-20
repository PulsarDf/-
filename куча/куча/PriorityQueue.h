#pragma once
#include <vector>
#include <iostream>

using namespace std;
using std::vector;

class PriorityQueue {
private:
    vector<int> A;
    int PARENT(int);
    int LEFT(int);
    int RIGHT(int);
    void shift_up(int);
    void shift_down(int);

public:
    PriorityQueue(int x);
    ~PriorityQueue();

    unsigned int size();
    bool empty();
    void push(int);
    void pop();
    int top();
    void clear();

    void printAsArray();
    void printAsTree(int p,int level);
};
