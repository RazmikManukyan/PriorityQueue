#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Vector/Vector.h"
#include <stdexcept>

class PriorityQueue {
private:
    Vector<int> heap;

    void heapifyUp(int);
    void heapifyDown(int);

public:
    PriorityQueue() = default;

    void push(int);
    int top();
    void pop();
    bool empty() const;
    int size() const;

    friend std::ostream& operator<<(std::ostream&, const PriorityQueue&);
};

#endif //PRIORITYQUEUE_H
