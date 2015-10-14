#include <iostream>
#include <stdexcept>
#include "Queue.h"

Queue::Queue() 
	: _head(new Node())
	, _last(new Node())
{
}
	
Queue::~Queue()
{
		while( _head->_next != nullptr )
		{
			auto *p = _head->_next;
			_head->_next = p->_next;
			delete p;
		}
		_last = nullptr;
}

Queue::Queue(const Queue& other)
{
	_head = other._head;
	_last = other._last;
}

Queue& Queue::operator=(const Queue& other)
{
	if(this == &other)
		return *this;
	delete _head;

	_head = other._head;
	_last = other._last;

	return *this;
}

void Queue::push(int value) noexcept
{
	auto *p = new Node(value,nullptr);

	if(_head->_next == nullptr)
		_head->_next = p;
	else
		_last->_next = p;

	_last = p;
}
void Queue::pop()
{
	if(empty())	
		throw std::runtime_error("Queue::Pop()->empty()->true");
	else
	{
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
 			os << it.current() << " ";
 		
 		os << std::endl;
 		return os;
 	}
 	
 }