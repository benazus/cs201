#include "ArrayBasedQueue.h"
using namespace std;

ArrayBasedQueue::ArrayBasedQueue() {
	head = 0;
	tail = max_size-1;
	itemCount = 0;
}

bool ArrayBasedQueue::isEmpty() const {
	if (itemCount == 0)
		return true;
	else
		return false;
}

bool ArrayBasedQueue::enqueue(int item) {
	if (itemCount == max_size)
		return false;
	else {
		tail = (tail + 1) % max_size;
		items[tail] = item;
		itemCount++;
		return true;
	}
	return false;
}

bool ArrayBasedQueue::dequeue() {
	if (isEmpty() == true)
		return false;
	else {
		head = (head + 1) % max_size;
		itemCount--;
		return true;
	}
	return false;
}

bool ArrayBasedQueue::dequeue(int& item) {
	if (isEmpty() == true) {
		item = -999999;
		return false;
	}
	else {
		item = items[head];
		head = (head + 1) % max_size;
		itemCount--;
		return true;
	}
	return false;
}

bool ArrayBasedQueue::getHead(int& headItem) const{
	if (isEmpty() == true)
		return false;

	else {
		headItem = items[head];
		return true;
	}
	return false;
}