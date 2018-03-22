#pragma once
class NodeBasedQueue {
public:
	NodeBasedQueue(); // Constructor, non-default
	~NodeBasedQueue(); // Destructor, non-default

    // Queue operations:
	bool isEmpty() const;
	// Determines whether the queue is empty.
	// Precondition: None.
	// Postcondition: Returns true if the queue 
	// is empty; otherwise returns false.

	bool enqueue(int newItem);
	// Inserts an item at the back of a queue.
	// Precondition: newItem is the item to be 
	// inserted.
	// Postcondition: If the insertion is 
	// successful, newItem is at the back of the 
	// queue.

	bool dequeue();
	// Dequeues the front of a queue.
	// Precondition: None.
	// Postcondition: If the queue is not empty, 
	// the item that was added to the queue 
	// earliest is deleted.

	bool dequeue(int& queueFront);
	// Retrieves and deletes the front of a queue
	// Precondition: None.
	// Postcondition: If the queue is not empty, 
	// queueFront contains the item that was 
	// added to the queue earliest, and the item 
	// is deleted.

	bool getHead(int& queueFront) const;
	// Retrieves the item at the front of a queue
	// Precondition: None.
	// Postcondition: If the queue is not empty, 
	// queueFront contains the item that was 
	// added to the queue earliest.

private:
	struct Node;
	Node* head;
	Node* tail;

	struct Node {
		int item;
		Node* next;
	};

};
