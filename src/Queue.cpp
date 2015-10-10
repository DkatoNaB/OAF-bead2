#include "Queue.h"

Queue::Queue() 
	: _queue(new Node())
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

void Queue::push(int) noexcept
{

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