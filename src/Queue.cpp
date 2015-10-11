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
		//Node *p = _queue;
		auto *p = _queue;
		_queue = p->_next;
		delete p;
	}
}

void Queue::push(int value) 
{

	//Node *p = new Node(value,nullptr);
	auto *p = new Node(value,nullptr);

	if(empty())
	{
		_queue = p;
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

	//Node *p = new Node(_queue->_value,_queue->_next);
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
const int& Queue::front() const 
{
	return _queue->_value;
}