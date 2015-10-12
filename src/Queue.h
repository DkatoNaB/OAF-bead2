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

	Queue(const Queue&);
	//Queue& operator=(const Queue&);

	bool inline empty() const noexcept { return _head->_next == nullptr; };
	void push(int) noexcept;
	void pop();	

	int& front();

	class Enumerator
	{
	public:
		Enumerator(Queue* queue) 
			: eQueue(queue)
			, current_element(nullptr)
		{
		}

		inline void first()			noexcept { current_element = eQueue-> _queue; }
		inline void next()			noexcept { current_element = current_element->_next; }
		inline bool end() const 	noexcept { return current_element == nullptr; }
		inline int current() const 	noexcept { return current_element->_value; }

	private:
		Queue *eQueue;
		Node *current_element;
	};

	Enumerator createEnumator() { return Enumerator(this); }

	friend std::ostream& operator<<(std::ostream&, Queue&);

private:
	//Node *_queue;
	Node *_head;
	Node *_queue;
	Node *_last;
};

#endif //__QUEUE_H__