#include "PriorityQueue.h"

void PriorityQueue::heapifyUp(int index) {
    while(index > 0) {
        int parentIndex = (index - 1) / 2;
        if(heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int index) {
    int size = heap.get_size();

    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if(leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }
    if(rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if(largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void PriorityQueue::push(int val) {
    heap.push_back(val);
    int index = heap.get_size() - 1;
    heapifyUp(index);
}

int PriorityQueue::top() {
    if(!heap.empty()) {
        return heap[0];
    }
    throw std::out_of_range("Priority queue is empty!.");
}

void PriorityQueue::pop() {
    if(!heap.empty()) {
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    } else {
        throw std::out_of_range("Priority queue is empty!.");
    }
}

bool PriorityQueue::empty() const {
    return heap.empty();
}

int PriorityQueue::size() const {
    return heap.get_size();
}

std::ostream& operator<<(std::ostream& os, const PriorityQueue& pq) {
    os << "PriorityQueue: ";
    for(int i = 0; i < pq.size(); ++i) {
        os << pq.heap[i] << " ";
    }
    return os;
}