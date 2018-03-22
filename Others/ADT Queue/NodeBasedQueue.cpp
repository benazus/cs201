#include "NodeBasedQueue.h"
using namespace std;

NodeBasedQueue::NodeBasedQueue() {
	head = nullptr;
	tail = nullptr;
}

NodeBasedQueue::~NodeBasedQueue() {
	while (head != nullptr)
		this->dequeue();

	head = nullptr;
	tail = nullptr;
}

bool NodeBasedQueue::isEmpty() const {
	if (head == nullptr || tail == nullptr)
		return true;
	else
		return false;
}

bool NodeBasedQueue::enqueue(int item) {
	// 1 - Insert to an empty list
	// 2 - Insert to a non-empty list

	if (tail == nullptr) { // Empty queue
		Node* tmp = new Node;
		tmp->item = item;
		tail = tmp;
		head = tmp;
		tmp->next = nullptr;
		return true;
	}
	else { // Non-empty queue
		Node* tmp = new Node;
		tmp->item = item;
		tail->next = tmp;
		tail = tmp;
		tmp->next = nullptr;
		return true;
	}
	return false;
}

bool NodeBasedQueue::dequeue() {
	if (head == tail) { // A queue of size 1
		delete tail;
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else { // Size > 1
		Node* tmp = head->next;
		delete head;
		head = tmp;
		return true;
	}
	return false;
}

bool NodeBasedQueue::dequeue(int& front) {
	if (head == tail) { // A queue of size 1
		front = tail->item;
		delete tail;
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else { // Size > 1
		Node* tmp = head->next;
		front = head->item;
		delete head;
		head = tmp;
		return true;
	}
	return false;
}

bool NodeBasedQueue::getHead(int& headItem) const {
	if (isEmpty() == true)
		return false;
	else { // queue is not empty
		headItem = head->item;
		return true;
	}
}
