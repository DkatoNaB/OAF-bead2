#include <iostream>
#include <stdexcept>
#include "Queue.h"

int main()
{
	Queue q;
	std::cout << "create q" << std::endl;
	std::cout << q;
	try
	{
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	std::cout << q << std::endl;
	std::cout << q << std::endl;
	std::cout << q << std::endl;
	} catch(std::runtime_error& ex)
	{
		std::cout << "push got rekt";
	}
	try
	{
		q.pop();
		q.pop();
		std::cout << q << std::endl;
	} catch (std::runtime_error& ex)
	{
		std::cout << "pop got rekt";
	}
	std::cout <<" Hello hello hello " <<std::endl;

	//Queue q2(q);
	return 0;
}