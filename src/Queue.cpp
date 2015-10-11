#include <iostream>
#include <stdexcept>
#include "Queue.h"

Queue::Queue() 
	: _queue(new Node())
	, _last(new Node())
{
}
	
Queue::~Queue()
{
	while( _queue != nullptr )
	{
		auto *p = _queue;
		_queue = p->_next;
		delete p;
	}
	_last = nullptr;
}

void Queue::push(int value) noexcept
{
	auto *p = new Node(value,nullptr);

	if(empty())
		_queue = p;
	else
		_last->_next = p;

	_last = p;
	
}
void Queue::pop()
{
	if(empty())	
		throw std::runtime_error("Queue::Pop()->empty()->true");

	auto *p = new Node(_queue->_value,_queue->_next);
	_queue = _queue->_next;
	delete p;
}

int& Queue::front()
{
	if(empty())	
		throw std::runtime_error("Queue::front()->empty()->true");

	return _queue->_value;
}

 std::ostream& operator<<(std::ostream& os, Queue& queue)
 {
 	if(queue.empty())
 		os << "queue is empty" << std::endl;
 	else
 	{
 		while( queue._queue != nullptr )
 		{
 			os << queue;
 			queue._queue = queue._queue->_next;
 		}
 	}
 	return os;
 }