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
		Node *p = _queue;
		_queue = p->_next;
		delete p;
	}
}

void Queue::push(int value) 
{

	Node *p = new Node(value,nullptr);
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

}
int& Queue::front()
{
	return _queue->_value;
}
const int& Queue::front() const 
{
	return _queue->_value;
}