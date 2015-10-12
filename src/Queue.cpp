#include <iostream>
#include <stdexcept>
#include "Queue.h"

Queue::Queue() 
	: _head(new Node())
	, _queue(new Node())
	, _last(new Node())
{
	_queue = _last;
}
	
Queue::~Queue()
{
		while( _head->_next != nullptr )
		{
			std::cout << "delete" << std::endl;
			auto *p = _head->_next;
			_head->_next = p->_next;
			delete p;
		}
		_last = nullptr;
}

Queue::Queue(const Queue& other)
{
	_queue = new Node(other._queue->_value, other._queue->_next);
	std::cout << "run bitch" << std::endl;
	while(_queue->_next != nullptr)
	{
		std::cout << "run bitch" << std::endl;
		_queue->_next = new Node(	  other._queue->_next->_value 
									, other._queue->_next->_next
								);
	}	
}

/*
	A(1) 	->	 B(2)	 ->	 C(3)	 ->	 D(4)
	"head"								"last"
	q = 	new(a.val,a.next)	a.next = b
			new(b.val,b.next)	b.next = c
			new(c.val,c.next)	c.next = d
	last = 	new(d.val,d.next) 	d.next = nullptr

*/

/*Queue& Queue::operator=(const Queue& other)
{
	if(this == &other)
		return *this;
	delete _queue;

	_last = other._last;
	while( other._queue != nullptr)
	{
		auto *p = new Node(other._queue);
		_queue = p->_next;
	}
	return *this;
}*/

void Queue::push(int value) noexcept
{
	auto *p = new Node(value,nullptr);

	if(_head->_next == nullptr)
	{
		_head->_next = _queue = p;
	}
	else
	{
		_last->_next = p;
	}

	_last = p;
}
void Queue::pop()
{
	if(empty())	
		throw std::runtime_error("Queue::Pop()->empty()->true");
	else
	{
		std::cout << "p->deleted?" << std::endl;
		auto *p = _head->_next;
		_head->_next = _head->_next->_next;
		delete p;
	}
}

int& Queue::front()
{
	if(empty())	
		throw std::runtime_error("Queue::front()->empty()->true");

	return _head->_next->_value;
}

 std::ostream& operator<<(std::ostream& os,  Queue& queue)
 {
 	if(queue.empty())
 	{
 		os << "queue is empty" << std::endl;
 		return os;
 	}
 	else
 	{
 		Queue::Enumerator it = queue.createEnumator();
 		for(it.first(); !it.end(); it.next())
 		{
 			os << it.current() << " " ;
 		}
 		os << std::endl;
 		return os;
 	}
 	
 }