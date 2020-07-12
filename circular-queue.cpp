#include "circular-queue.h"
#include <iostream>
using namespace std;

CircularQueue::CircularQueue() {
    items_ = new QueueItem [16];
    head_ = 0;
    tail_ = 0;
    capacity_ = 16;
    size_ = 0;
}
CircularQueue::CircularQueue(unsigned int capacity) {
    items_ = new QueueItem [capacity];
    head_ = 0;
    tail_ = 0;
    capacity_ = capacity;
    size_ = 0;
}
CircularQueue::~CircularQueue() {
    delete [] items_;
}
bool CircularQueue::empty() const {
    return size() == 0;
}
bool CircularQueue::full() const {
    return size() == capacity_;
}
int CircularQueue::size() const {
    return size_;
}
bool CircularQueue::enqueue(QueueItem value) {
    if (full()) {
        cout << "The queue is full, can't enqueue" << endl;
        return false;
    }
    else {
        items_[tail_] = value;
        tail_ = (tail_ + 1)%capacity_;
        size_++;
        return true;
    }
}
CircularQueue::QueueItem CircularQueue::dequeue() {
    if (empty()) {
        cout << "The queue is empty, can't dequeue" << endl;
        return EMPTY_QUEUE;
    }
    else {
        QueueItem value = items_[head_];
        size_--;
        head_ = (head_ + 1)%capacity_;
        return value;
    }
}
CircularQueue::QueueItem CircularQueue::peek() const {
    if (empty()) {
        cout << "The queue is empty, can't peek" << endl;
        return EMPTY_QUEUE;
    }
    else
        return items_[head_];
}
void CircularQueue::print() const {
    if (empty())
        cout << "The queue is empty, can't print" << endl;
    else if (tail_ > head_) {
        for (int i = head_; i < tail_; i++)
            cout << items_[i] << " ";
    }
    else {
        for (int i = head_; i < capacity_; i++)
            cout << items_[i] << " ";
        for (int i = 0; i < tail_; i++)
            cout << items_[i] << " ";
    }
}