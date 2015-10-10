#ifndef __QUEUE_H__
#define __QUEUE_H__

struct Node
{
	int _value;
	Node *_next;

	Node(int value = 0, Node *next = nullptr) : _value(value), _next(next) {}
};

class Queue
{
public:
	explicit Queue();
	~Queue();

	bool inline empty() const noexcept { return _queue == nullptr; };
	void push(int) noexcept;
	void pop();
	int& front();
	const int& front() const;

private:
	Node *_queue;
	//Node *_head;
};

#endif //__QUEUE_H__