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
	explicit Queue();
	~Queue();

	Queue(const Queue&);
	Queue& operator=(const Queue&);

	bool inline empty() const noexcept { return _head->_next == nullptr; };
	void push(int) noexcept;
	void pop();	
	int& front();

	class Enumerator
	{
	public:
		Enumerator( Queue* queue) 
			: eQueue(queue)
			, current_element(nullptr)
		{
		}

		inline void first()			noexcept { current_element = eQueue-> _head->_next; }
		inline void next()			noexcept { current_element = current_element->_next; }
		inline bool end() const 	noexcept { return current_element == nullptr; }
		inline int current() const 	noexcept { return current_element->_value; }

	private:
		 Queue *eQueue;
		Node *current_element;
	};

	Enumerator createEnumator() { return Enumerator(this); }

	friend std::ostream& operator<<(std::ostream&,  Queue&);
	friend std::ostream& operator+(Queue&);

private:
	Node *_head;
	Node *_last;
};

#endif //__QUEUE_H__

/*
	A(1) 	->	 B(2)	 ->	 C(3)	 ->	 D(4)
	"head"								"last"
	q = 	new(a.val,a.next)	a.next = b
			new(b.val,b.next)	b.next = c
			new(c.val,c.next)	c.next = d
	last = 	new(d.val,d.next) 	d.next = nullptr

*/