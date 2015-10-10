#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

struct Node
{
	int _value;
	Node *_next;

	Node(int value = 0, Node *next = nullptr) : _value(value), _next(next) {}
};

class Queue
{
public:
	Queue();
	~Queue();

	bool inline empty() const noexcept { return _queue == nullptr; };
	void push(int);
	void pop();
	int& front();
	const int& front() const;

	//friend operator<<(std::ostream&, const Queue&);

private:
	Node *_queue;
	Node *_last;
};

#endif //__QUEUE_H__